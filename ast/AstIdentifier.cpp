#include "AstIdentifier.h"

AstIdentifier* AstIdentifier::make(const string & id)
{
	AstIdentifier* i = new AstIdentifier(id);
	Expression* res = get_exp(i);
	assert(res->get_type() == AST_IDENTIFIER);
	return static_cast<AstIdentifier*>(res);
}

AstIdentifier::AstIdentifier(const string & id)
{
	this->et = AST_IDENTIFIER;
    this->id = id;
    this->hash_c = 7373 + id.size() + (id.size()>0? id[0]:0)+
    		(id.size()>1? id[1]:0) + (id.size()>2? id[2]:0);
}

string AstIdentifier::to_string(int d)
{
  return get_depth(d) + this->id + "\n";
}
string AstIdentifier::to_value()
{
  return this->id;
}

const string & AstIdentifier::get_id()
{
    return id;
}

Expression* AstIdentifier::substitute(Expression* e1, Expression* e2)
{
	if(e1 == this) return e2;
	return this;
}


bool AstIdentifier::operator==(const Expression& other)
{
	if(other.get_type() != AST_IDENTIFIER) return false;
	AstIdentifier& o = (AstIdentifier&) other;
	return id == o.id;


}

