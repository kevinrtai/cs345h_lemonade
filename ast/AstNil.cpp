#include "AstNil.h"

AstNil* AstNil::make()
{
	AstNil* ii = new AstNil();
	Expression* res = get_exp(ii);
	assert(res->get_type() == AST_NIL);
	return static_cast<AstNil*>(res);
}


AstNil::AstNil()
{
  this->et = AST_NIL;
  this->hash_c = 0;
}

string AstNil::to_string(int d)
{
    return get_depth(d) +"Nil\n";
}

string AstNil::to_value()
{
    return "Nil";
}




Expression* AstNil::substitute(Expression* e1, Expression* e2)
{
	if(this == e1) return e2;
	return this;
}

bool AstNil::operator==(const Expression& other)
{
	if(other.get_type() != AST_NIL) return false;
	return true;
}
