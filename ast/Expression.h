 #ifndef EXPRESSION_H_
 #define EXPRESSION_H_
 
 #include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <unordered_set>
#include <iostream>
 #include <assert.h>

 
 using namespace std; 
 class Expression;

 namespace std {



 template <>
 struct hash<Expression*> {
         size_t operator() (const Expression* const & x) const;
 };

 struct exp_eq
 {
   bool operator()(const Expression* l1, const Expression* l2) const;
 };

 }
 using namespace __gnu_cxx;

 enum expression_type {AST_BINOP,  AST_IDENTIFIER,
 AST_INT, AST_LAMBDA, AST_LET, AST_STRING, AST_IDENTIFIER_LIST,
 AST_EXPRESSION_LIST, AST_BRANCH, AST_NIL, AST_LIST, AST_UNOP, AST_READ};
 
 string get_depth(int d);
 string int_to_string(long i);
 long int string_to_int(const string & s);
  
 class Expression;
 
 class Expression
 {
    
   protected:
     expression_type et;
     size_t hash_c;
     static unordered_set<Expression*, hash<Expression*>, exp_eq> expressions;
     
     static Expression* get_exp(Expression* e);

      
   public:
      expression_type get_type() const;
      virtual string to_string(int depth = 0) = 0;
      virtual string to_value();
      virtual Expression* substitute(Expression* e1,
    		  Expression* e2) = 0;
      virtual bool operator==(const Expression& other) = 0;

      size_t get_hash() {return hash_c;};
     
 };
 
 #endif /* EXPRESSION_H_ */
