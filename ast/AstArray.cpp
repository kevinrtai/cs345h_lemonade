#include "AstArray.h"

AstArray* AstArray::make(vector<Expression*>& expr_vec)
{
    AstArray* array = new AstArray(expr_vec);
    Expression* res = get_exp(array);
    assert(res->get_type() == AST_ARRAY);
    return static_cast<AstArray*>(res);
}

AstArray* AstArray::make(Expression* e)
{
    AstArray* array = new AstArray(e);
    Expression* res = get_exp(array);
    assert(res->get_type() == AST_ARRAY);
    return static_cast<AstArray*>(res);
}

AstArray* AstArray::make()
{
    AstArray* array = new AstArray();
    Expression* res = get_exp(array);
    assert(res->get_type() == AST_ARRAY);
    return static_cast<AstArray*>(res);
}

AstArray::AstArray(Expression* e)
{
    vec.push_back(e);
    this->et = AST_ARRAY;
    compute_hash();
}

AstArray::AstArray(vector<Expression*>& exps)
{
    this->vec = exps;
    this->et = AST_ARRAY;
    compute_hash();
}

AstArray::AstArray()
{
    this->et = AST_ARRAY;
    compute_hash();
}

void AstArray::compute_hash()
{
    this->hash_c = 0;
    for (vector<Expression*>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        Expression* e = *it;
        this->hash_c += e->get_hash();
    }
    this->hash_c *= 9;
}

string AstArray::to_string(int d)
{
      string res =  get_depth(d) + "ARRAY\n";
      for(vector<Expression*>::iterator it = vec.begin(); it != vec.end(); it++)
      {
          res += (*it)->to_string(d+1);
      }
      return res;
}

string AstArray::to_value()
{
    string res = "[";
    for(vector<Expression*>::iterator it = vec.begin(); it != vec.end();)
    {
        res += (*it)->to_value();
        it++;
        if (it != vec.end()) res += ", ";
    }
    res += "]";
    return res;
}

const vector<Expression*>& AstArray::get_expressions()
{
    return vec;
}

Expression* AstArray::get(int index) {
    return vec.at(index);
}

int AstArray::size() {
    return vec.size();
}

AstArray* AstArray::append_exp(Expression* e)
{
    vector<Expression*> new_vec = vec;
    new_vec.push_back(e);
    return AstArray::make(new_vec);
}

Expression* AstArray::substitute(Expression* e1, Expression* e2)
{
    if(this == e1) return e2;
    vector<Expression*> new_vec;
    bool changed = false;
    for (vector<Expression*>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        Expression* e = *it;
        Expression* new_e = e->substitute(e1, e2);
        new_vec.push_back(new_e);
        if(e != new_e) changed = true;
    }
    if (!changed) return this;
    return AstArray::make(new_vec);
}


bool AstArray::operator==(const Expression& other)
{
    if (other.get_type() != AST_ARRAY) return false;
    AstArray& l = (AstArray&) other;
    return vec == l.vec;
}
