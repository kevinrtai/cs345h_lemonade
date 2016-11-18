#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include "ast/expression.h"
#include "Evaluator.h"


using namespace std;

int yylex();
int yyparse();
extern int yy_scan_string(const char* c);

void (*parser_error_fn)(string);
int curr_lineno;
Expression* res_expr;
std::set<string> libraries;

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

string readLib(string libName) {
    if (libraries.find(libName) != libraries.end()) {
        cout << "Are you boosted?";
        return "";
    }
    libraries.insert(libName);
    string buff = "";
    libName += ".cookie";
    ifstream file(libName.c_str());
    if (!file.is_open()) {
        cout << "Library \"" << libName << " cannot be opened." << endl;
        return "";
    }
    bool first = true;
    bool import = true;
    while (!file.eof()) {
        if (first) buff += "\n";
        first = false;
        string temp;
        std::getline(file, temp);
        std::istringstream iss(temp);
        string word;
        while (iss >> word && import) {
            if (word == "give-me") {
                temp.erase(0, word.length() + 1); // remove "give-me"
                iss >> word;
                string libContent = readLib(word);
                buff += libContent;
                temp.erase(0, word.length() + 1); // remove next word
                iss >> word; // skip "in"
                if (libContent == "") {
                    temp.erase(0, word.length() + 1); // remove next word
                }
            } else {
                import = false;
            }
        }
        buff += temp + " ";
    }
    return buff;
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
                temp.erase(0, word.length() + 1); // remove "give-me"
                iss >> word;
                string libContent = readLib(word);
                res += libContent;
                temp.erase(0, word.length() + 1); // remove next word
                iss >> word; // skip "in"
                if (libContent == "") {
                    temp.erase(0, word.length() + 1); // remove next word
                }
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
	    Evaluator e;
	    Expression* res = e.eval(res_expr);
	    cout << res->to_value()<< endl;
    }

}
