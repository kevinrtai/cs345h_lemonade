 #ifndef AST_IDENTIFIER_H_
 #define AST_IDENTIFIER_H_
 #include "Expression.h"
 
 class AstIdentifier: public Expression
 {
   private:
     string id;
     AstIdentifier(const string & id);
   public:
    static AstIdentifier* make(const string & id);
    virtual string to_string(int d = 0);
    virtual string to_value();
    const string & get_id();
	virtual Expression* substitute(Expression* e1,
	        		  Expression* e2);
	virtual bool operator==(const Expression& other);

    
 };
 
 
 
 #endif /* AST_IDENTIFIER_H_ */
