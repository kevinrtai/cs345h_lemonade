#ifndef AST_LAMBDA_H_
#define AST_LAMBDA_H_
 
#include "Expression.h"
#include "AstIdentifier.h"
#include "AstIdentifierList.h"
 
class AstLambda:public Expression
{
private:
  AstIdentifier* formal;
  Expression* body;
  AstLambda(AstIdentifier* formals, Expression* body);
public:
  static AstLambda* make(AstIdentifier* formal, Expression* body);
  static AstLambda* make(AstIdentifierList* formal, Expression* body);
  virtual string to_string(int d = 0);
  virtual string to_value();
  Expression* get_body();
  AstIdentifier* get_formal();
  virtual Expression* substitute(Expression* e1,
  	        		  Expression* e2);
  virtual bool operator==(const Expression& other);
  
  
};
 
 
#endif /* AST_LAMBDA_H_ */
