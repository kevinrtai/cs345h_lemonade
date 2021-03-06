#include "Evaluator.h"

#include "ast/expression.h"


/*
 * Call this function to report any run-time errors
 * This will abort execution.
 */
void report_error(Expression* e, const string & s)
{
	cout << "Run-time error in expression " << e->to_value() << endl;
	cout << s << endl;
	exit(1);
}

Evaluator::Evaluator(bool isLib, map<string, SymbolTable*>* maps)
{
	sym_tab = new SymbolTable();
    sym_tab->push();
    c = 0;
    this->isLib = isLib;
    lib_maps = maps;
}

Expression* Evaluator::eval_unop(AstUnOp* b)
{
	Expression* e = b->get_expression();
	Expression* eval_e = eval(e);

	if(b->get_unop_type() == PRINT) {
		if(eval_e->get_type() == AST_STRING) {
			AstString* s = static_cast<AstString*>(eval_e);
			cout << s->get_string() << endl;
		}
		else cout << eval_e->to_value() << endl;
		return AstInt::make(0);
	} else if (b->get_unop_type() == ISNIL) {
		if (eval_e->get_type() == AST_NIL) {
			return AstInt::make(1);
		} else {
			return AstInt::make(0);
		}
	} else if (b->get_unop_type() == HD) {
		if (eval_e->get_type() == AST_LIST) {
			AstList* lst = static_cast<AstList*>(eval_e);
			return lst->get_hd();
		} else {
			return eval_e;
		}
	} else if (b->get_unop_type() == TL) {
		if (eval_e->get_type() == AST_LIST) {
			AstList* lst = static_cast<AstList*>(eval_e);
			return lst->get_tl();
		} else {
			return AstNil::make();
		}
	} else if (b->get_unop_type() == LEN) {
        if (eval_e->get_type() == AST_ARRAY) {
            AstArray* array = static_cast<AstArray*>(eval_e);
            return AstInt::make(array->size());
        } else if (eval_e->get_type() == AST_STRING) {
            AstString* str = static_cast<AstString*>(eval_e);
            return AstInt::make(str->get_string().size());
        } else if (eval_e->get_type() == AST_DICT) {
            AstDict* dict = static_cast<AstDict*>(eval_e);
            return AstInt::make(dict->size());
        } else {
            report_error(e, "len can only be applied to arrays");
        }
    }

    //add code to deal with all the other unops
    assert(false);
}


Expression* Evaluator::eval_binop (AstBinOp* b) {
	Expression* first = eval(b->get_first());
	Expression* second = eval(b->get_second());

	if (first->get_type() == AST_INT && second->get_type() == AST_INT) {
		int val1 = static_cast<AstInt*>(first)->get_int();
		int val2 = static_cast<AstInt*>(second)->get_int();

		if (b->get_binop_type() == PLUS) {
			return AstInt::make(val1 + val2);
		} else if (b->get_binop_type() == MINUS) {
			return AstInt::make(val1 - val2);
		} else if (b->get_binop_type() == TIMES) {
			return AstInt::make(val1 * val2);
		} else if (b->get_binop_type() == DIVIDE) {
			return AstInt::make(val1 / val2);
		} else if (b->get_binop_type() == AND) {
			return AstInt::make(val1 && val2);
		} else if (b->get_binop_type() == OR) {
			return AstInt::make(val1 || val2);
		} else if (b->get_binop_type() == EQ) {
			return AstInt::make(val1 == val2);
		} else if (b->get_binop_type() == NEQ) {
			return AstInt::make(val1 != val2);
		} else if (b->get_binop_type() == LT) {
			return AstInt::make(val1 < val2);
		} else if (b->get_binop_type() == LEQ) {
			return AstInt::make(val1 <= val2);
		} else if (b->get_binop_type() == GT) {
			return AstInt::make(val1 > val2);
		} else if (b->get_binop_type() == GEQ) {
			return AstInt::make(val1 >= val2);
		} else if (b->get_binop_type() == CONS) {
            return AstList::make(first, second);
        }
	} else if (first->get_type() == AST_FLOAT && second->get_type() == AST_FLOAT) {
		double val1 = static_cast<AstFloat*>(first)->get_float();
		double val2 = static_cast<AstFloat*>(second)->get_float();

		if (b->get_binop_type() == PLUS) {
			return AstFloat::make(val1 + val2);
		} else if (b->get_binop_type() == MINUS) {
			return AstFloat::make(val1 - val2);
		} else if (b->get_binop_type() == TIMES) {
			return AstFloat::make(val1 * val2);
		} else if (b->get_binop_type() == DIVIDE) {
			return AstFloat::make(val1 / val2);
		} else if (b->get_binop_type() == EQ) {
			return AstFloat::make(val1 == val2);
		} else if (b->get_binop_type() == NEQ) {
			return AstInt::make(val1 != val2);
		} else if (b->get_binop_type() == LT) {
			return AstInt::make(val1 < val2);
		} else if (b->get_binop_type() == LEQ) {
			return AstInt::make(val1 <= val2);
		} else if (b->get_binop_type() == GT) {
			return AstInt::make(val1 > val2);
		} else if (b->get_binop_type() == GEQ) {
			return AstInt::make(val1 >= val2);
		} else if (b->get_binop_type() == CONS) {
            return AstList::make(first, second);
        } else {
        	string bt = AstBinOp::binop_type_to_string(b->get_binop_type());
        	report_error(b, "Binop " + bt + " cannot be applied to floats");
        }
    } else if (first->get_type() == AST_INT && second->get_type() == AST_FLOAT) {
    	int temp = static_cast<AstInt*>(first)->get_int();
    	double val1 = static_cast<double>(temp);
		double val2 = static_cast<AstFloat*>(second)->get_float();
		if (b->get_binop_type() == PLUS) {
			return AstFloat::make(val1 + val2);
		} else if (b->get_binop_type() == MINUS) {
			return AstFloat::make(val1 - val2);
		} else if (b->get_binop_type() == TIMES) {
			return AstFloat::make(val1 * val2);
		} else if (b->get_binop_type() == DIVIDE) {
			return AstFloat::make(val1 / val2);
		} else if (b->get_binop_type() == EQ) {
			return AstFloat::make(val1 == val2);
		} else if (b->get_binop_type() == NEQ) {
			return AstInt::make(val1 != val2);
		} else if (b->get_binop_type() == LT) {
			return AstInt::make(val1 < val2);
		} else if (b->get_binop_type() == LEQ) {
			return AstInt::make(val1 <= val2);
		} else if (b->get_binop_type() == GT) {
			return AstInt::make(val1 > val2);
		} else if (b->get_binop_type() == GEQ) {
			return AstInt::make(val1 >= val2);
		} else if (b->get_binop_type() == CONS) {
            return AstList::make(first, second);
        } else {
        	string bt = AstBinOp::binop_type_to_string(b->get_binop_type());
        	report_error(b, "Binop " + bt + " cannot be applied to floats");
        }
    } else if (first->get_type() == AST_FLOAT && second->get_type() == AST_INT) {
		double val1 = static_cast<AstFloat*>(first)->get_float();
		int temp = static_cast<AstInt*>(second)->get_int();
    	double val2 = static_cast<double>(temp);

		if (b->get_binop_type() == PLUS) {
			return AstFloat::make(val1 + val2);
		} else if (b->get_binop_type() == MINUS) {
			return AstFloat::make(val1 - val2);
		} else if (b->get_binop_type() == TIMES) {
			return AstFloat::make(val1 * val2);
		} else if (b->get_binop_type() == DIVIDE) {
			return AstFloat::make(val1 / val2);
		} else if (b->get_binop_type() == EQ) {
			return AstFloat::make(val1 == val2);
		} else if (b->get_binop_type() == NEQ) {
			return AstInt::make(val1 != val2);
		} else if (b->get_binop_type() == LT) {
			return AstInt::make(val1 < val2);
		} else if (b->get_binop_type() == LEQ) {
			return AstInt::make(val1 <= val2);
		} else if (b->get_binop_type() == GT) {
			return AstInt::make(val1 > val2);
		} else if (b->get_binop_type() == GEQ) {
			return AstInt::make(val1 >= val2);
		} else if (b->get_binop_type() == CONS) {
            return AstList::make(first, second);
        } else {
        	string bt = AstBinOp::binop_type_to_string(b->get_binop_type());
        	report_error(b, "Binop " + bt + " cannot be applied to floats");
        }
    } else if (first->get_type() == AST_ARRAY && b->get_binop_type() == PLUS) {
    	AstArray* arr = static_cast<AstArray*>(first);
    	if (second->get_type() == AST_ARRAY) {
    		// concatenate the two arrays
    		AstArray* secondArr = static_cast<AstArray*>(second);
    		vector<Expression*> secondVec = secondArr->get_expressions();
    		vector<Expression*> firstVec = arr->get_expressions();
    		firstVec.insert(firstVec.end(), secondVec.begin(), secondVec.end());
    		return AstArray::make(firstVec);
    	} else {
    		// append the expression onto the end of the array
    		vector<Expression*> firstVec = arr->get_expressions();
    		firstVec.push_back(second);
    		return AstArray::make(firstVec);
    	}
    } else if (first->get_type() == AST_DICT && b->get_binop_type() == PLUS) {
        AstDict* dict = static_cast<AstDict*>(first);
        if (second->get_type() != AST_LIST) {
            report_error(b, "Only a list tuple of key value can be appended to dict");
        }
        AstList* tuple = static_cast<AstList*>(second);
        Expression* hd = tuple->get_hd();
        Expression* tl = tuple->get_tl();
        if (hd->get_type() != AST_STRING) {
            report_error(b, "Dict key must be string");
        }
        AstString* astString = static_cast<AstString*>(hd);
        unordered_map<string, Expression*> m = dict->get_dict();
        m.insert(make_pair(astString->get_string(), tl));
        return AstDict::make(m);

    } else if (first->get_type() == AST_DICT && b->get_binop_type() == DEL) {
        AstDict* dict = static_cast<AstDict*>(first);
        if (second->get_type() != AST_STRING) {
            report_error(b, "Dict key must be string");
        }
        AstString* astString = static_cast<AstString*>(second);
        string str = astString->get_string();
        if (!dict->contains(str)) {
            report_error(b, "Dict key not present");
        }
        unordered_map<string, Expression*> m = dict->get_dict();
        m.erase(str);
        return AstDict::make(m);

	} else if (first->get_type() == AST_STRING && second->get_type() == AST_STRING) {
		string str1 = static_cast<AstString*>(first)->get_string();
		string str2 = static_cast<AstString*>(second)->get_string();

		if (b->get_binop_type() == PLUS) {
			return AstString::make(str1 + str2);
		} else if (b->get_binop_type() == EQ) {
			return AstInt::make(str1 == str2);
		} else if (b->get_binop_type() == NEQ) {
			return AstInt::make(str1 != str2);
		} else if (b->get_binop_type() == CONS) {
            return AstList::make(first, second);
		} else {
			string bt = AstBinOp::binop_type_to_string(b->get_binop_type());
			report_error(b, "Binop " + bt + " cannot be applied to strings");
		}

	} else if (first->get_type() == AST_LIST || second->get_type() == AST_LIST) {
		if(b->get_binop_type() != CONS) {
			report_error(b, "Binop @ is the only legal binop for lists");
		} else {
            return AstList::make(first, second);
        }

	} else if (b->get_binop_type() == CONS) {
		return AstList::make(first, second);

	} else {
		if (first->get_type() == AST_NIL || second->get_type() == AST_NIL) {
			report_error(b, "Nil can only be used with binop @");
		}
		report_error(b, "Binop can only be applied to expressions of same type");
        assert(false);
	}
}


Expression* Evaluator::eval(Expression* e)
{
	Expression* res_exp = NULL;
	switch(e->get_type())
	{
	case AST_READ:
	{
		AstRead* r = static_cast<AstRead*>(e);
		string input;
		getline(cin, input);
		if(r->read_integer()) {
			return AstInt::make(string_to_int(input));
		}
		return AstString::make(input);

		break;
	}
	case AST_BINOP:
	{
		AstBinOp* b = static_cast<AstBinOp*>(e);
		res_exp = eval_binop(b);
		break;
	}
	case AST_UNOP:
	{
		AstUnOp* b = static_cast<AstUnOp*>(e);
		res_exp = eval_unop(b);
		break;
	}
	case AST_BRANCH:
	{
		AstBranch* br = static_cast<AstBranch*>(e);
		Expression* turnip = eval(br->get_pred());
		if (turnip->get_type() != AST_INT) {
			report_error(e, "Predicate in conditional must be an integer");
		}

		int pred = static_cast<AstInt*>(turnip)->get_int();
		Expression* e1 = br->get_then_exp();
		Expression* e2 = br->get_else_exp();
		if (pred) {
			res_exp = eval(e1);
		} else {
			res_exp = eval(e2);
		}

		break;
	}
	case AST_EXPRESSION_LIST:
	{
		AstExpressionList* lst = static_cast<AstExpressionList*>(e);
		vector<Expression*> exps = lst->get_expressions();
        Expression* first = eval(exps[0]);
		if (first->get_type() == AST_ARRAY || first->get_type() == AST_DICT
                || first->get_type() == AST_STRING) {
			Expression* prev = first;
			vector<Expression*>::iterator it = exps.begin();
			it++;
			for (; it != exps.end(); it++) {
				if (!(prev->get_type() == AST_ARRAY
                        || prev->get_type() == AST_DICT
                        || prev->get_type() == AST_STRING)) {
					report_error(e, "can only index into array, string, or dict");
				}
                if (prev->get_type() == AST_ARRAY) {
                    AstArray* arr = static_cast<AstArray*>(prev);
                    Expression* currExp = *it;
                    Expression* evalExp = eval(currExp);
                    if (evalExp->get_type() != AST_INT) {
                        report_error(e, "array index must be integer");
                    }
                    AstInt* astInt = static_cast<AstInt*>(evalExp);
                    int index = astInt->get_int();
                    int len = arr->size();
                    if (index < 0 || index >= len) {
                        report_error(e, "array index out of bounds");
                    }
                    prev = arr->get(index);
                } else if (prev->get_type() == AST_DICT) {
                    AstDict* dict = static_cast<AstDict*>(prev);
                    Expression* currExp = *it;
                    Expression* evalExp = eval(currExp);
                    if (evalExp->get_type() != AST_STRING) {
                        report_error(e, "dict index must be string");
                    }
                    AstString* astString = static_cast<AstString*>(evalExp);
                    string str = astString->get_string();
                    if (!dict->contains(str)) {
                        report_error(e, "dict key not present");
                    }
                    prev = dict->get(str);
                } else if (prev->get_type() == AST_STRING) {
                    AstString* astString = static_cast<AstString*>(prev);
                    Expression* currExp = *it;
                    Expression* evalExp = eval(currExp);
                    if (evalExp->get_type() != AST_INT) {
                        report_error(e, "string index must be integer");
                    }
                    AstInt* astInt = static_cast<AstInt*>(evalExp);
                    unsigned int index = astInt->get_int();
                    string str = astString->get_string();
                    if (index < 0 || index >= str.size()) {
                        report_error(e, "string index out of bounds");
                    }
                    prev = AstString::make(str.substr(index, 1));
                }
			}
			res_exp = prev;
			break;

		} else if (first->get_type() != AST_LAMBDA) {
			report_error(e, "Only lambda expressions can be applied to other expressions");
		}
		if (exps.size() == 2) {
			AstLambda* lambda = static_cast<AstLambda*>(first);
            Expression* new_body = lambda->get_body()->substitute(lambda->get_formal(), exps[1]);
			res_exp = eval(new_body);
		} else {
			AstLambda* lambda = static_cast<AstLambda*>(first);
            Expression* new_body = lambda->get_body()->substitute(lambda->get_formal(), exps[1]);
			exps[0] = eval(new_body);
			exps.erase(exps.begin() + 1);
			res_exp = eval(AstExpressionList::make(exps));
		}
		break;
	}	
	case AST_LET:
	{
		AstLet* let = static_cast<AstLet*>(e);
		AstIdentifier* id = let->get_id();
		Expression* val = let->get_val();
		Expression* body = let->get_body();
		sym_tab->push();
		sym_tab->add(id, eval(val));
		res_exp = eval(body);
        if (!isLib) {
            sym_tab->pop();
        }
		break;
	}
	case AST_LIBCALL:
	{
		AstLibCall* libcall = static_cast<AstLibCall*>(e);
		string libName = libcall->get_lib();
		AstIdentifier* func = libcall->get_func();
		map<string, SymbolTable*>::iterator iter = lib_maps->find(libName);
		if (iter != lib_maps->end()) {
			SymbolTable* lib_tab = iter->second;
			res_exp = lib_tab->find(func);
			if (res_exp == NULL) {
  	            string id_str = func->to_string();
            	int len = id_str.length();
        	    id_str[len - 1] = '\0';
				report_error(e,"Identifier " + id_str + " not found in library " + libName);
			}
	    } else {
	    	report_error(e,"Library " + libName + " is not bound in current context");
	    }
		break;
	}
	case AST_IDENTIFIER:
	{
		AstIdentifier* id = static_cast<AstIdentifier*>(e);
		res_exp = sym_tab->find(id);
		if (res_exp == NULL) {
            string id_str = id->to_string();
            int len = id_str.length();
            id_str[len - 1] = '\0';
			report_error(e,"Identifier " + id_str + " is not bound in current context");
		}
		break;
	}
    case AST_LAMBDA:
    {
        res_exp = e;
        break;
    }
	case AST_NIL:
	{
		res_exp = e;
		break;
	}
	case AST_INT:
	{
		res_exp = e;
		break;
	}
	case AST_STRING:
	{
		res_exp = e;
		break;
	}
	case AST_LIST:
	{
		res_exp = e;
		break;
	}
	case AST_FLOAT:
	{
		res_exp = e;
		break;
	}
	case AST_ARRAY:
	{
		AstArray* arr = static_cast<AstArray*>(e);
		vector<Expression*> vec = arr->get_expressions();
		vector<Expression*> evalVec;
		for (vector<Expression*>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			evalVec.push_back(eval(*it));
		}
		res_exp = AstArray::make(evalVec);
		break;
	}
    case AST_DICT:
    {
        AstDict* dict = static_cast<AstDict*>(e);
        if (dict->raw()) {
            // convert dict to proper form
            vector<pair<Expression*, Expression*> > vec = dict->get_vec();
            unordered_map<string, Expression*> new_map;
            for (auto it : vec)
            {
                Expression* evaled_expr = eval(it.first);
                if (evaled_expr->get_type() != AST_STRING) {
                    report_error(e, "dicts must use strings as keys");
                }
                AstString* ast_str = static_cast<AstString*>(evaled_expr);
                new_map[ast_str->get_string()] = it.second;
            }
            dict = AstDict::make(new_map);
        }
        unordered_map<string, Expression*> eval_map;
        for (auto it : dict->get_dict())
        {
            eval_map[it.first] = eval(it.second);
        }
        res_exp = AstDict::make(eval_map);
        break;
    }
	//ADD CASES FOR ALL EXPRESSIONS!!
	default:
    {
        report_error(e, "unknown parse tree");
		assert(false);
    }

	}
	return res_exp;
}

SymbolTable* Evaluator::get_sym_tab()
{
    return sym_tab;
}
