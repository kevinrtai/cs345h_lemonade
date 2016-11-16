#ifndef ASTBRANCH_H_
#define ASTBRANCH_H_
#include "Expression.h"

class AstBranch:public Expression {
private:
	Expression* pred;
	Expression* then_exp;
	Expression* else_exp;
	AstBranch(Expression* pred, Expression* then_exp, Expression* else_exp);
public:
	static AstBranch* make(Expression* pred, Expression* then_exp,
			Expression* else_exp);
	virtual string to_string(int d = 0);
	virtual string to_value();
	Expression* get_pred();
	Expression* get_then_exp();
	Expression* get_else_exp();
	virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
	virtual bool operator==(const Expression& other);

};

#endif /* ASTBRANCH_H_ */
