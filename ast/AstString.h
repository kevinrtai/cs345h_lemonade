 #ifndef AST_STRING_H_
 #define AST_STRING_H_
 
 #include "Expression.h"
 
 class AstString: public Expression
 {
   private:
     string s;
     AstString(const string & s);
   public:
     static AstString* make(const string & s);
     virtual string to_string(int d = 0);
     virtual string to_value();
     const string & get_string();
     virtual Expression* substitute(Expression* e1,
     	        		  Expression* e2);
     virtual bool operator==(const Expression& other);
   
 };
 
 
 
 #endif /* AST_STRING_H_ */ 
