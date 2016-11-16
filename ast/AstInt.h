#ifndef ASTINT_H_
#define ASTINT_H_
#include "Expression.h"

class AstInt:public Expression
{
private:
  long int i;
  AstInt(long int i);
public:
  static AstInt* make(long int i);
  virtual string to_string(int d = 0);
  virtual string to_value();
  long int get_int();
  virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
  virtual bool operator==(const Expression& other);
};

#endif /* ASTINT_H_ */
