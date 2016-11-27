

#ifndef EVALUATOR_H_
#define EVALUATOR_H_
#include <string>
#include <stack>
class Expression;
class AstBinOp;
class AstUnOp;
class AstExpressionList;
#include "SymbolTable.h"

class Evaluator {
private:
	SymbolTable* sym_tab;
    bool isLib;
    map<string, SymbolTable*>* lib_maps;
	int c;
public:
    Evaluator(bool isLib, map<string, SymbolTable*>* maps);
	Expression* eval(Expression* e);
	Expression* eval_binop(AstBinOp* b);
	Expression* eval_unop(AstUnOp* b);
	Expression* eval_expression_list(AstExpressionList* l);
    SymbolTable* get_sym_tab();
};

#endif /* EVALUATOR_H_ */
