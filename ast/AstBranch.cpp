#include "AstBranch.h"

AstBranch* AstBranch::make(Expression* pred, Expression* then_exp,
		Expression* else_exp)
{
	AstBranch* t = new AstBranch(pred, then_exp, else_exp);
	Expression* res = get_exp(t);
	assert(res->get_type() == AST_BRANCH);
	return static_cast<AstBranch*>(res);
}


AstBranch::AstBranch(Expression* pred, Expression* then_exp, Expression* else_exp)
{
	this->et = AST_BRANCH;
	this->pred = pred;
	this->then_exp = then_exp;
	this->else_exp = else_exp;

	this->hash_c = 5* pred->get_hash() +2*then_exp->get_hash() +732*
			else_exp->get_hash();


}




string AstBranch::to_string(int d)
{
  string res =  get_depth(d) + "BRANCH""\n";
  res +=  get_depth(d) + "Predicate:\n";
  res += pred->to_string(d+1);
  res += get_depth(d) +  "Then branch:\n";
  res += then_exp->to_string(d+1);
  res += get_depth(d) +  "Else Branch:\n";
  res += else_exp->to_string(d+1);
  return res;
}

string AstBranch::to_value()
{
  return "(if " + pred->to_value() + " then " + then_exp->to_value() + " else "
   + else_exp->to_value() + ")";
}


Expression* AstBranch::AstBranch::get_pred()
{
	return pred;
}

Expression* AstBranch::AstBranch::get_then_exp()
{
	return then_exp;
}


Expression* AstBranch::AstBranch::get_else_exp()
{
	return else_exp;
}

Expression* AstBranch::substitute(Expression* e1,
        		  Expression* e2)
{
	if(e1 == this) return e2;
	Expression* new_pred = pred->substitute(e1, e2);
	Expression* new_then = then_exp->substitute(e1, e2);
	Expression* new_else = else_exp->substitute(e1, e2);
	if(pred == new_pred && then_exp == new_then && else_exp == new_else)
		return this;
	return AstBranch::make(new_pred, new_then, new_else);
}


bool AstBranch::operator==(const Expression& other)
{
	if(other.get_type() != AST_BRANCH) return false;
	AstBranch& b = (AstBranch&) other;
	return pred == b.pred && then_exp == b.then_exp && else_exp == b.else_exp;
}


