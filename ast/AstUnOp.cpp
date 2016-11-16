#include "AstUnOp.h"


AstUnOp* AstUnOp::make(unop_type bt, Expression* e)
{
	AstUnOp* t = new AstUnOp(bt, e);
	Expression* res = get_exp(t);
	assert(res->get_type() == AST_UNOP);
	return static_cast<AstUnOp*>(res);
}

AstUnOp::AstUnOp(unop_type bt, Expression* e)
{
	this->et = AST_UNOP;
	this->bt = bt;
	this->e = e;
	this->hash_c = 777*e->get_hash() +(int)bt*3;
}

string AstUnOp::to_string(int d)
{
  string res =  get_depth(d) + "UNOP: " + unop_type_to_string(bt)+ "\n";
  res += e->to_string(d+1);
  return res;
}

string AstUnOp::to_value()
{
	return "(" + unop_type_to_string(bt)+ e->to_value() + ")";

}


Expression* AstUnOp::get_expression()
{
  return e;
}


unop_type AstUnOp::get_unop_type()
{
  return bt;
}


Expression* AstUnOp::substitute(Expression* e1, Expression* e2)
{
	if(this == e1) return e2;
	Expression* new_e = this->e->substitute(e1, e2);
	if(this->e == new_e) return this;
	return  AstUnOp::make(bt, new_e);
}


bool AstUnOp::operator==(const Expression& other)
{
	if(other.get_type() != AST_UNOP) return false;
	AstUnOp& op = (AstUnOp&) other;
	return bt == op.bt && e == op.e;


}
