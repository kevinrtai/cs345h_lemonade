#include "AstLet.h"

AstLet* AstLet::make(AstIdentifier* id, Expression* val, Expression* body)
{
	AstLet* l = new AstLet(id, val, body);
	Expression* res = get_exp(l);
	assert(res->get_type() == AST_LET);
	return static_cast<AstLet*>(res);
}


AstLet::AstLet(AstIdentifier* id, Expression* val, Expression* body)
{
  this->et = AST_LET;
  this->id = id;
  this->val = val;
  this->body = body;
  this->hash_c = 1 + id->get_hash() + 6*val->get_hash() + 484*body->get_hash();
}

string AstLet::to_string(int d)
{
  string res =  get_depth(d) + "Let " + id->get_id() + "\n";
  res +=  get_depth(d) + "VAL\n";
  res +=  val->to_string(d+1);
  res +=  get_depth(d) + "BODY\n";
  res +=  body->to_string(d+1);
  return res;
}

string AstLet::to_value()
{
  return "let " + id->to_value() + " = " + val->to_value() + " in " + body->to_value();
}



AstIdentifier* AstLet::get_id()
{
    return id;
}

Expression* AstLet::get_val()
{
    return val;
}


Expression* AstLet::get_body()
{
    return body;
}

Expression* AstLet::substitute(Expression* e1, Expression* e2)
{
	//avoid capture of bound variable
	if(e1 == id) return this;
	Expression* _new_id = id->substitute(e1, e2);
	assert(_new_id->get_type() == AST_IDENTIFIER);
	AstIdentifier* new_id = static_cast<AstIdentifier*>(_new_id);
	Expression* new_val = val->substitute(e1, e2);
	Expression* new_body = body->substitute(e1, e2);
	return AstLet::make(new_id, new_val, new_body);
}

bool AstLet::operator==(const Expression& other)
{
	if(other.get_type() != AST_LET) return false;
	AstLet& l = (AstLet&) other;
	return id == l.id && val == l.val && body == l.body;
}
