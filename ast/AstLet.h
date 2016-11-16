#ifndef AST_LET_H_
#define AST_LET_H_

#include "Expression.h"
#include "AstIdentifier.h"

class AstLet:public Expression
{
  private:
    AstIdentifier* id;
    Expression* val;
    Expression* body;
    AstLet(AstIdentifier* id, Expression* val, Expression* body);
  public:
    static AstLet* make(AstIdentifier* id, Expression* val, Expression* body);
    virtual string to_string(int d = 0);
    virtual string to_value();
    AstIdentifier* get_id();
    Expression* get_body();
    Expression* get_val();
    virtual Expression* substitute(Expression* e1,
    	        		  Expression* e2);
    virtual bool operator==(const Expression& other);
    
    
};

#endif /* AST_LET_H_ */
