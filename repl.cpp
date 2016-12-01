#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int yylex();
int yyparse();
extern int yy_scan_string(const char* c);
string FILEPATH = "libs/";
#include "ast/expression.h"
#include "Evaluator.h"
map<string, SymbolTable*>* sym_tab_map = new map<string, SymbolTable*>();
set<string> libs;

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

string float_to_string(double f)
{
    stringstream s;
    s << f;
    return s.str();
}

double string_to_float(const string& s)
{
    return stof(s);
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
                // Recurse if dependency has not been processed.
                if (libs.find(word) == libs.end()) {
                    libs.insert(word);
                    map<string, SymbolTable*>::iterator it = sym_tab_map->begin();
                    sym_tab_map->insert(it, pair<string, SymbolTable*>(word, readLib(word)));
                }

         //       map<string, SymbolTable*>::iterator it = sym_tab_map->begin();
           //     sym_tab_map->insert(it, pair<string, SymbolTable*>(word, readLib(word)));
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



void parse_with_import(const string & s, void (*write_fn)(string)) {
    string res;
    bool first = true;
    bool import = true;
    std::istringstream prog_iss(s);
    //std::getline(iss, temp);
    while(prog_iss)
    {
        if(!first) res+="\n";
        first = false;
        string temp;
        std::getline(prog_iss, temp);
        std::istringstream iss(temp);
        string word;
        while (iss >> word && import) {
            if (word == "give-me") {
                iss >> word;
                // Recurse if dependency has not been processed.
                if (libs.find(word) == libs.end()) {
                    libs.insert(word);
                    map<string, SymbolTable*>::iterator it = sym_tab_map->begin();
                    sym_tab_map->insert(it, pair<string, SymbolTable*>(word, readLib(word)));
                }

             //   map<string, SymbolTable*>::iterator it = sym_tab_map->begin();
               // sym_tab_map->insert(it, pair<string, SymbolTable*>(word, readLib(word)));
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
}

int main(int argc, char** argv)
{
    bool print_ast = false;
  
    string res;
    bool first = true;
    bool import = true;

    while(true)
    {
        cout << ">> ";
        if(!first) res+="\n";
        first = false;
        string temp;
        // apparently getline behaves poorly with backspace
        std::getline(std::cin, temp);
        std::istringstream iss(temp);
        string word;
        iss >> word;
        if(word == "examine") {
            string temp_program;
            temp_program = res;
            while(iss >> word){
                temp_program += word;
                temp_program += " ";
            }
            parse_with_import(temp_program, report_error);
  
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
        else if(word == "clear") {
            res = "";
            sym_tab_map = new map<string, SymbolTable*>();
        } else {
            // Maybe try to eavluate and only add to res if it doesn't fail?
            // This would mean we wouldn't have to clear after errors.
            //res+=temp;
            string temp_copy = temp;
            string temp_prog = res;
            temp_prog += temp;
            if (word == "let" || word == "fun") {
                std::istringstream temp_iss(temp_copy);
                string temp_word;
                temp_iss >> temp_word;
                // assert word is let or fun
                temp_iss >> temp_word;
                // temp_word should now contain identifier name
                temp_prog += "\n";
                temp_prog += temp_word;
            }
            if (word != "give-me") {
                // Maybe this should be factored out?
                parse_with_import(temp_prog, report_error);
                if (res_expr != NULL) {
                    res += temp;
                }
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
            } else {
                res += temp;
            }
        }
    }
    
    return 0;
}
