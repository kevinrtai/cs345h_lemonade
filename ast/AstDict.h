#ifndef ASTDICT_H_
#define ASTDICT_H_
#include "Expression.h"
#include <unordered_map>

class AstDict:public Expression
{
private:
    unordered_map<string, Expression*> dict;
    vector< pair<Expression*, Expression*> > vec;
    AstDict(string str, Expression* expr);
    AstDict(unordered_map<string, Expression*>& d);
    AstDict(vector< pair<Expression*, Expression*> >& v);
    AstDict();
public:
    static AstDict* make(string str, Expression* expr);
    static AstDict* make(unordered_map<string, Expression*>& dict);
    static AstDict* make(vector<pair<Expression*, Expression*>>& vec);
    static AstDict* make();
    virtual string to_string(int d = 0);
    virtual string to_value();
    const unordered_map<string, Expression*>& get_dict();
    bool contains(const string& str);
    Expression* get(const string& str);
    int size();
    bool raw();
    const vector<pair<Expression*, Expression*> >& get_vec();
    virtual Expression* substitute(Expression* e1, Expression* e2);
    virtual bool operator==(const Expression& other);
private:
    void compute_hash();
};

#endif /*ASTDICT_H_ */
