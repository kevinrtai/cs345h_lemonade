#include "AstRead.h"


AstRead* AstRead::make(bool read_int)
{
	AstRead* t = new AstRead(read_int);
	Expression* res = get_exp(t);
	assert(res->get_type() == AST_READ);
	return static_cast<AstRead*>(res);
}

AstRead::AstRead(bool read_int)
{
	this->et = AST_READ;
	this->read_int = read_int;
	this->hash_c = 777+(read_int?1:0);
}

string AstRead::to_string(int d)
{
  string res =  get_depth(d) + "read" + (read_int? "Int": "String")+ "\n";
  return res;
}

string AstRead::to_value()
{
  return string("read") + (read_int? "Int": "String");
}



bool AstRead::read_integer()
{
  return read_int;
}




Expression* AstRead::substitute(Expression* e1, Expression* e2)
{
	if(this == e1) return e2;
	return this;
}


bool AstRead::operator==(const Expression& other)
{
	if(other.get_type() != AST_READ) return false;
	AstRead& op = (AstRead&) other;
	return read_int == op.read_int;


}
