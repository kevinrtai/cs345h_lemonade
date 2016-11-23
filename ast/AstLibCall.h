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
  Expression* body;
  AstLibCall(AstIdentifier* lib, AstIdentifier* func, Expression* body);
public:
  static AstLibCall* make(AstIdentifier* libName, AstIdentifier* formal, Expression* body);
  virtual string to_string(int d = 0);
  Expression* get_body();
  AstIdentifier* get_func();
  AstIdentifier* get_lib();
  virtual bool operator==(const Expression& other);
  
  
};
 
 
#endif /* AST_LIBCALL_H_ */