#ifndef ASTFLOAT_H_
#define ASTFLOAT_H_
#include "Expression.h"

class AstFloat:public Expression
{
private:
  double f;
  AstFloat(double f);
public:
  static AstFloat* make(double f);
  virtual string to_string(int d = 0);
  virtual string to_value();
  double get_float();
  virtual Expression* substitute(Expression* e1, Expression* e2);
  virtual bool operator==(const Expression& other);
};

#endif /* ASTFLOAT_H_ */