%{

/* Kevin Tai    krt752  kevin.r.tai@utexas.edu
 * Ziqiu Chen   zc3428  stevenchen@utexas.edu
 */

#include "parser-defs.h"

int yylex();
extern int yy_scan_string(const char* c);
int yyerror(const char* p)
{ 
  if(parser_error_fn != NULL) {
    parser_error_fn("At line " + int_to_string(curr_lineno) + ": " + string(p));
  }
  return 1;
};

/* Helper function that parses lambda expressions. */
Expression* parse_lambda(Expression* expr2, Expression* expr4) {
    if(expr2->get_type() == AST_IDENTIFIER_LIST) {
        AstIdentifierList* id_list = static_cast<AstIdentifierList*>(expr2);
        return AstLambda::make(id_list, expr4);
    } else if(expr2->get_type() == AST_IDENTIFIER) {
        AstIdentifier* id = static_cast<AstIdentifier*>(expr2);
        return AstLambda::make(id, expr4);
    } else {
        return 0;
    }
}

/* Helper function that parses let expression */
Expression* parse_let(Expression* expr2, Expression* expr4, Expression* expr6) {
    assert(expr2->get_type() == AST_IDENTIFIER);
    AstIdentifier* id = static_cast<AstIdentifier*>(expr2);
    return AstLet::make(id, expr4, expr6);
}

%}
/* BISON Declarations */
%token 
TOKEN_READSTRING 
TOKEN_READINT 
TOKEN_PRINT 
TOKEN_ISNIL
TOKEN_HD 
TOKEN_TL 
TOKEN_CONS 
TOKEN_NIL 
TOKEN_DOT 
TOKEN_WITH 
TOKEN_LET 
TOKEN_PLUS 
TOKEN_MINUS 
TOKEN_IDENTIFIER 
TOKEN_TIMES 
TOKEN_DIVIDE 
TOKEN_INT 
TOKEN_LPAREN 
TOKEN_RPAREN 
TOKEN_LBRACKET
TOKEN_RBRACKET
TOKEN_LCURLY
TOKEN_RCURLY
TOKEN_AND 
TOKEN_OR 
TOKEN_EQ 
TOKEN_NEQ 
TOKEN_GT 
TOKEN_GEQ 
TOKEN_LT 
TOKEN_LEQ 
TOKEN_IF 
TOKEN_THEN 
TOKEN_ELSE 
TOKEN_LAMBDA 
TOKEN_FUN 
TOKEN_COMMA 
TOKEN_STRING 
TOKEN_ERROR 
TOKEN_IN
TOKEN_FLOAT
TOKEN_LEN
TOKEN_DEL
TOKEN_COLON
TOKEN_LIBCALL;

%nonassoc EXPR
%nonassoc TOKEN_PRINT TOKEN_LEN
%left TOKEN_COLON TOKEN_DEL
%left TOKEN_EQ TOKEN_NEQ TOKEN_LT TOKEN_GT TOKEN_GEQ TOKEN_LEQ
%left TOKEN_AND TOKEN_OR
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_TIMES TOKEN_DIVIDE
%nonassoc TOKEN_ISNIL
%right TOKEN_CONS
%nonassoc TOKEN_HD TOKEN_TL

%%

program: expression
{
	res_expr = $$;
}

expression: TOKEN_INT 
{
  	string lexeme = GET_LEXEME($1);
  	long int val = string_to_int(lexeme);
  	Expression* e = AstInt::make(val);
  	$$ = e;
} 
| TOKEN_FLOAT
{
    string lexeme = GET_LEXEME($1);
    double val = string_to_float(lexeme);
    Expression* e = AstFloat::make(val);
    $$ = e;
}
| TOKEN_STRING 
{
	string lexeme = GET_LEXEME($1);
  	Expression* e = AstString::make(lexeme);
  	$$ = e;
}
| libcall
{
  $$ = $1;
}
| identifier
{
  	$$ = $1; 
}
| TOKEN_LET identifier TOKEN_EQ expression TOKEN_IN expression %prec EXPR
{
    $$ = parse_let($2, $4, $6);
}
| TOKEN_LAMBDA identifier_list TOKEN_DOT expression %prec EXPR
{
    Expression* lambda = parse_lambda($2, $4);
    if(lambda != 0) {
        $$ = lambda; 
    } else {
        string error = "Lexing error: ";
        yyerror(error.c_str());
        YYERROR;
    }
}
| TOKEN_FUN identifier TOKEN_WITH identifier_list TOKEN_EQ expression TOKEN_IN expression %prec EXPR
{
    Expression* lambda = parse_lambda($4, $6);
    if (lambda == 0) {
        string error = "Lexing error: ";
        yyerror(error.c_str());
        YYERROR;
    }
    $$ = parse_let($2, lambda, $8);
}
| TOKEN_IF expression TOKEN_THEN expression TOKEN_ELSE expression %prec EXPR
{
    $$ = AstBranch::make($2, $4, $6);
}
| TOKEN_NIL
{
    $$ = AstNil::make();
}
| TOKEN_READINT
{
    $$ = AstRead::make(true);
}
| TOKEN_READSTRING
{
    $$ = AstRead::make(false);
}
| TOKEN_PRINT expression
{
    $$ = AstUnOp::make(PRINT, $2);
}
| TOKEN_LEN expression
{
    $$ = AstUnOp::make(LEN, $2);
}
| expression TOKEN_DEL expression
{
    $$ = AstBinOp::make(DEL, $1, $3);
}
| expression TOKEN_EQ expression
{
	$$ = AstBinOp::make(EQ, $1, $3);
}
| expression TOKEN_NEQ expression
{
	$$ = AstBinOp::make(NEQ, $1, $3);
}
| expression TOKEN_LT expression
{
	$$ = AstBinOp::make(LT, $1, $3);
}
| expression TOKEN_GT expression
{
	$$ = AstBinOp::make(GT, $1, $3);
}
| expression TOKEN_GEQ expression
{
	$$ = AstBinOp::make(GEQ, $1, $3);
}
| expression TOKEN_LEQ expression
{
	$$ = AstBinOp::make(LEQ, $1, $3);
}
| expression TOKEN_OR expression
{
	$$ = AstBinOp::make(OR, $1, $3);
}
| expression TOKEN_AND expression
{
	$$ = AstBinOp::make(AND, $1, $3);
}
| expression TOKEN_PLUS expression 
{
	$$ = AstBinOp::make(PLUS, $1, $3);
}
| expression TOKEN_MINUS expression
{
    $$ = AstBinOp::make(MINUS, $1, $3);
}
| expression TOKEN_TIMES expression
{
    $$ = AstBinOp::make(TIMES, $1, $3);
}
| expression TOKEN_DIVIDE expression
{
    $$ = AstBinOp::make(DIVIDE, $1, $3);
}
| TOKEN_ISNIL expression
{
    $$ = AstUnOp::make(ISNIL, $2);
}
| expression TOKEN_CONS expression
{
    $$ = AstBinOp::make(CONS, $1, $3);
}
| TOKEN_HD expression
{
    $$ = AstUnOp::make(HD, $2);
}
| TOKEN_TL expression
{
    $$ = AstUnOp::make(TL, $2);
}
| TOKEN_LBRACKET TOKEN_RBRACKET
{
    $$ = AstArray::make();
}
| TOKEN_LPAREN expression_list TOKEN_RPAREN 
{
	$$ = $2;
}
| TOKEN_LBRACKET array_list TOKEN_RBRACKET
{
    $$ = $2;
}
| TOKEN_LCURLY dict_list TOKEN_RCURLY
{
    $$ = $2;
}
| TOKEN_ERROR 
{
   // do not change the error rule
   string lexeme = GET_LEXEME($1);
   string error = "Lexing error: ";
   if(lexeme != "") error += lexeme;
   yyerror(error.c_str());
   YYERROR;
}

libcall: TOKEN_IDENTIFIER TOKEN_DOT identifier 
{
  string lib = GET_LEXEME($1);
  AstIdentifier* func = static_cast<AstIdentifier*>($3);
  $$ = AstLibCall::make(lib, func);
}

identifier: TOKEN_IDENTIFIER
{
	string lexeme = GET_LEXEME($1);
  $$ = AstIdentifier::make(lexeme);
}

dict_list: expression TOKEN_COLON expression TOKEN_COMMA dict_list
{
    Expression* expr1 = $1;
    Expression* expr3 = $3;
    Expression* expr5 = $5;
    AstDict* ast_dict = static_cast<AstDict*>(expr5);
    vector<pair<Expression*, Expression*> > vec = ast_dict->get_vec();
    vec.insert(vec.begin(), make_pair(expr1, expr3));
    AstDict* new_dict = AstDict::make(vec);
    vector<pair<Expression*, Expression*> > final_vec = new_dict->get_vec();
    $$ = new_dict;
}
| expression TOKEN_COLON expression TOKEN_COMMA expression TOKEN_COLON expression
{
    // for nested dicts
    Expression* expr1 = $1;
    Expression* expr3 = $3;
    Expression* expr5 = $5;
    Expression* expr7 = $7;
    vector<pair<Expression*, Expression*> > vec;
    vec.push_back(make_pair(expr1, expr3));
    vec.push_back(make_pair(expr5, expr7));
    $$ = AstDict::make(vec);
}
| expression TOKEN_COLON expression
{
    Expression* expr1 = $1;
    Expression* expr3 = $3;
    vector<pair<Expression*, Expression*> > vec;
    vec.push_back(make_pair(expr1, expr3));
    $$ = AstDict::make(vec);
}

array_list: expression TOKEN_COMMA array_list
{
  Expression* expr1 = $1;
  Expression* expr2 = $3;
  AstArray* arr_list = static_cast<AstArray*>(expr2);
  vector<Expression*> vec = arr_list->get_expressions();
  vec.insert(vec.begin(), expr1);
  $$ = AstArray::make(vec);
}
| expression TOKEN_COMMA expression
{
  // for nested arrays
  Expression* expr1 = $1;
  Expression* expr2 = $3;
  vector<Expression*> vec;
  vec.push_back(expr1);
  vec.push_back(expr2);
  $$ = AstArray::make(vec);
}
| expression
{
  Expression* expr1 = $1;
  vector<Expression*> vec;
  vec.push_back(expr1);
  $$ = AstArray::make(vec);
}

expression_list: expression expression_list
{
	Expression* expr1 = $1;
    Expression* expr2 = $2;
    /* We have to handle the case where we have an expression list and just a single expression */
	 if (expr2->get_type() == AST_EXPRESSION_LIST) {
	     AstExpressionList* expr_list = static_cast<AstExpressionList*>(expr2);
         vector<Expression*> vec = expr_list->get_expressions();
         vec.insert(vec.begin(), expr1);
         $$ = AstExpressionList::make(vec);
     } else {
        AstExpressionList* expr_list = AstExpressionList::make(expr1);
        $$ = expr_list->append_exp(expr2);
     }
}
| expression expression
{
    Expression* expr1 = $1;
    Expression* expr2 = $2;
    AstExpressionList* expr_list = AstExpressionList::make(expr1);
    $$ = expr_list->append_exp(expr2);
}
| expression
{
	$$ = $1;
}

identifier_list: identifier TOKEN_COMMA identifier_list
{
    Expression* expr1 = $1;
    Expression* expr3 = $3;
    assert(expr1->get_type() == AST_IDENTIFIER);
    AstIdentifier* id1 = static_cast<AstIdentifier*>(expr1);
    /* We must handle the case where we have an identifier list and just a single identifier */
	if (expr3->get_type() == AST_IDENTIFIER_LIST) {
	    AstIdentifierList* expr_list = static_cast<AstIdentifierList*>(expr3);
        vector<AstIdentifier*> vec = expr_list->get_ids();
        vec.insert(vec.begin(), id1);
        $$ = AstIdentifierList::make(vec);
    } else if(expr3->get_type() == AST_IDENTIFIER) {
        AstIdentifier* id2 = static_cast<AstIdentifier*>(expr3);
        AstIdentifierList* expr_list = AstIdentifierList::make(id1);
        $$ = expr_list->append_id(id2);
    } else {
        string error = "Lexing error: ";
        yyerror(error.c_str());
        YYERROR; 
    }
}
| identifier
{
    $$ = $1;
}

