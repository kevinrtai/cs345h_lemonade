#include "AstDict.h"
#include "AstString.h"

AstDict* AstDict::make(string str, Expression* expr)
{
    AstDict* dict = new AstDict(str, expr);
    Expression* res = get_exp(dict);
    assert(res->get_type() == AST_DICT);
    return static_cast<AstDict*>(res);
}

AstDict* AstDict::make(unordered_map<string, Expression*>& in_map)
{
    AstDict* dict = new AstDict(in_map);
    Expression* res = get_exp(dict);
    assert(res->get_type() == AST_DICT);
    return static_cast<AstDict*>(res);
}

AstDict* AstDict::make(vector<pair<Expression*, Expression*> >& vec)
{
    // constructor used by the parser, with un-evaluated expressions
    AstDict* dict = new AstDict(vec);
    Expression* res = get_exp(dict);
    assert(res->get_type() == AST_DICT);
    return static_cast<AstDict*>(res);
}

AstDict* AstDict::make()
{
    AstDict* dict = new AstDict();
    Expression* res = get_exp(dict);
    assert(res->get_type() == AST_DICT);
    return static_cast<AstDict*>(res);
}

AstDict::AstDict(string str, Expression* expr)
{
    dict[str] = expr;
    this->et = AST_DICT;
    compute_hash();
}

AstDict::AstDict(unordered_map<string, Expression*>& in_map)
{
    this->dict = in_map;
    this->et = AST_DICT;
    compute_hash();
}

AstDict::AstDict(vector< pair<Expression*, Expression*> >& v)
{
    this->vec = v;
    this->et = AST_DICT;
    compute_hash();
}

AstDict::AstDict()
{
    this->et = AST_DICT;
    compute_hash();
}

void AstDict::compute_hash()
{
    this->hash_c = 0;
    for (auto it : dict)
    {
        Expression* e = it.second;
        this->hash_c += e->get_hash();
    }
    this->hash_c *= 9;
}

string AstDict::to_string(int d)
{
    string res = get_depth(d) + "DICT\n";
    for (auto it : dict)
    {
        AstString* temp = AstString::make(it.first);
        res += temp->to_string(d + 1);
        res += it.second->to_string(d + 1);
    }
    return res;
}

string AstDict::to_value()
{
    string res = "{";
    for (unordered_map<string, Expression*>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        res += it->first;
        res += ": ";
        res += it->second->to_value();
        if (it != dict.end()) res += ", ";
    }
    res += "}";
    return res;
}

const unordered_map<string, Expression*>& AstDict::get_dict()
{
    return dict;
}

Expression* AstDict::get(const string& str)
{
    return dict[str];
}

int AstDict::size()
{
    return dict.size();
}

bool AstDict::raw()
{
    // a dict is raw if it has not been evaluated and contains raw expressions
    return vec.size() > 0;
}

vector<pair<Expression*, Expression*> >& AstDict::get_vec()
{
    return vec;
}

bool AstDict::contains(const string& str)
{
    return dict.find(str) == dict.end();
}

Expression* AstDict::substitute(Expression* e1, Expression* e2)
{
    if (this == e1) return e2;
    unordered_map<string, Expression*> new_map;
    bool changed = false;
    for (auto it : dict)
    {
        Expression* e = it.second;
        Expression* new_e = e->substitute(e1, e2);
        new_map[it.first] = new_e;
        if (e != new_e) changed = true;
    }
    if (!changed) return this;
    return AstDict::make(new_map);
}

bool AstDict::operator==(const Expression& other)
{
    if (other.get_type() != AST_DICT) return false;
    AstDict& d = (AstDict&) other;
    return dict == d.dict;
}
