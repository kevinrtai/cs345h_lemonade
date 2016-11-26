#include <iostream>
#include <fstream>
#include <sstream>
#include "ast/expression.h"
#include "Evaluator.h"

using namespace std;

int yylex();
int yyparse();
string FILEPATH = "libs/";

extern int yy_scan_string(const char* c);
map<string, SymbolTable*>* sym_tab_map = new map<string, SymbolTable*>();

void (*parser_error_fn)(string);
int curr_lineno;
Expression* res_expr;


string int_to_string(long i)
{
  
  char temp[100];
  sprintf(temp, "%ld",  i);
  string res = temp;
  return res;
}

long int string_to_int(const string & s)
{
	stringstream ss;
	ss<< s;
	long int res;
	ss >> res;
	return res;
}


void parse(const string & s, void (*write_fn)(string))
{
	curr_lineno = 1;
	res_expr = NULL;
	parser_error_fn = write_fn;
	yy_scan_string(s.c_str());
	if(yyparse()!=0)
	{
		res_expr = NULL;
	}

}

void report_error(string c)
{
    cout << c << endl;
  
}

SymbolTable* readLib(string word) {
    string filename = word + ".cookie";
    ifstream file(FILEPATH + filename.c_str());
    if(!file.is_open()) {
        cout << "File \"" << filename << "\" cannot be opened." << endl;
        return NULL;
    }

    string res;
    bool first = true;
    bool import = true;

    while(!file.eof())
    {
        if(!first) res+="\n";
        first = false;
        string temp;
        std::getline(file, temp);
        std::istringstream iss(temp);
        string word;

        while (iss >> word && import) {
            if (word == "give-me") {
                iss >> word;
                map<string, SymbolTable*>::iterator it = sym_tab_map->begin();
                sym_tab_map->insert(it, pair<string, SymbolTable*>(word, readLib(word)));
                temp.erase(0, 8); // remove word
                temp.erase(0, word.length() + 1); // remove next word
                iss >> word; // skip "in"
                temp.erase(0, 2);
            } else {
                import = false;
            }
        }
        res+=temp;
    }

    parse(res, report_error);

    SymbolTable* table = NULL;

    if(res_expr != NULL) {
	    Evaluator* e = new Evaluator(true, sym_tab_map);
	    e->eval(res_expr);
        table = e->get_sym_tab();
    }
    return table;
}

int main(int argc, char** argv)
{
    if(argc <=1)
    {
        cout << "No filename given " << endl;
        return -1;
    }
  
    string filename;

    bool print_ast = false;
    if(argc == 2)
        filename = argv[1];
    else {
        filename = argv[2];
        string flags = argv[1];
        if(flags == "-ast") print_ast = true;
    }
    ifstream file(filename.c_str());
    if(!file.is_open()) {
        cout << "File \"" << filename << "\" cannot be opened." << endl;
        return -1;
    }
  
    string res;
    bool first = true;
    bool import = true;
    while(!file.eof())
    {
        if(!first) res+="\n";
        first = false;
        string temp;
        std::getline(file, temp);
        std::istringstream iss(temp);
        string word;
        while (iss >> word && import) {
            if (word == "give-me") {
                iss >> word;
                map<string, SymbolTable*>::iterator it = sym_tab_map->begin();
                sym_tab_map->insert(it, pair<string, SymbolTable*>(word, readLib(word)));
                temp.erase(0, 8); // remove word
                temp.erase(0, word.length() + 1); // remove next word
                iss >> word; // skip "in"
                temp.erase(0, 2);
            } else {
                import = false;
            }
        }
        res+=temp;
    }
    parse(res, report_error);
  
    if(print_ast && res_expr != NULL) {
	    cout << "****************** AST ******************" << endl;
	    cout << res_expr->to_string() << endl;
	    cout << "*****************************************" << endl;
    }

    if(res_expr != NULL) {
	    Evaluator* e = new Evaluator(false, sym_tab_map);
	    Expression* res = e->eval(res_expr);
	    cout << res->to_value()<< endl;
    }
}
