#include "AstExpressionList.h"


AstExpressionList* AstExpressionList::make(Expression* e)
{
	AstExpressionList* l = new AstExpressionList(e);
	Expression* res = get_exp(l);
	assert(res->get_type() == AST_EXPRESSION_LIST);
	return static_cast<AstExpressionList*>(res);
}

AstExpressionList* AstExpressionList::make(vector<Expression*> & expr)
{
	AstExpressionList* l = new AstExpressionList(expr);
	Expression* res = get_exp(l);
	assert(res->get_type() == AST_EXPRESSION_LIST);
	return static_cast<AstExpressionList*>(res);
}

AstExpressionList::AstExpressionList(Expression* e)
{
	exps.push_back(e);
	this->et = AST_EXPRESSION_LIST;

	compute_hash();

}


AstExpressionList::AstExpressionList(vector<Expression*> & exps)
{
	this->exps = exps;
	this->et = AST_EXPRESSION_LIST;
	compute_hash();


}

void AstExpressionList::compute_hash()
{
	this->hash_c = 0;
	for(vector<Expression*>::iterator it = exps.begin(); it != exps.end(); it++)
	{
		Expression* e = *it;
		this->hash_c += e->get_hash();

	}
	this->hash_c*=9;
}

string AstExpressionList::to_string(int d)
{
	  string res =  get_depth(d) + "EXP LIST\n";
	  for(vector<Expression*>::iterator it = exps.begin(); it != exps.end(); it++)
	  {
	      res += (*it)->to_string(d+1);
	  }
	  return res;
}

string AstExpressionList::to_value()
{
	string res = "(";
	for(vector<Expression*>::iterator it = exps.begin(); it != exps.end();)
	{
		res += (*it)->to_value();
		it++;
		if(it != exps.end()) res += " ";
	}
	res+= ")";
	return res;
}


const vector<Expression*> & AstExpressionList::get_expressions()
{
	return exps;
}


AstExpressionList* AstExpressionList::append_exp(Expression* e)
{
	vector<Expression*> new_exps = exps;
	new_exps.push_back(e);
	return AstExpressionList::make(new_exps);
}

Expression* AstExpressionList::substitute(Expression* e1,
	        		  Expression* e2)
{
	if(this == e1) return e2;
	vector<Expression*> new_exps;
	bool changed = false;
	for(vector<Expression*>::iterator it = exps.begin(); it != exps.end(); it++)
	{
		Expression* e = *it;
		Expression* new_e = e->substitute(e1, e2);
		new_exps.push_back(new_e);
		if(e != new_e) changed = true;
	}
	if(!changed) return this;
	return AstExpressionList::make(new_exps);

}


bool AstExpressionList::operator==(const Expression& other)
{
	if(other.get_type() != AST_EXPRESSION_LIST) return false;
	AstExpressionList& l = (AstExpressionList&) other;
	return exps == l.exps;
}
