#include "AstIdentifierList.h"


AstIdentifierList* AstIdentifierList::make(AstIdentifier* id)
{
	AstIdentifierList* l = new AstIdentifierList(id);
	Expression* res = get_exp(l);
	assert(res->get_type() == AST_IDENTIFIER_LIST);
	return static_cast<AstIdentifierList*>(res);
}

AstIdentifierList* AstIdentifierList::make()
{
	AstIdentifierList* l = new AstIdentifierList();
	Expression* res = get_exp(l);
	assert(res->get_type() == AST_IDENTIFIER_LIST);
	return static_cast<AstIdentifierList*>(res);
}

AstIdentifierList* AstIdentifierList::make(vector<AstIdentifier*> & ids)
{
	AstIdentifierList* l = new AstIdentifierList(ids);
	Expression* res = get_exp(l);
	assert(res->get_type() == AST_IDENTIFIER_LIST);
	return static_cast<AstIdentifierList*>(res);
}


AstIdentifierList::AstIdentifierList(AstIdentifier* id)
{
	ids.push_back(id);
	this->et = AST_IDENTIFIER_LIST;
	compute_hash();

}

AstIdentifierList::AstIdentifierList()
{
	this->et = AST_IDENTIFIER_LIST;
	compute_hash();
}



AstIdentifierList::AstIdentifierList(vector<AstIdentifier*> & ids)
{
	this->ids = ids;
	this->et = AST_IDENTIFIER_LIST;
	compute_hash();
}

string AstIdentifierList::to_string(int d)
{
	  string res =  get_depth(d) + "ID LIST\n";
	  for(vector<AstIdentifier*>::iterator it = ids.begin(); it != ids.end(); it++)
	  {
	      res += (*it)->to_string(d+1);
	  }
	  return res;
}

string AstIdentifierList::to_value()
{
	  string res;
	  for(vector<AstIdentifier*>::iterator it = ids.begin(); it != ids.end();)
	  {
	      res += (*it)->to_value();
	      it++;
	      if(it != ids.end()) res += ", ";
	  }
	  return res;
}


const vector<AstIdentifier*> & AstIdentifierList::get_ids()
{
	return ids;
}


AstIdentifierList* AstIdentifierList::append_id(AstIdentifier* id)
{
	vector<AstIdentifier*> new_ids = ids;
	new_ids.push_back(id);
	return AstIdentifierList::make(new_ids);
}

Expression* AstIdentifierList::substitute(Expression* e1, Expression* e2)
{


	vector<AstIdentifier*> new_ids;
	bool changed = false;
	for(vector<AstIdentifier*>::iterator it = ids.begin(); it!= ids.end(); it++)
	{
		AstIdentifier* id = *it;
		Expression* _new_id = id->substitute(e1, e2);
		assert(_new_id->get_type() == AST_IDENTIFIER);
		AstIdentifier* new_id = static_cast<AstIdentifier*>(_new_id);
		new_ids.push_back(new_id);
		if(id != new_id) changed = true;
	}
	if(!changed) return this;
	return AstIdentifierList::make(new_ids);
}

bool AstIdentifierList::operator==(const Expression& other)
{
	if(other.get_type() != AST_IDENTIFIER_LIST) return false;
	AstIdentifierList& l = (AstIdentifierList&) other;
	return ids == l.ids;


}

void AstIdentifierList::compute_hash()
{
	this->hash_c = 0;
	for(vector<AstIdentifier*>::iterator it = ids.begin(); it!= ids.end(); it++)
	{
		AstIdentifier* id = *it;
		hash_c += id->get_hash();
	}
	this->hash_c*=3;
}

