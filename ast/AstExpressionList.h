#ifndef ASTEXPRESSIONLIST_H_
#define ASTEXPRESSIONLIST_H_
#include "Expression.h"

class AstExpressionList;

class AstExpressionList:public Expression {
private:
	vector<Expression*> exps;
	AstExpressionList(Expression* e);
	AstExpressionList(vector<Expression*> & expr);
public:
	static AstExpressionList* make(Expression* e);
	static AstExpressionList* make(vector<Expression*> & expr);
	virtual string to_string(int d = 0);
	virtual string to_value();
	const vector<Expression*> & get_expressions();
	AstExpressionList* append_exp(Expression* e);
	virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
	virtual bool operator==(const Expression& other);
private:
	void compute_hash();
};

#endif /* ASTEXPRESSIONLIST_H_ */
