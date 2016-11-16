#ifndef ASTLIST_H_
#define ASTLIST_H_
#include "Expression.h"

class AstList:public Expression
{
private:
	Expression* hd;
	Expression* tl;
	AstList(Expression* hd, Expression* tl);
public:
  static Expression* make(Expression* hd, Expression* tl);
  Expression* get_hd();
  Expression* get_tl();
  virtual string to_string(int d = 0);
  virtual string to_value();
  virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
  virtual bool operator==(const Expression& other);
};

#endif /* ASTLIST_H_ */
