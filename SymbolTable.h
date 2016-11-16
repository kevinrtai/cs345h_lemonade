
#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

class Expression;
class AstIdentifier;
#include <vector>
#include <map>

using namespace std;



class SymbolTable {
private:
	vector<map<AstIdentifier*, Expression*> > values;
public:
	SymbolTable();
	void push();
	void pop();
	void add(AstIdentifier* id, Expression* e);
	Expression* find(AstIdentifier* id);
	void print_contents();

};

#endif /* SYMBOLTABLE_H_ */
