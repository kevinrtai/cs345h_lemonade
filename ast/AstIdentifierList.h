#ifndef ASTIDENTIFIERLIST_H_
#define ASTIDENTIFIERLIST_H_
#include "AstIdentifier.h"

class AstIdentifierList:public Expression {
private:
	vector<AstIdentifier*> ids;
	AstIdentifierList(AstIdentifier* id);
	AstIdentifierList();
	AstIdentifierList(vector<AstIdentifier*> & ids);
public:
	static AstIdentifierList* make(AstIdentifier* id);
	static AstIdentifierList* make();
	static AstIdentifierList* make(vector<AstIdentifier*> & ids);

	virtual string to_string(int d = 0);
	virtual string to_value();
	const vector<AstIdentifier*> & get_ids();
	AstIdentifierList* append_id(AstIdentifier* id);
	virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
	virtual bool operator==(const Expression& other);
	void compute_hash();
};

#endif /* ASTIDENTIFIERLIST_H_ */
