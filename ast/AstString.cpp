#include "AstString.h"

AstString* AstString::make(const string & s)
{
	AstString* ss = new AstString(s);
	Expression* res = get_exp(ss);
	assert(res->get_type() == AST_STRING);
	return static_cast<AstString*>(res);
}


AstString::AstString(const string & s)
{
  this->et = AST_STRING;
  this->s = s;
  this->hash_c = 494+s.size() + (s.size()>0? s[0]:0)+
  		(s.size()>1? s[1]:0) + (s.size()>2? s[2]:0);
}

string AstString::to_string(int d)
{
    return get_depth(d) + "STRING: \"" + this->s + "\"\n";
}

string AstString::to_value()
{
	return "\"" + this->s + "\"";
}

const string & AstString::get_string()
{
    return s;
} 

Expression* AstString::substitute(Expression* e1, Expression* e2)
{
	if(this == e1) return e2;
	return this;
}

bool AstString::operator==(const Expression& other)
{
	if(other.get_type() != AST_STRING) return false;
	AstString& o = (AstString&) other;
	return o.s == s;
}

