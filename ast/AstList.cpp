#include "AstList.h"

Expression* AstList::make(Expression* hd, Expression* tl)
{
	if(tl->get_type() == AST_NIL) return hd;
	AstList* ii = new AstList(hd, tl);
	Expression* res = get_exp(ii);
	assert(res->get_type() == AST_LIST);
	return static_cast<AstList*>(res);
}


AstList::AstList(Expression* hd, Expression* tl)
{
  this->et = AST_LIST;
  this->hd = hd;
  this->tl = tl;
  this->hash_c = hd->get_hash()*3+tl->get_hash()*13+543;
}

Expression* AstList::get_hd()
{
	return hd;
}

Expression* AstList::get_tl()
{
	return tl;
}

string AstList::to_string(int d)
{
    return get_depth(d) + "[" + hd->to_string() + ", " + tl->to_string() + "]";
}

string AstList::to_value()
{
	return "[" + hd->to_value() + ", " + tl->to_value() + "]";
}



Expression* AstList::substitute(Expression* e1, Expression* e2)
{
	if(this == e1) return e2;
	Expression* new_hd = hd->substitute(e1, e2);
	Expression* new_tl = tl->substitute(e1, e2);
	if(hd != new_hd || tl != new_tl)
		return AstList::make(new_hd, new_tl);
	return this;
}

bool AstList::operator==(const Expression& other)
{
	if(other.get_type() != AST_LIST) return false;

	AstList& other_l = (AstList&) other;
	return other_l.hd == hd && other_l.tl == tl;
}
