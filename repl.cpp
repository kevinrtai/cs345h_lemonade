#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int yylex();
int yyparse();
extern int yy_scan_string(const char* c);
#include "ast/expression.h"
#include "Evaluator.h"

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

string readLib(string libName) {
    string buff = "";
    libName += ".L";
    ifstream file(libName.c_str());
    if (!file.is_open()) {
        cout << "Library \"" << libName << " cannot be opened." << endl;
        return "";
    }
    bool first = true;
    while (!file.eof()) {
        if (first) buff += "\n";
        first = false;
        string temp;
        std::getline(file, temp);
        // cout << temp;
        buff += temp + " ";
    }
    return buff;
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
        // std::istringstream iss(temp);
        // string word;
        // while (iss >> word && import) {
        //     cout << word << endl;
        //     if (word == "give-me") {
        //         iss >> word;
        //         res += readLib(word);
        //         temp.erase(0, 8); // remove word
        //         temp.erase(0, word.length() + 1); // remove next word
        //         iss >> word; // skip "in"
        //     } else {
        //         import = false;
        //     }
        // }
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
            parse(temp_program, report_error);
  
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
        else if(word == "clear") {
            res = "";
        } else {
            // Maybe try to eavluate and only add to res if it doesn't fail?
            // This would mean we wouldn't have to clear after errors.
            res+=temp;
            string temp_copy = temp;
            string temp_prog = res;
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
            // Maybe this should be factored out?
            parse(temp_prog, report_error); 
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
    }
    
    return 0;
}
