 #ifndef AST_BINOP_H_
 #define AST_BINOP_H_
 #include "Expression.h"
 
 enum binop_type {PLUS, MINUS, TIMES, DIVIDE, AND, OR, EQ, NEQ, LT, LEQ,
	 GT, GEQ, CONS};
 

 class AstBinOp;

 class AstBinOp: public Expression
 {
   private:
     binop_type bt;
     Expression* e1;
     Expression* e2;
     AstBinOp(binop_type bt, Expression* e1, Expression* e2);
     
   public:

    static AstBinOp* make(binop_type bt, Expression* e1, Expression* e2);
    virtual string to_string(int d = 0);
    virtual string to_value();
    Expression* get_first();
    Expression* get_second();
    binop_type get_binop_type();
    
    virtual Expression* substitute(Expression* e1,
        		  Expression* e2);

    virtual bool operator==(const Expression& other);

    static string binop_type_to_string(binop_type bt)
    {
        switch (bt) {
          case PLUS: return "+";
          case MINUS: return "-";
          case TIMES: return "*";
          case DIVIDE: return "/";
          case AND: return "&";
          case OR: return "|";
          case EQ: return "=";
          case NEQ: return "<>";
          case LT: return "<";
          case LEQ: return "<=";
          case GT: return ">";
          case GEQ: return ">=";
          case CONS: return "@";
          default:
            assert(false);
        }
    }
    
 };
 
 
 #endif /* AST_BINOP_H_ */
