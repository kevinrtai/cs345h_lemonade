 #ifndef AST_READ_H_
 #define AST_READ_H_
 #include "Expression.h"
 
 


 class AstRead: public Expression
 {
   private:
	 bool read_int;
	 AstRead(bool read_int);
     
   public:

    static AstRead* make(bool read_int);
    virtual string to_string(int d = 0);
    virtual string to_value();
    bool read_integer();
    
    virtual Expression* substitute(Expression* e1,
        		  Expression* e2);

    virtual bool operator==(const Expression& other);

    

 };
 
 
 #endif /* AST_READ_H_ */
