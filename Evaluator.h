

#ifndef EVALUATOR_H_
#define EVALUATOR_H_

class Expression;
class AstBinOp;
class AstUnOp;
class AstExpressionList;
#include "SymbolTable.h"

class Evaluator {
private:
	SymbolTable sym_tab;
	int c;
public:
	Evaluator();
	Expression* eval(Expression* e);
	Expression* eval_binop(AstBinOp* b);
	Expression* eval_unop(AstUnOp* b);
	Expression* eval_expression_list(AstExpressionList* l);

};

#endif /* EVALUATOR_H_ */
