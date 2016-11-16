#include "SymbolTable.h"
#include "ast/expression.h"

SymbolTable::SymbolTable()
{


}


void SymbolTable::push()
{
	map<AstIdentifier*, Expression*> cur_map;
	values.push_back(cur_map);
}

Expression* SymbolTable::find(AstIdentifier* id)
{
	for(vector<map<AstIdentifier*, Expression*> >::reverse_iterator it =
			values.rbegin(); it != values.rend(); it++)
	{
		map<AstIdentifier*, Expression*> & cur = *it;
		if(cur.count(id) > 0) return cur[id];
	}
	return NULL;
}

void SymbolTable::pop()
{
	if(values.size() == 0)
	{
		cout << "You can only pop from a symbol table that you have pushed on first"
				<< endl;
		assert(false);
	}
	values.pop_back();
}

void SymbolTable::add(AstIdentifier* id, Expression* e)
{
	if(values.size() == 0)
	{
		cout << "You can only add to a symbol table that you have pushed on first"
				<< endl;
		assert(false);
	}
	values[values.size()-1][id] = e;
}

void SymbolTable::print_contents()
{
	cout << "******** Symbol Table ******** " << endl;
	int i = 0;
	for(vector<map<AstIdentifier*, Expression*> >::iterator it = values.begin();
				it != values.end(); it++, i++)
	{
		cout << "Bindings at level " << i <<  ":" << endl;
		map<AstIdentifier*, Expression*> & cur = *it;
		for(map<AstIdentifier*, Expression*>::iterator it2 = cur.begin();
				it2 != cur.end(); it2++) {
			cout << "\t" << it2->first->to_string(1) << "   -> " <<
					it2->second->to_string(1) << endl;
		}

	}
	cout << "******** ********* ******** " << endl;
}
