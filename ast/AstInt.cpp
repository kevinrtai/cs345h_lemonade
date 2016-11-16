#include "AstInt.h"

AstInt* AstInt::make(long int i)
{
	AstInt* ii = new AstInt(i);
	Expression* res = get_exp(ii);
	assert(res->get_type() == AST_INT);
	return static_cast<AstInt*>(res);
}


AstInt::AstInt(long int i)
{
  this->et = AST_INT;
  this->i = i;
  this->hash_c = i;
}

string AstInt::to_string(int d)
{
    return get_depth(d) + "INT: " + int_to_string(this->i) + "\n";
}

string AstInt::to_value()
{
	return int_to_string(this->i);
}

long int AstInt::get_int()
{
    return i;
}

Expression* AstInt::substitute(Expression* e1, Expression* e2)
{
	if(this == e1) return e2;
	return this;
}

bool AstInt::operator==(const Expression& other)
{
	if(other.get_type() != AST_INT) return false;
	AstInt& l = (AstInt&) other;
	return l.i == i;
}
