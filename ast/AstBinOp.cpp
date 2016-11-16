#include "AstBinOp.h"


AstBinOp* AstBinOp::make(binop_type bt, Expression* e1, Expression* e2)
{
	AstBinOp* t = new AstBinOp(bt, e1, e2);
	Expression* res = get_exp(t);
	assert(res->get_type() == AST_BINOP);
	return static_cast<AstBinOp*>(res);
}

AstBinOp::AstBinOp(binop_type bt, Expression* e1, Expression* e2)
{
	this->et = AST_BINOP;
	this->bt = bt;
	this->e1 = e1;
	this->e2 = e2;
	this->hash_c = 3*e1->get_hash() + 17*e2->get_hash()+(int)bt;
}

string AstBinOp::to_string(int d)
{
  string res =  get_depth(d) + "BINOP: " + binop_type_to_string(bt)+ "\n";
  res += e1->to_string(d+1);
  res += e2->to_string(d+1);
  return res;
}

string AstBinOp::to_value()
{
  return "(" + e1->to_value() + " " + binop_type_to_string(bt)+ " " +
		  e2->to_value() + ")";
}




Expression* AstBinOp::get_first()
{
  return e1;
}


Expression* AstBinOp::get_second()
{
  return e2;
}

binop_type AstBinOp::get_binop_type()
{
  return bt;
}


Expression* AstBinOp::substitute(Expression* e1, Expression* e2)
{
	if(this == e1) return e2;
	Expression* new_e1 = this->e1->substitute(e1, e2);
	Expression* new_e2 = this->e2->substitute(e1, e2);
	if(this->e1 == new_e1 && this->e2 == new_e2) return this;
	return  AstBinOp::make(bt, new_e1, new_e2);
}


bool AstBinOp::operator==(const Expression& other)
{
	if(other.get_type() != AST_BINOP) return false;
	AstBinOp& op = (AstBinOp&) other;
	return bt == op.bt && e1 == op.e1 && e2 == op.e2;


}
