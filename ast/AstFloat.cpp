#include "AstFloat.h"

AstFloat* AstFloat::make(double f)
{
    AstFloat* ff = new AstFloat(f);
    Expression* res = get_exp(ff);
    assert(res->get_type() == AST_FLOAT);
    return static_cast<AstFloat*>(res);
}


AstFloat::AstFloat(double f)
{
    this->et = AST_FLOAT;
    this->f = f;
    // not a great hash code generator for now
    this->hash_c = static_cast<int>(f);
}

string AstFloat::to_string(int depth)
{
    return get_depth(depth) + "FLOAT: " + float_to_string(this->f) + "\n";
}

string AstFloat::to_value()
{
    return float_to_string(this->f);
}

double AstFloat::get_float()
{
    return f;
}

Expression* AstFloat::substitute(Expression* e1, Expression* e2)
{
    if (this == e1) return e2;
    return this;
}

bool AstFloat::operator==(const Expression& other)
{
    if (other.get_type() != AST_FLOAT) return false;
    AstFloat& otherFloat = (AstFloat&) other;
    return f == otherFloat.f;
}