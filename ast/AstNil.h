#ifndef ASTNIL_H_
#define ASTNIL_H_
#include "Expression.h"

class AstNil:public Expression
{
private:
  AstNil();
public:
  static AstNil* make();
  virtual string to_string(int d = 0);
  virtual string to_value();
  virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
  virtual bool operator==(const Expression& other);
};

#endif /* ASTNIL_H_ */
