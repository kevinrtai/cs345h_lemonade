#ifndef ASTARRAY_H_
#define ASTARRAY_H_
#include "Expression.h"

class AstArray:public Expression
{
private:
    vector<Expression*> vec;
    AstArray(Expression* expr);
    AstArray(vector<Expression*>& expr);
public:
    static AstArray* make(Expression* e);
    static AstArray* make(vector<Expression*>& expr_vec);
    virtual string to_string(int d = 0);
    virtual string to_value();
    const vector<Expression*>& get_expressions();
    Expression* get(int index);
    int size();
    AstArray* append_exp(Expression* e);
    virtual Expression* substitute(Expression* e1, Expression* e2);
    virtual bool operator==(const Expression& other);
private:
    void compute_hash();
};

#endif /* ASTARRAY_H_ */