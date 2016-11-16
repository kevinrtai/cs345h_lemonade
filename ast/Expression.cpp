#include "Expression.h"

unordered_set<Expression*, hash<Expression*>, exp_eq> Expression::expressions;






namespace std {
	size_t hash<Expression*>::operator() (const Expression* const & x) const {
		Expression*& xx = (Expression*&)x;
			return xx->get_hash();
	}

	  bool exp_eq::operator()(const Expression* l1, const Expression* l2) const
	  {

	    bool res =  *(Expression*)l1==*(Expression*)l2;
	    return res;
	  }

}









string get_depth(int d)
{
 string res = "";
 for(int i=0; i < d; i++)
   res+="\t";
 return res;
}
  


expression_type Expression::get_type() const
{
    return et; 
}   


string Expression::to_value()
{
	return to_string();
}

Expression* Expression::get_exp(Expression* e)
{
	unordered_set<Expression*, hash<Expression*>, exp_eq>::iterator it =
			expressions.find(e);

	if(it == expressions.end()){
		expressions.insert(e);
		return e;
	}
	delete e;
	return *it;
}

