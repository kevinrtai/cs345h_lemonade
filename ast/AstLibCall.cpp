#include "AstLibCall.h"

AstLibCall::AstLibCall(AstIdentifier* libName, AstIdentifier* func)
{
	this->et = AST_LIBCALL;
    this->libName = libName;
    this->func = func;
    this->hash_c = 997 + libName->to_string().size() + func->to_string().size();
}

AstLibCall* AstLibCall::make(AstIdentifier* libName, AstIdentifier* func)
{
	AstLibCall* lc = new AstLibCall(libName, func);
	Expression* res = get_exp(lc);
	assert(res->get_type() == AST_LIBCALL);
	return static_cast<AstLibCall*>(res);
}

string AstLibCall::to_string(int d)
{
    return get_depth(d) + this->libName->to_string() + "." + this->func->to_string() + "\n";
}

AstIdentifier* AstLibCall::get_func()
{
    return this->func;
}

AstIdentifier* AstLibCall::get_lib()
{
    return this->libName;
}

Expression* AstLibCall::substitute(Expression* e1, Expression* e2)
{
	if(e1 == this) return e2;
	return this;
}

bool AstLibCall::operator==(const Expression& other)
{
	if(other.get_type() != AST_LIBCALL) return false;
	AstLibCall& o = (AstLibCall&) other;
	return libName == o.libName && func == o.func;
}

