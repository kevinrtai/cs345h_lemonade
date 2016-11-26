#ifndef AST_LIBCALL_H_
#define AST_LIBCALL_H_
 
#include "Expression.h"
#include "AstIdentifier.h"
#include "AstIdentifierList.h"
 
class AstLibCall:public Expression
{
private:
  AstIdentifier* libName;
  AstIdentifier* func;
  AstLibCall(AstIdentifier* lib, AstIdentifier* func);
public:
  static AstLibCall* make(AstIdentifier* libName, AstIdentifier* formal);
  virtual string to_string(int d = 0);
  AstIdentifier* get_func();
  AstIdentifier* get_lib();
  virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
  virtual bool operator==(const Expression& other);
};
 
 
#endif /* AST_LIBCALL_H_ */
