#include "AstLambda.h"


AstLambda* AstLambda::make(AstIdentifierList* formal, Expression* body)
{
	Expression* res = body;
	assert(formal->get_ids().size() > 0);
	for(vector<AstIdentifier*>::const_reverse_iterator it =
			formal->get_ids().rbegin(); it != formal->get_ids().rend();it++)
	{
		AstIdentifier* id = *it;
		res = AstLambda::make(id, res);
	}

	assert(res->get_type() == AST_LAMBDA);
	return static_cast<AstLambda*>(res);

}


AstLambda* AstLambda::make(AstIdentifier* formal, Expression* body)
{
	AstLambda* l = new AstLambda(formal, body);
	Expression* res = get_exp(l);
	assert(res->get_type() == AST_LAMBDA);
	return static_cast<AstLambda*>(res);
}


AstLambda::AstLambda(AstIdentifier* formal, Expression* body)
{
  this->et = AST_LAMBDA;
  this->formal = formal;
  this->body = body;
  this->hash_c = 73+ formal->get_hash()*9 + body->get_hash()*3;
}


string AstLambda::to_string(int d)
{
  string res =  get_depth(d) + "Lambda\n";
  res +=  get_depth(d) + "Formal:\n";
  res += formal->to_string(d+1);
  res += get_depth(d) +  "Body:\n";
  res += body->to_string(d+1);
  return res;
}
string AstLambda::to_value()
{
 return "lambda " + formal->to_value() + ". " + body->to_value();
}


Expression* AstLambda::get_body()
{
  return body;
}



AstIdentifier* AstLambda::get_formal()
{
  return formal;
}


Expression* AstLambda::substitute(Expression* e1, Expression* e2)
{
	//avoid \alpha capture
	if(e1 == formal) return this;
	Expression* _new_f = formal->substitute(e1, e2);
	assert(_new_f->get_type() == AST_IDENTIFIER);
	AstIdentifier* new_f = static_cast<AstIdentifier*>(_new_f);
	Expression* new_body = body->substitute(e1, e2);
	return AstLambda::make(new_f, new_body);

}

bool AstLambda::operator==(const Expression& other)
{
	if(other.get_type() != AST_LAMBDA) return false;
	AstLambda& l = (AstLambda&) other;
	return formal == l.formal && body == l.body;
}

