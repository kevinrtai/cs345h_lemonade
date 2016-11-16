 #ifndef PARSER_DEFS_H_
 #define PARSER_DEFS_H_
 #include <iostream>


 #include <string>
 using namespace std;
 
#include "ast/expression.h"


#define YYSTYPE Expression*
 
 extern YYSTYPE yylval;
 
 #define YYINITDEPTH 100000
 

 #define SET_LEXEME(x) {yylval = AstString::make(x);}

 #define GET_LEXEME(x) ({assert(x->get_type() == AST_STRING); \
                        static_cast<AstString*>(x)->get_string();})

 
 

 extern int curr_lineno;
 extern void (*parser_error_fn)(string);
 
 extern Expression* res_expr;

 



 #endif
