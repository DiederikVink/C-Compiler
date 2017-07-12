%code requires {
	#include <iostream>
	#include <cstdlib>
	#include <string>
	#include <map>
	#include <vector>
	#include <sstream>
	#include <fstream> 
	#include <algorithm>
	int yylex();
	int yyerror(const char* s);
	


	}
	
%code {
		#include "src/c_parser.h"	
		#define TOTAL 17
		#define REG1 "t0"
		#define REG2 "t1"
		#define REG3 "t2"
		#define AREG "t3"
		#define CREG "t4"
		Root* base;
		int debug = 0;
		int codegen = 1;
		int offset = 0;
		int glbl_scope = 0;
		int param_num = 0;
		int arg_count = 0;
		int max_arg_size = 0;
		int current_arg_size = 1;
		int glbl_while_count = 0;
		int glbl_do_while_count = 0;
		int glbl_for_count = 0;
		int glbl_select_count = 0;
		int array_count = 0;
		int break_count = 0;
		int extern_decl = 0;
		int case_count = 0;
		int case_body = 0;

		std::map<Tag, int> offset_mapping;
		std::map<std::string, std::vector<Tag> > tag_mapping;
		std::map<std::string, int> func_mapping;	
		std::map<Tag, int> array_offset_mapping;
		std::map<Tag, int> pointer_mapping;

		std::vector<std::string> param_tag;
		std::vector<int> break_vec;

		std::stringstream tunit;
		std::stringstream header;
		std::stringstream fpsetup;
		std::stringstream argsetup;
		std::stringstream genout;
		std::stringstream fprestore;
		std::stringstream footer;
		std::stringstream array_data;

		std::ofstream ofile("test/test.s");	
		int current = 8;
		

		std::string setOffset()
		{
			std::stringstream tag_name;
			tag_name << "T_" << offset;
			offset_mapping[tag_name.str()] = offset;	
			offset += 4;
			return tag_name.str();
		}

		void arithmetic_ass(std::string instr, AssignExpr* assignexpr, Unary* unary, std::string tag)
		{
			int type;
			std::string rhs_tag = "";
			std::string lhs_tag = "";
			unary->get_type(type);
			assignexpr->get_tag(rhs_tag);
			unary->get_tag(lhs_tag);
			
			// if its an array
			if ((type == 1) || (type ==2))
			{
				genout << "\tlw" << "\t$" << REG3 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				genout << "\tlw" << "\t$" << REG1 << "," << 0 << "($" << REG3 << ")" << std::endl;
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
				genout << "\t" << instr << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				if ((instr == "mul") || (instr == "div") || (instr == "rem"))
				{
					genout << "\tnop" << std::endl;
					genout << "\tnop" << std::endl;
				}
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << 0 << "($" << REG3 << ")" << std::endl;
			}
			else
			{
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
				genout << "\t" << instr << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				if ((instr == "mul") || (instr == "div") || (instr == "rem"))
				{
					genout << "\tnop" << std::endl;
					genout << "\tnop" << std::endl;
				}
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
		}

		void arithmetic_expr(std::string instr, std::string tag_lhs, std::string tag_rhs, std::string tag)
		{
			genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
			genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
			genout << "\t" << instr << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
			genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
		}





		Tree::Tree(int inp) {
			tag = setOffset();
		}
		Tree::~Tree() {}	

		Root::Root(File *f) : file(f) {}
		void Root::print()
		{
			if (file != NULL) file->print();
			//current_arg_size = 0;
		}
		void Root::cgen()
		{
			tunit << "\t.text\n";
			if (file != NULL) file->cgen();	
		}
		
		File::File(ExternDecl *ed, File *f) : externdecl(ed), file(f) {}
		void File::print()
		{
			if (debug) std::cerr << "this: " << this << " f: " << file << " ed: " << externdecl << std::endl;

			if (externdecl != NULL) externdecl->print();
			if (file != NULL) file->print();
		}
		void File::cgen()
		{
			if (externdecl != NULL) externdecl->cgen();
			
			// write to tunit
			tunit << header.str() << fpsetup.str() << argsetup.str() << genout.str() << fprestore.str() << footer.str() << std::endl;
			
			// clear strinstreams
			header.str("");
			fpsetup.str("");
			argsetup.str("");
			genout.str("");
			fprestore.str("");
			footer.str("");

			if (file != NULL) file->cgen();
		}

		ExternDecl::ExternDecl(FuncDec* _fd, Declaration* _d) : funcdec(_fd), declaration(_d) {}
		void ExternDecl::print()
		{
			if (debug) std::cerr << "ED" << std::endl;
			if (declaration != NULL) declaration->print() ;
			if (funcdec != NULL) funcdec->print();
		}
		void ExternDecl::cgen()
		{
			std::cerr << "ExternDecl: " << std::endl;
			if (declaration != NULL) declaration->cgen();
			if (funcdec != NULL) funcdec->cgen();
		}

		FuncDec::FuncDec(DeclSpec* _ds, Decl* _d, DeclarationSet* _dset, Comp* _c) : declspec(_ds), decl(_d), declarationset(_dset), compstate(_c) {}
		void FuncDec::print() 
		{
			if (debug) std::cerr << "FD" << std::endl;
			if (declspec != NULL) declspec->print();
			if (decl != NULL) decl->print();
			if (declarationset != NULL) declarationset->print();
			if (compstate != NULL) compstate->print();
		}
		void FuncDec::cgen()
		{
			// save offset
			func_mapping[decl->getID()] = offset;
			
			// reset offset
			offset = 0;
			if (compstate != NULL) compstate->get_arg_size(offset);
			std::cerr << "Func:\t" << decl->getID() << "\tArguments:\t" << offset << std::endl;
			if (offset < 4) offset = 4;
			offset = offset * 4;
			std::cerr << "Func:\t" << decl->getID() << "\tOffset:\t" << offset << std::endl;

			// print out header
			header << "\t.align\t2\n";
			header << "\t.globl\t" << decl->getID() << std::endl;
			header << "\t.ent\t" << decl->getID() << std::endl;
			header << "\t.type\t" << decl->getID();
			header << ", @function\n" << decl->getID() << ": " << std::endl;

			param_tag.clear();
			param_num = 0;

			// print out contents
			if (decl != NULL)
			{
				glbl_scope++;
				decl->cgen();
				glbl_scope--;
			}
			if (compstate != NULL) 
			{
				compstate->cgen();
			}

			// print out closure
			//footer << "\n\t.cprestore\t16" << std::endl;
			footer << "\t.end\t" << decl->getID() << std::endl;
			footer << "\t.size\t" << decl->getID() << ", .-" << decl->getID() << std::endl;

			// increase offset by 12 to account of sp and $31 saving
			offset += 12;
			fpsetup << "\taddiu\t$sp,$sp,-" << offset << std::endl;
			fpsetup << "\tsw\t$31," << offset - 4 << "($sp)" << std::endl;
			fpsetup << "\tsw\t$fp," << offset - 8 << "($sp)" << std::endl;
			fpsetup << "\tmove\t$fp,$sp" << std::endl;

			std::cerr << "Func:\t" << decl->getID() << "\tParam num:\t" << param_num << std::endl;
			for (int i = 0; i < param_num; i++)
			{
				if (i < 4)
				{
					argsetup << "\tsw\t" << "$a" << i << "," << offset_mapping[param_tag[i]] << "($fp)" << std::endl;
				}
				else
				{
					argsetup << "\tlw\t" << "$" << REG1 << "," << offset + (i*4) << "($fp)" << std::endl;
					argsetup << "\tsw\t" << "$" << REG1 << "," << offset_mapping[param_tag[i]] << "($fp)" << std::endl;
				}
			}

			fprestore << "\tmove\t$sp,$fp" << std::endl;
			fprestore << "\tlw\t$fp," << offset - 8 << "($sp)" << std::endl;
			fprestore << "\tlw\t$31," << offset - 4 << "($sp)" << std::endl;
			fprestore << "\taddiu\t$sp,$sp," << offset << std::endl;
			fprestore << "\tj\t" << "$31" << std::endl;
			fprestore << "\tnop" << std::endl;

			// load offset
			offset = func_mapping[decl->getID()];
		}

		Comp::Comp(DeclarationSet* ds, StateList* sl) : declarationset(ds), statelist(sl) 
		{
			scope = glbl_scope;	
		}
		void Comp::print()
		{
			if (debug) std::cerr << "COMP" << std::endl;
			std::cerr << "{" << std::endl;
			if (declarationset != NULL) declarationset->print();
			if (statelist != NULL) statelist->print();
			std::cerr << "}" << std::endl;
		}
		void Comp::cgen()
		{
			glbl_scope++;
			if (declarationset != NULL) declarationset->cgen();
			if (statelist != NULL) statelist->cgen();
			for (std::map<Tag, std::vector<Tag> >::iterator it = tag_mapping.begin(); it != tag_mapping.end(); ++it)
			{
				it->second.resize(glbl_scope);
			}
			glbl_scope--;
		}
		void Comp::get_arg_size(int& val)
		{
			if (statelist != NULL)
			{
				statelist->get_arg_size(val);
				std::cerr << "Comp: " << val << std::endl;
			}
		}

		StateList::StateList(State *s, StateList *sl) : state(s), statelist(sl) {}
		void StateList::print()
		{
			if (state != NULL) state->print();
			if (statelist != NULL) statelist->print();
		}
		void StateList::cgen()
		{
			if (state != NULL) state->cgen();
			if (statelist != NULL) statelist->cgen();
		}
		void StateList::get_arg_size(int& val)
		{
			int tmp = 0;
			if (state != NULL) state->get_arg_size(tmp);
			if (val < tmp)
			{
				val = tmp;
				std::cerr << "StateList: " << val << " " << tmp << std::endl;
			}
			if (statelist != NULL) statelist->get_arg_size(val);
		}

		ColonStatement::ColonStatement(State *s, Ternary *t, std::string id, int c, int d) : state(s), ternary(t), ID(id), vcase(c), vdefault(d) {}
		void ColonStatement::print ()
		{}
		void ColonStatement::cgen()
		{
			if(vcase)
			{
				if (!case_body)
				{
					std::string tern_tag = "";
					if (ternary != NULL)
					{
						ternary->cgen();
						ternary->get_tag(tern_tag);
					}
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tern_tag] << "($fp)" << std::endl;
					genout << "\tbne" << "\t$" << REG1 << ",$" << CREG << "," << "case_test_" << case_count + 1 << std::endl;
					genout << "\tnop" << std::endl;
					genout << "\tb" << "\t" << "case_body_" << case_count << std::endl;
					genout << "\tnop" << std::endl;
					genout << "case_test_" << case_count + 1 << ": " << std::endl;
					case_count++;	
				}
				else if (case_body)
				{
					genout << "case_body_" << case_count << ":" << std::endl;
					if (state != NULL) state->cgen();
					genout << "\tnop" << std::endl;
					case_count++;	
				}
			}
			if (vdefault)
			{
				if (case_body) 
				{
					if (state != NULL) state->cgen();
				}
			}
			if (ID != "")
			{
				genout << "label_" << ID << ":" << std::endl;
				if (state != NULL) state->cgen();
			}
		}
		void ColonStatement::get_arg_size(int& val)
		{
			int tmp = 0;
			int tmp1 = 0;
			if (ternary != NULL) ternary->get_arg_size(tmp);
			if (state != NULL) state->get_arg_size(tmp1);
			if ((tmp) || (tmp1))
			{
				if (tmp < tmp1)
				{
					val = tmp1;
				}
				else if (tmp1 < tmp)
				{
					val = tmp;
				}
			}
		}

		Jump::Jump(ExprStatement* e, std::string j, std::string i) : exprstatement(e), jump(j), id(i) {}
		void Jump::print()
		{
			if (jump != "") std::cerr << jump << " ";
			if (exprstatement != NULL) exprstatement->print();
			else 
			{
				if (id != "") std::cerr << id << " ";	
				std::cerr << ";" << std::endl;
			}
		}
		void Jump::cgen()
		{
			if (jump == "return")
			{
				std::string tag = "";
				exprstatement->cgen();
				exprstatement->get_tag(tag);
				if (offset_mapping[tag])
				{
					genout << "\tlw\t$2," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else
				{
					genout << "\tmove\t$2,$0" << std::endl;
				}
			}
			if (jump == "break")
			{
				genout << "\tb\t" << "break_exit_" << break_vec.back() << std::endl;
				genout << "\tnop" << std::endl;
			}
			if (jump == "goto")
			{
				genout << "\tb\t" << "label_" << id << std::endl;
				genout << "\tnop" << std::endl;
			}
		}
		void Jump::get_arg_size(int& val)
		{
			if (exprstatement != NULL) exprstatement->get_arg_size(val);
		}

		Select::Select(Expr* e, State *s, std::string sel, State *s2, std::string sel2) : expr(e), state(s), select(sel), state2(s2), select2(sel2) {}
		void Select::print()
		{
			if (select != "") std::cerr << select << " ";
			if (expr != NULL)
			{
				std::cerr << "( ";
				expr->print();
				std::cerr << ") ";
			}
			if (state != NULL) state->print(); 
			if (select2 != "") std::cerr << select2 << " ";
			if (state2 != NULL) state2->print();
		}
		void Select::cgen()
		{
			if (select == "if")
			{
				int select_count = glbl_select_count;
				if (state != NULL)
				{
					select_count++;
					glbl_select_count++;
					std::string if_tag = "";
					genout << "if_start_" << select_count << ":" << std::endl;
					if (expr != NULL) expr->cgen();
					if (expr != NULL) expr->get_tag(if_tag);
					expr->get_tag(if_tag);
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[if_tag] << "($fp)" << std::endl;
					genout << "\tbeq" << "\t$" << REG1 << ",$" << 0 << "," << "else_" << select_count << std::endl;
					genout << "\tnop" << std::endl;
					state->cgen();
					genout << "\tb\t" << "if_end_" << select_count <<  std::endl;
					genout << "\tnop" << std::endl;
					genout << "else_" << select_count << ":" << std::endl;
				}
				if (state2 != NULL)
				{
					state2->cgen();
				}
				genout << "if_end_" << select_count << ":" << std::endl;
				select_count--;
			}
			else if (select == "switch")
			{
				if (expr != NULL) 
				{
					break_count++;
					break_vec.push_back(break_count);
					std::string expr_tag = "";
					expr->cgen();
					expr->get_tag(expr_tag);
					genout << "\tlw" << "\t$" << CREG << "," << offset_mapping[expr_tag] << "($fp)" << std::endl;
					int save_case_count = case_count;
					case_body = 0;
					state->cgen();
					case_count = save_case_count;
					case_body = 1;
					state->cgen();
					case_body = 0;
					genout << "break_exit_" << break_vec.back() << ":" << std::endl;
					break_vec.pop_back();
				}
			}
		}
		void Select::get_arg_size(int& val)
		{
			int tmp = 0;
			int tmp2 = 0;
			int tmp3 = 0;
			if (expr != NULL) expr->get_arg_size(tmp);
			if (state != NULL) state->get_arg_size(tmp2);
			if (state2 != NULL) state2->get_arg_size(tmp3);
			if ((tmp) || (tmp2) || (tmp3))
			{
				if ((tmp2 < tmp) && (tmp3 < tmp))
				{
					val = tmp;
				}
				else if ((tmp3 < tmp2) && (tmp < tmp2))
				{
					val = tmp2;
				}
				else if ((tmp2 < tmp3) && (tmp < tmp3))
				{
					val = tmp3;
				}
			}
		}


		Loop::Loop(Expr *e, State *s, std::string l, ExprStatement *es, ExprStatement *es2, int d, std::string l2) : expr(e), state(s), loop(l), exprstatement(es), exprstatement2(es2), doing(d), loop2(l2) {}
		void Loop::print()
		{
			if (doing)
			{
				if (loop != "") std::cerr << loop << " ";
				if (state != NULL) state->print();
				if (loop2 != "") std::cerr << loop2 << " ";
				if (expr != NULL)
				{
					std::cerr << "( ";
					expr->print();
					std::cerr << " )";
					std::cerr << ";" << std::endl;
				}
			}
			else
			{
				if (loop != "") std::cerr << loop << " ";
				if (exprstatement != NULL) exprstatement->print();
				if (exprstatement2 != NULL) exprstatement2->print();
				if (expr != NULL)
				{
					std::cerr << "( ";
					expr->print();
					std::cerr << ") ";
				}
				if (state != NULL)
				{
					state->print();
				}
			}
		}
		void Loop::cgen()
		{
			int do_while_count = glbl_do_while_count;
			int while_count = glbl_while_count;
			int for_count = glbl_for_count;

			break_count++;
			break_vec.push_back(break_count);

			std::string expr_tag = "";
			if (loop == "while")
			{
				// increment loop label counter
				while_count++;
				glbl_while_count++;
				genout << "while_start_" << while_count << ":" << std::endl;
				expr->cgen();
				expr->get_tag(expr_tag);
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[expr_tag] << "($fp)" << std::endl;
				genout << "\tbeq" << "\t$" << REG1 << ",$" << 0 << "," << "while_end_" << while_count <<  std::endl;
				genout << "\tnop" << std::endl;
				state->cgen();
				genout << "\tb" << "\t" << "while_start_" << while_count << std::endl;
				genout << "\tnop" << std::endl;
				genout << "while_end_" << while_count << ":" << std::endl;
				while_count--;
			}
			if (loop == "do")
			{
				// increment loop label counter
				do_while_count++;
				glbl_do_while_count++;
				genout << "do_while_start_" << do_while_count << ":" << std::endl;
				state->cgen();
				expr->cgen();
				expr->get_tag(expr_tag);
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[expr_tag] << "($fp)" << std::endl;
				genout << "\tbne" << "\t$" << REG1 << ",$" << 0 << "," << "do_while_start_" << do_while_count << std::endl;
				genout << "\tnop" << std::endl;
				do_while_count--;
			}
			if (loop == "for")
			{
				// increment loop label counter
				for_count++;
				glbl_for_count++;
				exprstatement->cgen();
				genout << "for_start_" << for_count << ":" << std::endl;
				exprstatement2->cgen();
				exprstatement2->get_tag(expr_tag);
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[expr_tag] << "($fp)" << std::endl;
				genout << "\tbeq" << "\t$" << REG1 << ",$" << 0 << "," << "for_end_" << for_count <<  std::endl;
				genout << "\tnop" << std::endl;
				state->cgen();
				if (expr != NULL) expr->cgen();
				genout << "\tb" << "\t" << "for_start_" << for_count << std::endl;
				genout << "\tnop" << std::endl;
				genout << "for_end_" << for_count << ":" << std::endl;
				for_count--;
			}

			genout << "break_exit_" << break_vec.back() << ": " << std::endl;
			break_vec.pop_back();
		}
		void Loop::get_arg_size(int& val)
		{
			int tmp = 0;
			int tmp1 = 0;
			int tmp2 = 0;
			int tmp3 = 0;
			if (expr != NULL) expr->get_arg_size(tmp);
			if (exprstatement != NULL) exprstatement->get_arg_size(tmp1);
			if (exprstatement2 != NULL) exprstatement2->get_arg_size(tmp2);
			if (state != NULL) state->get_arg_size(tmp3);
			if ((tmp) || (tmp1) || (tmp2) || (tmp3))
			{
				if ((tmp1 < tmp) && (tmp2 < tmp) && (tmp3 < tmp))
				{
					val = tmp;
				}
				else if ((tmp < tmp1) && (tmp2 < tmp1) && (tmp3 < tmp1))
				{
					val = tmp1;
				}
				else if ((tmp1 < tmp2) && (tmp < tmp2) && (tmp3 < tmp2))
				{
					val = tmp2;
				}
				else if ((tmp1 < tmp3) && (tmp2 < tmp3) && (tmp < tmp3))
				{
					val = tmp3;
				}
				std::cerr << "Loop: " << val << std::endl;
			}
		}


		ExprStatement::ExprStatement(Expr *e) : expr(e) {}
		void ExprStatement::print()
		{
			if(debug) std::cerr << "ExprState" << std::endl;
			if (expr != NULL) expr->print();
			std::cerr << ";" << std::endl;
		}
		void ExprStatement::cgen()
		{
			if (expr != NULL) expr->cgen();
		}
		void ExprStatement::get_tag(std::string& in_tag)
		{
			if (expr != NULL) expr->get_tag(in_tag);
		}
		void ExprStatement::get_arg_size(int& val)
		{
			if (expr != NULL)
			{
				expr->get_arg_size(val);
				std::cerr << "EpxrStat: " << val << std::endl;
			}
		}

		Expr::Expr(AssignExpr *ae, Expr *e) : assignexpr(ae), expr(e) {}
		void Expr::print()
		{
			if (debug) std::cerr << "Expr" << std::endl;
			if (assignexpr != NULL) 
			{
				assignexpr->print();
			}
			if (expr != NULL) 
			{
				std::cerr << ", ";
				expr->print();
			}
		}
		void Expr::cgen()
		{
			if (assignexpr != NULL) assignexpr->cgen();
			if (expr != NULL) expr->cgen();
		}
		void Expr::get_tag(std::string& in_tag)
		{
			if (assignexpr != NULL) assignexpr->get_tag(in_tag);
			if (expr != NULL) expr->get_tag(in_tag);
		}
		void Expr::get_arg_size(int& val)
		{
			int tmp = 0;
			int tmp1 = 0;
			if (assignexpr != NULL) assignexpr->get_arg_size(tmp);
			if (expr != NULL) expr->get_arg_size(tmp1);
			if ((tmp) || (tmp1))
			{
				if (tmp < tmp1)
				{
					val = tmp1;
				}
				else if (tmp1 < tmp)
				{
					val = tmp;
				}
				std::cerr << "Expr: " << val << std::endl;
			}
		}

		AssignExpr::AssignExpr(Ternary *t, Unary *u, std::string ao, AssignExpr* ae) : ternary(t), unary(u), assignop(ao), assignexpr(ae) 
		{
			//if (assignop != "")
			//{
			//	tag = setOffset();
			//}
		}
		void AssignExpr::print()
		{
			if (ternary != NULL) ternary->print();
			if (unary != NULL) unary->print();
			if (assignop != "") std::cerr << assignop << " ";
			if (assignexpr != NULL) assignexpr->print();
		}
		void AssignExpr::cgen()
		{
			if (assignop != "")
			{
				tag = setOffset();
			}
			if (tag != "")
			{
				std::cerr << "\nTAG: " << tag << std::endl;
				std::cerr << "OP: " << assignop << std::endl;
			}
			std::string lhs;
			std::string rhs;
			std::string mhs;
			if (unary != NULL) unary->get_tag(lhs);
			if (ternary != NULL) ternary->get_tag(rhs);
			if (assignexpr != NULL) assignexpr->get_tag(rhs);
			if (tag != "")
			{
				std::cerr << "LHS: " << lhs << std::endl;
				std::cerr << "RHS: " << rhs << std::endl;
			}
			int type = 0;
			if (unary != NULL)
			{
				unary->get_type(type);
				if ((type == 1) || (type == 2))
				{
					// type is an array
					int tmp = 1;
					unary->set_return_type(tmp);
				}
				unary->cgen();
			}
			if (ternary != NULL) 
			{
				//ternary->get_type(type);
				//if (type == 1)
				//{
				//	// type is an array
				//	ternary->set_return_type(type);
				//}
				ternary->cgen();
			}
			if (assignexpr != NULL)
			{
				assignexpr->cgen();
			}
			
			std::string lhs_tag = "";
			std::string rhs_tag = "";
			if (assignop == "=")
			{
				unary->get_type(type);
				assignexpr->get_tag(rhs_tag);
				unary->get_tag(lhs_tag);
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
				
				// if its an array
				if ((type == 1) || (type == 2))
				{
					genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << ",0($" << REG2 << ")" << std::endl;
				}
				else
				{
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				}

				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
			else if (assignop == "+=")
			{
				arithmetic_ass("add", assignexpr, unary, tag);
			}
			else if (assignop == "-=") 
			{
				arithmetic_ass("sub", assignexpr, unary, tag);
			}
			else if (assignop == "*=")
			{
				arithmetic_ass("mul", assignexpr, unary, tag);
			}
			else if (assignop == "/=")
			{
				arithmetic_ass("div", assignexpr, unary, tag);
			}
			else if (assignop == "%=")
			{
				arithmetic_ass("rem", assignexpr, unary, tag);
			}
			else if (assignop == "<<=")
			{
				arithmetic_ass("sllv", assignexpr, unary, tag);
			}
			else if (assignop == ">>=")
			{
				arithmetic_ass("srav", assignexpr, unary, tag);
			}
			else if (assignop == "&=")
			{
				arithmetic_ass("and", assignexpr, unary, tag);
			}
			else if (assignop == "^=")
			{
				arithmetic_ass("xor", assignexpr, unary, tag);
			}
			else if (assignop == "|=")
			{
				arithmetic_ass("or", assignexpr, unary, tag);
			}
			if (unary != NULL)
			{
				int tmp = 0;
				// set return type back to value
				unary->set_return_type(tmp);
			}
		}
		void AssignExpr::get_tag(std::string& in_tag)
		{
			if (assignop != "")
			{
				in_tag = tag;
			}
			else if ((unary != NULL) && (in_tag == "")) 
			{
				unary->get_tag(in_tag);
			}
			else if ((assignexpr != NULL) && (in_tag == "")) 
			{
				assignexpr->get_tag(in_tag);
			}
			else if ((ternary != NULL) && (in_tag == "")) 
			{
				ternary->get_tag(in_tag);
			}
		}
		void AssignExpr::get_arg_size(int& val)
		{
			int tmp = 0;
			int tmp1 = 0;
			int tmp2 = 0;
			if (unary != NULL) unary->get_arg_size(tmp);
			if (assignexpr != NULL) assignexpr->get_arg_size(tmp1);
			if (ternary != NULL) ternary->get_arg_size(tmp2);
			if ((tmp) || (tmp1) || (tmp2))
			{
				if ((tmp < tmp2) &&  (tmp1 < tmp2))
				{
					val = tmp2;
				}
				else if ((tmp < tmp1) && (tmp2 < tmp1))
				{
					val = tmp1;
				}
				else if ((tmp1 < tmp) && (tmp2 < tmp))
				{
					val = tmp;
				}
				std::cerr << "AssignExpr: " << val << std::endl;
			}
		}

		Ternary::Ternary(Prec *lo, Expr *e, Ternary *t) : logor(lo), expr(e), ternary(t) 
		{
			//if (expr != NULL)	
			//{
			//	tag = setOffset();
			//}
		}
		void Ternary::print()
		{
			if (logor != NULL) logor->print();
			if (expr != NULL) expr->print();
			if (ternary != NULL) ternary->print();
		}
		void Ternary::cgen()
		{
			std::string cond_tag = "";
			std::string lhs_tag = "";
			std::string rhs_tag = "";
			if (expr != NULL)	
			{
				tag = setOffset();
			}
			if (expr != NULL) 
			{
				expr->cgen();
				expr->get_tag(lhs_tag);
			}
			if (ternary != NULL) 
			{
				ternary->cgen();
				ternary->get_tag(rhs_tag);
			}
			if (logor != NULL) 
			{
				logor->cgen();
				logor->get_tag(cond_tag);
			}
			if (ternary != NULL)
			{
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				genout << "\tlw" << "\t$" << REG3 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[cond_tag] << "($fp)" << std::endl;
				genout << "\tmovz" << "\t$" << REG2 << ",$" << REG3 << ",$" << REG1 << std::endl;
				genout << "\tsw" << "\t$" << REG2 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
		
		}
		void Ternary::get_tag(std::string& in_tag)
		{
			if (expr != NULL)
			{
				in_tag = tag;
				expr->get_tag(in_tag);
			}
			if ((logor != NULL) && (in_tag == ""))
			{
				logor->get_tag(in_tag);
			}
		}
		void Ternary::get_arg_size(int& val)
		{
			int tmp = 0;
			int tmp1 = 0;
			int tmp2 = 0;
			if (logor != NULL) logor->get_arg_size(tmp);
			else if (expr != NULL) expr->get_arg_size(tmp1);
			else if (ternary != NULL) ternary->get_arg_size(tmp2);
			if ((tmp) || (tmp1) || (tmp2))
			{
				if ((tmp1 < tmp) && (tmp2 < tmp))
				{
					val = tmp;
				}
				else if ((tmp < tmp1) && (tmp2 < tmp1))
				{
					val = tmp1;
				}
				else if ((tmp < tmp2) && (tmp1 < tmp2))
				{
					val = tmp2;
				}
				std::cerr << "Ternary: " << val << std::endl;
			}
		}
		void Ternary::get_array_size(int& asize)
		{
			if (logor != NULL) logor->get_array_size(asize);
		}
		void Ternary::get_type(int& type)
		{
			if (logor != NULL) logor->get_type(type);
		}
		void Ternary::set_return_type(int& rtype)
		{
			if (logor != NULL) logor->set_return_type(rtype);
		}

		Prec::Prec(Prec *p1, Prec *p2, std::string o, TypeCast *as) : lhs(p1), rhs(p2), op(o), typecast(as) 
		{
		}
		void Prec::print()
		{
			if ( (lhs && rhs) || (lhs && typecast) ) std::cerr << "( ";
			if (lhs != NULL) lhs->print();
			if (op != "") std::cerr << op << " ";
			if (typecast != NULL) typecast->print();
			if (rhs != NULL) rhs->print();  
			if ((lhs && rhs) || (lhs && typecast)) std::cerr << ") ";
		}
		void Prec::cgen()
		{
			if (op != "")
			{
				tag = setOffset();
			}
			if (tag != "")
			{
				std::cerr << "\nTAG: " << tag << std::endl;
				std::cerr << "OP: " << op << std::endl;
			}
			std::string rhst;
			std::string lhst;
			std::string unaryt;
			if (rhs != NULL) rhs->get_tag(rhst);
			if (lhs != NULL) lhs->get_tag(lhst);
			if (tag != "")
			{
				std::cerr << "RHS: " << rhst << std::endl;
				std::cerr << "LHS: " << lhst << std::endl;
			}
			std::string tag_lhs = "";
			std::string tag_rhs = "";
			std::string tag_tc = "";
			if (rhs != NULL) 
			{
				rhs->cgen();
				rhs->get_tag(tag_rhs);
			}
			if (lhs != NULL) 
			{
				lhs->cgen();
				lhs->get_tag(tag_lhs);
			}
			if (typecast != NULL) 
			{
				typecast->cgen();
				typecast->get_tag(tag_tc);
			}
			if(op == "+")
			{
				int ltype = 0;
				int rtype = 0;
				if (lhs != NULL)
				{
					lhs->get_tag(tag_lhs);
					lhs->get_type(ltype);
				}
				if (rhs != NULL)
				{
					rhs->get_tag(tag_rhs);
					rhs->get_type(rtype);
				}

				if ((pointer_mapping[tag_lhs]) && (pointer_mapping[tag_rhs]))
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
					genout << "\tadd" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
					genout << "\tsra" << "\t$" << REG1 << ",$" << REG1 << "," << 2 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else if (pointer_mapping[tag_lhs])
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
					genout << "\tsll" << "\t$" << REG2 << ",$" << REG2 << "," << 2 << std::endl;
					genout << "\tadd" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else if (pointer_mapping[tag_rhs])
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
					genout << "\tsll" << "\t$" << REG1 << ",$" << REG1 << "," << 2 << std::endl;
					genout << "\tadd" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else if ((!pointer_mapping[tag_lhs]) && (!pointer_mapping[tag_rhs]))
				{
					arithmetic_expr("add", tag_lhs, tag_rhs, tag);
				}
			}
			else if (op == "-")
			{
				int ltype = 0;
				int rtype = 0;
				if (lhs != NULL)
				{
					lhs->get_tag(tag_lhs);
					lhs->get_type(ltype);
				}
				if (rhs != NULL)
				{
					rhs->get_tag(tag_rhs);
					rhs->get_type(rtype);
				}

				if ((pointer_mapping[tag_lhs]) && (pointer_mapping[tag_rhs]))
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
					genout << "\tsub" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
					genout << "\tsra" << "\t$" << REG1 << ",$" << REG1 << "," << 2 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else if (pointer_mapping[tag_lhs])
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
					genout << "\tsll" << "\t$" << REG2 << ",$" << REG2 << "," << 2 << std::endl;
					genout << "\tsub" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else if (pointer_mapping[tag_lhs])
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
					genout << "\tsll" << "\t$" << REG1 << ",$" << REG1 << "," << 2 << std::endl;
					genout << "\tsub" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else if ((!pointer_mapping[tag_lhs]) && (!pointer_mapping[tag_rhs]))
				{
					arithmetic_expr("sub", tag_lhs, tag_rhs, tag);
				}
			}
			else if (op == "*")
			{
				//arithmetic_expr("mul", tag_lhs, tag_rhs, tag);

				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_tc] << "($fp)" << std::endl;
				genout << "\tmul" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				genout << "\tnop" << std::endl << "\tnop" << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
			else if (op == "/")
			{
				//arithmetic_expr("div", tag_lhs, tag_rhs, tag);

				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_tc] << "($fp)" << std::endl;
				genout << "\tdiv" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				genout << "\tnop" << std::endl << "\tnop" << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
			else if (op == "%")
			{
				//arithmetic_expr("rem", tag_lhs, tag_rhs, tag);

				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_tc] << "($fp)" << std::endl;
				genout << "\trem" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				genout << "\tnop" << std::endl << "\tnop" << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
			else if (op == "<<")
			{
				arithmetic_expr("sllv", tag_lhs, tag_rhs, tag);
			}
			else if (op == ">>")
			{
				arithmetic_expr("srav", tag_lhs, tag_rhs, tag);
			}
			else if (op == "&")
			{
				arithmetic_expr("and", tag_lhs, tag_rhs, tag);
			}
			else if (op == "^")
			{
				arithmetic_expr("xor", tag_lhs, tag_rhs, tag);
			}
			else if (op == "|")
			{
				arithmetic_expr("or", tag_lhs, tag_rhs, tag);
			}
			else if (op == "&&")
			{				
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
				genout << "\tsne" << "\t$" << REG1 << ",$" << REG1 << "," << "0" << std::endl;
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
				genout << "\tsne" << "\t$" << REG2 << ",$" << REG2 << "," << "0" << std::endl;
				genout << "\tand" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
			else if (op == "||")
			{
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_lhs] << "($fp)" << std::endl;
				genout << "\tsne" << "\t$" << REG1 << ",$" << REG1 << "," << "0" << std::endl;
				genout << "\tlw" << "\t$" << REG2 << "," << offset_mapping[tag_rhs] << "($fp)" << std::endl;
				genout << "\tsne" << "\t$" << REG2 << ",$" << REG2 << "," << "0" << std::endl;
				genout << "\tor" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
			}
			else if (op == "<")
			{
				arithmetic_expr("slt", tag_lhs, tag_rhs, tag);
			}
			else if (op == "<=")
			{
				arithmetic_expr("sle", tag_lhs, tag_rhs, tag);
			}
			else if (op == ">")
			{
				arithmetic_expr("sgt", tag_lhs, tag_rhs, tag);
			}
			else if (op == ">=")
			{
				arithmetic_expr("sge", tag_lhs, tag_rhs, tag);
			}
			else if (op == "==")
			{
				arithmetic_expr("seq", tag_lhs, tag_rhs, tag);
			}
			else if (op == "!=")
			{
				arithmetic_expr("sne", tag_lhs, tag_rhs, tag);
			}
		}
		void Prec::get_tag(std::string& in_tag)
		{
			if (op != "")
			{
				in_tag = tag;
			}
			else if ((lhs != NULL) && (in_tag == "")) 
			{
				lhs->get_tag(in_tag);
			}
			else if ((rhs != NULL) && (in_tag == "")) 
			{
				rhs->get_tag(in_tag);
			}
			else if ((typecast != NULL) && (in_tag == ""))
			{
				typecast->get_tag(in_tag);
			}
		}
		void Prec::get_arg_size(int& val)
		{
			int tmp = 0;
			int tmp1 = 0;
			int tmp2 = 0;
			if (lhs != NULL) lhs->get_arg_size(tmp);
			if (rhs != NULL) rhs->get_arg_size(tmp1);
			if (typecast != NULL) typecast->get_arg_size(tmp2);
			if ((tmp) || (tmp1) || (tmp2))
			{
				if ((tmp1 < tmp) && (tmp2 < tmp))
				{
					val = tmp;
				}
				else if ((tmp < tmp1) && (tmp2 < tmp1))
				{
					val = tmp1;
				}
				else if ((tmp < tmp2) && (tmp1 < tmp2))
				{
					val = tmp2;
				}
				std::cerr << "Prec: " << val << " " << tmp << " " << tmp1 << " " << tmp2 << std::endl;
			}
		}
		void Prec::get_array_size(int& asize)
		{
			if (lhs != NULL) lhs->get_array_size(asize);
			if (rhs != NULL) rhs->get_array_size(asize);
			if (typecast != NULL) typecast->get_array_size(asize);
		}
		void Prec::get_type(int& type)
		{
			if (lhs != NULL) lhs->get_type(type);
			if (rhs != NULL) rhs->get_type(type);
			if (typecast != NULL) typecast->get_type(type);
		}
		void Prec::set_return_type(int& rtype)
		{
			if (lhs != NULL) lhs->set_return_type(rtype);
			if (rhs != NULL) rhs->set_return_type(rtype);
			if (typecast != NULL) typecast->set_return_type(rtype);
		}

		TypeCast::TypeCast(Unary *u, TypeCast *tc) : unary(u), typecast(tc) {}
		void TypeCast::print()
		{
			if (unary != NULL) unary->print();
			if (typecast != NULL)
			{
				std::cerr << "( )";
				typecast->print();
			}
		}
		void TypeCast::cgen()
		{
			unary->cgen();
		}
		void TypeCast::get_tag(std::string& in_tag)
		{
			unary->get_tag(in_tag);
		}
		void TypeCast::get_arg_size(int& val)
		{
			if (unary != NULL) unary->get_arg_size(val);
		}
		void TypeCast::get_array_size(int& asize)
		{
			if (unary != NULL) unary->get_array_size(asize);
		}
		void TypeCast::get_type(int& type)
		{
			if (unary != NULL) unary->get_type(type);
		}
		void TypeCast::set_return_type(int& rtype)
		{
			if (unary != NULL) unary->set_return_type(rtype);
		}

		Unary::Unary(Postfix *p, Unary *u, TypeCast *tc, std::string uo, int i, int d, int s, int e) : postfix(p), unary(u), typecast(tc), unaryop(uo), inc(i), dec(d), size(s), empty(e), return_type(0) {}
		void Unary::print()
		{
			if (postfix != NULL) postfix->print();
			if (inc || dec) {
				if (inc) std::cerr << "++";
				if (dec) std::cerr << "--";
				if (unary != NULL) unary->print();
			}
			if (unaryop != "") std::cerr << unaryop << " ";
			if (typecast != NULL) typecast->print();
			if (size)
			{
				std::cerr << "sizeof ";
				if (unary != NULL) unary->print();
				if (empty) std::cerr << "( )";
			}
		}
		void Unary::cgen()
		{
			if (postfix != NULL) postfix->cgen();	
			if ((inc == 1) || (dec == 1))
			{
				if (unary != NULL)
				{
					int type = 0;
					unary->get_type(type);
					if (type == 1)
					{
						unary->set_return_type(type);
					}
				}
			}

			if (unary != NULL)
			{
				std::cerr << "\nTAG: " << tag << std::endl;
				std::cerr << "OP: " << unaryop << std::endl;
				if (unary != NULL) unary->cgen();
				std::string lhs_tag = "";	
				tag = setOffset();
				if (unary != NULL)
				{
					unary->set_inc_dec(1);
					unary->get_tag(lhs_tag);
				}
				if (inc != 0)
				{
					if (array_offset_mapping[lhs_tag])
					{
						if (unary != NULL) unary->set_inc_dec(0);
						if (unary != NULL) unary->get_tag(lhs_tag);
						genout << "\tlw" << "\t$" << AREG << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\tlw" << "\t$" << REG1 << "," << "0($" << AREG << ")" << std::endl;
						genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << 1 << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," <<  "0($" << AREG << ")" << std::endl;
					}
					else if (pointer_mapping[lhs_tag])
					{
						genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << 4 << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					}
					else
					{
						genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << 1 << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					}
				}
				if (dec != 0)
				{
					if (array_offset_mapping[lhs_tag])
					{
						if (unary != NULL) unary->set_inc_dec(0);
						if (unary != NULL) unary->get_tag(lhs_tag);
						genout << "\tlw" << "\t$" << AREG << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\tlw" << "\t$" << REG1 << "," << "0($" << AREG << ")" << std::endl;
						genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << -1 << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," <<  "0($" << AREG << ")" << std::endl;
					}
					else if (pointer_mapping[lhs_tag])
					{
						genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << -4 << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					}
					else
					{
						genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << -1 << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					}
				}
			}
			if (typecast != NULL)
			{
				typecast->cgen();
				std::string rhs_tag = "";
				tag = setOffset();
				if (unaryop == "+")
				{
					std::cerr << "\nTAG: " << tag << std::endl;
					std::cerr << "OP: " << unaryop << std::endl;
					if (typecast != NULL) typecast->get_tag(rhs_tag);
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				if (unaryop == "-")
				{
					std::cerr << "\nTAG: " << tag << std::endl;
					std::cerr << "OP: " << unaryop << std::endl;
					if (typecast != NULL) 
					{
						typecast->get_tag(rhs_tag);
					}
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
					genout << "\tneg\t$" << REG1 << ",$" << REG1 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				if (unaryop == "~")
				{
					if (typecast != NULL) typecast->get_tag(rhs_tag);
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
					genout << "\tnot\t$" << REG1 << ",$" << REG1 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				if (unaryop == "!")
				{
					if (typecast != NULL) typecast->get_tag(rhs_tag);
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
					genout << "\tmovn" << "\t$" << REG3 << ",$" << 0 << ",$" << REG1 << std::endl;
					genout << "\tli" << "\t$" << REG2 << "," << 1 << std::endl;
					genout << "\tmovz" << "\t$" << REG3 << ",$" << REG2 << ",$" << REG1 << std::endl;
					genout << "\tsw" << "\t$" << REG3 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				if (unaryop == "*")
				{
					if (typecast != NULL) typecast->get_tag(rhs_tag);
					if (return_type == 0)
					{
						genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
						genout << "\tlw" << "\t$" << REG1 << ",0($" << REG1 << ")" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					}
					else
					{
						genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
						genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					}
				}
				if (unaryop == "&")
				{
					if (typecast != NULL) typecast->get_tag(rhs_tag);
					genout << "\tla" << "\t$" <<  REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" <<  REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
			}
		}
		void Unary::set_inc_dec(int set)
		{
			if (postfix != NULL) postfix->set_inc_dec(set);
		}
		void Unary::get_tag(std::string& in_tag)
		{
			if (unary != NULL) in_tag = tag;
			if (typecast != NULL) in_tag = tag;
			if (postfix != NULL) postfix->get_tag(in_tag);	
		}
		void Unary::get_arg_size(int& val)
		{
			if (postfix != NULL) 
			{
				postfix->get_arg_size(val);
				std::cerr << "Unary: " << val << std::endl;
			}
		}
		void Unary::get_type(int& type)
		{
			if (postfix != NULL)
			{
				postfix->get_type(type);
			}
			if (unaryop == "*")
			{
				 type = 2;
			}
		}
		void Unary::set_return_type(int& rtype)
		{
			if (postfix != NULL)
			{
				postfix->set_return_type(rtype);
			}
			if (unaryop == "*")
			{
				return_type = rtype;
			}
		}
		void Unary::get_array_size(int& asize)
		{
			if (unary != NULL) unary->get_array_size(asize);
			if (postfix != NULL) postfix->get_array_size(asize);
		}

		ArgList::ArgList(AssignExpr* ae, ArgList* al) : assignexpr(ae), arglist(al) {}
		void ArgList::print() {}
		void ArgList::cgen()
		{	
			if (assignexpr != NULL) 
			{
				std::string rhs = "";
				assignexpr->cgen();
				assignexpr->get_tag(rhs);
				
				//if (type == 1)
				//{
				//	genout << "\tla" << "\t$" << REG3 << "," << "array_data_" << rhs << std::endl; 
				//}
				//else
				//{
					genout << "\tlw\t" << "$" << REG1 << "," << offset_mapping[rhs] << "($fp)" << std::endl;
				//}
				
				if (arg_count < 4)
				{
					genout << "\tmove\t" << "$a" << arg_count << ",$" << REG1 << std::endl;
				}
				genout << "\tsw\t" << "$" << REG1 << "," << arg_count * 4 << "($fp)" << std::endl;
				arg_count++;
			}

			if (arglist != NULL) 
			{
				arglist->cgen();
			}
		
		}
		void ArgList::get_arg_size(int& val)
		{
			if (arglist != NULL) arglist->get_arg_size(val);
			if (assignexpr != NULL) val++;
			std::cerr << "ArgList: " << val << std::endl;
		}

		Postfix::Postfix(Factor *f, Expr *e, ArgList *a, Postfix *p, std::string _ID, std::string _inc, std::string _dec) : factor(f), expr(e), arglist(a), postfix(p), ID(_ID), inc(_inc), dec(_dec) {}
		void Postfix::print()
		{
			if (factor != NULL) factor->print();
			if (postfix != NULL) postfix->print();
			if (expr != NULL) expr->print();
			if (arglist != NULL) arglist->print();
			if (ID != "") std::cerr << ID << " ";
			if (inc != "") std::cerr << inc << " ";
			if (dec != "") std::cerr << dec << " ";
		}
		void Postfix::cgen()
		{
			if (factor != NULL) factor->cgen();
			if ((inc != "") || (dec != ""))
			{
				if (postfix != NULL)
				{
					int type = 0;
					postfix->get_type(type);
					if (type == 1)
					{
						postfix->set_return_type(type);
					}
				}
			}
			if (postfix != NULL) postfix->cgen();
			if (arglist != NULL) 
			{
				tag = setOffset();
				arglist->cgen();
				arg_count = 0;
				genout << "\tla" << "\t$" << REG1 << "," << postfix->get_ID() << std::endl;
				genout << "\tjalr" << "\t$" << REG1 << std::endl;
				genout << "\tnop" << std::endl;
				genout << "\tsw" << "\t$2," << offset_mapping[tag] << "($fp)" << std::endl;
			}
			std::string lhs_tag = "";
			std::string rhs_tag = "";
			if (inc != "")
			{
				tag = setOffset();
				if (postfix != NULL) 
				{
					postfix->set_inc_dec(1);
					postfix->get_tag(lhs_tag);
				}
				int type = 0;
				if (array_offset_mapping[lhs_tag])
				{
					postfix->set_inc_dec(0);
					postfix->get_tag(lhs_tag);
					genout << "\tlw" << "\t$" << AREG << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG1 << "," << "0($" << AREG << ")" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << 1 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," <<  "0($" << AREG << ")" << std::endl;
				}
				else if (pointer_mapping[lhs_tag])
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << 4 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				}
				else
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << 1 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				}
			}
			if (dec != "")
			{
				tag = setOffset();
				if (postfix != NULL) 
				{
					postfix->set_inc_dec(1);
					postfix->get_tag(lhs_tag);
				}
				if (array_offset_mapping[lhs_tag])
				{
					postfix->set_inc_dec(0);
					postfix->get_tag(lhs_tag);
					genout << "\tlw" << "\t$" << AREG << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
					genout << "\tlw" << "\t$" << REG1 << "," << "0($" << AREG << ")" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << -1 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << "0($" << AREG << ")" << std::endl;
				}
				else if (pointer_mapping[lhs_tag])
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << -4 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				}
				else
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag] << "($fp)" << std::endl;
					genout << "\taddi" << "\t$" << REG1 << ",$" << REG1 << "," << -1 << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				}
			}
			if (expr != NULL)
			{
				tag = setOffset();
				expr->cgen();
				expr->get_tag(lhs_tag);
				postfix->get_tag(rhs_tag);

				//genout << "\tla" << "\t$" << AREG << "," << "array_data_" << rhs_tag << std::endl;
				genout << "\tlw" << "\t$" << AREG << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;

				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				genout << "\tli" << "\t$" << REG2 << "," << 4 << std::endl;
				genout << "\tmul" << "\t$" << REG1 << ",$" << REG1 << ",$" << REG2 << std::endl;
				genout << "\tnop" << std::endl;
				genout << "\tnop" << std::endl;
				genout << "\tadd" << "\t$" << AREG << ",$" << AREG << ",$" << REG1 << std::endl;
			
				if (return_type == 0)
				{
					// return value
					genout << "\tlw" << "\t$" << REG2 << ",0($" << AREG << ")" << std::endl;
					genout << "\tsw" << "\t$" << REG2 << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
				else
				{
					// return memory location
					genout << "\tsw" << "\t$" << AREG << "," << offset_mapping[tag] << "($fp)" << std::endl;
				}
			}
		}
		void Postfix::get_tag(std::string& in_tag)
		{
			if ((inc != "") || (dec != "")) in_tag = tag;
			if (arglist != NULL) in_tag = tag;
			if ((expr != NULL) && !incdec)
			{
				in_tag = tag;
			}
			if ((expr != NULL) && incdec)
			{
				postfix->get_tag(in_tag);
			}
			if (factor != NULL) factor->get_tag(in_tag);
		}
		void Postfix::get_arg_size(int& val)
		{
			if (arglist != NULL) 
			{
				arglist->get_arg_size(val);
				std::cerr << "Postfix: " << val << std::endl;
			}
		}
		std::string Postfix::get_ID()
		{
			if (factor != NULL) 
			{
				return factor->get_ID();	
			}
			else 
			{
				return postfix->get_ID();
			}
		}
		void Postfix::set_inc_dec(int set)
		{
			incdec = set;
		}
		void Postfix::get_type(int& type)
		{
			// if array, return 1
			if (expr != NULL)
			{
				type = 1;
			}
			//if ((inc != "") || (dec != ""))
			//{
			//	postfix->get_type(type);
			//}
		}
		void Postfix::set_return_type(int& rtype)
		{
			//if ((inc != "") || (dec != "")) 
			//{
			//	postfix->set_return_type(rtype);
			//}
			//else
			//{
				return_type = rtype;
			//}
		}
		void Postfix::get_array_size(int& asize)
		{
			if (postfix != NULL) postfix->get_array_size(asize);
			if (factor != NULL) factor->get_array_size(asize);
		}

		Factor::Factor(std::string v, int t, Expr *e) : val(v), type(t), expr(e) 
		{
			//if (val != "")
			//{
			//	if (tag_mapping[val].empty())
			//	{
			//		std::cerr << "HERE1" << std::endl;
			//		tag = setOffset();
			//		tag_mapping[val].resize(glbl_scope + 1);
			//		tag_mapping[val][glbl_scope] = tag;
			//	}
			//	else if (tag_mapping[val].size() != 0)
			//	{
			//		std::cerr << "HERE : " << glbl_scope << std::endl;
			//		for (int i = glbl_scope - 1; i >= 0; i--)
			//		{
			//			if (tag_mapping[val][i] != "")
			//			{
			//				tag = tag_mapping[val][i];
			//				std::cerr << i << " " << tag_mapping[val][glbl_scope] << std::endl;
			//				break;
			//			}
			//		}
			//	}
			//}
		}
		void Factor::print()
		{
			if (val != "") std::cerr << val << " "; 
		}
		void Factor::cgen()
		{
			int index = -1;
			if (val != "")
			{
				if (tag_mapping[val].empty())
				{
					tag = setOffset();
					tag_mapping[val].resize(glbl_scope + 1);
					tag_mapping[val][glbl_scope] = tag;
					index = glbl_scope;
				}
				else if (tag_mapping[val].size() != 0)
				{
					for (int i = glbl_scope; i >= 0; i--)
					{
						if (i < tag_mapping[val].size())
						{
							if (tag_mapping[val][i] != "")
							{
								tag = tag_mapping[val][i];
								index = i;
								break;
							}
						}
					}
					if (index == -1)
					{
						tag = setOffset();
						tag_mapping[val][glbl_scope] = tag;
						index = glbl_scope;
					}
				}
			}
			
			if (expr != NULL) 
			{
				expr->cgen();
			}
			else
			{
				std::cerr << "\nTAG: " << tag << std::endl;
				std::cerr << "VAL: " << val << std::endl;

				if (type == 1)
				{ 
					rvalue = std::stoi(val, NULL, 10);
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_mapping[val][index]] << "($fp)" << std::endl;
					genout << "\tli" << "\t$" << REG1 << "," << rvalue << std::endl;		
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag_mapping[val][index]] << "($fp)" << std::endl;
				}
				else if (type == 2)
				{
					rvalue = std::stoi(val, NULL, 8);
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_mapping[val][index]] << "($fp)" << std::endl;
					genout << "\tli" << "\t$" << REG1 << "," << rvalue << std::endl;		
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag_mapping[val][index]] << "($fp)" << std::endl;
				}
				else if (type == 3)
				{
					rvalue = std::stoi(val, NULL, 16);
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[tag_mapping[val][index]] << "($fp)" << std::endl;
					genout << "\tli" << "\t$" << REG1 << "," << rvalue << std::endl;		
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[tag_mapping[val][index]] << "($fp)" << std::endl;
				}
			}
		}
		void Factor::get_tag(std::string& in_tag)
		{
			if (val != "")
			{
				in_tag = tag;
			}
			if (expr != NULL)
			{
				expr->get_tag(in_tag);
			}
		}
		std::string Factor::get_ID()
		{
			return val;
		}
		void Factor::get_array_size(int& asize)
		{
			asize = rvalue;
		}

		ParamEllipsisList::ParamEllipsisList(ParamList *pl, std::string e) : paramlist(pl), ellipsis(e) {}
		void ParamEllipsisList::print()
		{
			if (paramlist != NULL) paramlist->print();
			if (ellipsis != "") std::cerr << ", " << ellipsis << " ";
		}
		void ParamEllipsisList::cgen()
		{
			if (paramlist != NULL) paramlist->cgen();
		}

		ParamList::ParamList(ParamDecl *pd, ParamList *pl) : paramdecl(pd), paramlist(pl) {}
		void ParamList::print()
		{
			if (paramdecl != NULL) paramdecl->print();
			if (paramlist != NULL) 
			{
				std::cerr << ", ";
				paramlist->print();
			}
		}
		void ParamList::cgen()
		{
			if (paramdecl != NULL) paramdecl->cgen();
			if (paramlist != NULL) paramlist->cgen();
		}


		ParamDecl::ParamDecl(DeclSpec *ds, Decl *d) : declspec(ds), decl(d) {}
		void ParamDecl::print()
		{
			if (declspec != NULL) declspec->print();
			if (decl != NULL) decl->print();
		}
		void ParamDecl::cgen()
		{
			if (decl != NULL) 
			{
				std::string tag = "";
				decl->cgen();
				decl->get_tag(tag);
				std::cerr << "TESTT: " << tag << std::endl;
				param_tag.push_back(tag);
				std::cerr << "PNUM: " <<  param_num << std::endl;
				param_num++;
			}
		}

		InitDeclList::InitDeclList(InitDecl *id, InitDeclList *idl) : initdecl(id), initdecllist(idl) {}
		void InitDeclList::print()
		{
			if (initdecllist != NULL)
			{
				initdecllist->print(); 
				std::cerr << "," << " ";
			}
			if (initdecl != NULL) initdecl->print();
		}
		void InitDeclList::cgen()
		{
			if (initdecl != NULL) initdecl->cgen();
			if (initdecllist != NULL) initdecllist->cgen();
		}
		void InitDeclList::get_tag(std::string& in_tag)
		{
		}

		InitDecl::InitDecl(Decl *d, Init* ini) : decl(d), init(ini) {}
		void InitDecl::print()
		{
			if (decl != NULL) decl->print();
			if (init != NULL) 
			{
				std::cerr << "=" << " ";
				init->print();
			}
		}
		void InitDecl::cgen()
		{
			if (decl != NULL) decl->cgen();
			if (init != NULL) init->cgen();
			
			std::string lhs_tag = "";
			std::string rhs_tag = "";
			if (init != NULL) 
			{
				if (decl != NULL)
				{
					decl->get_tag(lhs_tag);
				}
				init->get_tag(rhs_tag);
				if (!array_offset_mapping[lhs_tag])
				{
					genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[rhs_tag] << "($fp)" << std::endl;
					genout << "\tsw" << "\t$" << REG1 << "," << offset_mapping[lhs_tag] << "($fp)" << std::endl;
				}
			}
		}

		InitList::InitList(Init* i, InitList *il) : init(i), initlist(il) {}
		void InitList::print()
		{}
		void InitList::cgen()
		{
			if (init != NULL) 
			{
				std::string init_tag = "";
				init->cgen();
				init->get_tag(init_tag);
				//array_data << 0 << ",";
				genout << "\tlw" << "\t$" << REG1 << "," << offset_mapping[init_tag] << "($fp)" << std::endl;
				genout << "\tsw" << "\t$" << REG1 << "," << array_count * 4 << "($" << AREG << ")" << std::endl;
				array_count++;
			}
			if (initlist != NULL) initlist->cgen();
		}
		void InitList::get_tag(std::string& in_tag)
		{
			if (init != NULL) init->get_tag(in_tag);
			if (initlist != NULL) initlist->get_tag(in_tag);
		}

		Init::Init(InitList *idl, AssignExpr *ae) : initlist(idl), assignexpr(ae) {}
		void Init::print()
		{
			if (assignexpr != NULL) assignexpr->print();
			if (initlist != NULL) initlist->print();
		}
		void Init::cgen()
		{
			if (assignexpr != NULL)
			{
				assignexpr->cgen();
			}
			if (initlist != NULL)
			{
				initlist->cgen();
			}
		}
		void Init::get_tag(std::string& in_tag)
		{
			if (assignexpr != NULL) assignexpr->get_tag(in_tag);
			if (initlist != NULL) initlist->get_tag(in_tag);
		}

		Decl::Decl(Pointer *p, DeclType *_dt) : pointers(p), decltypes(_dt) {}
		void Decl::print()
		{
			if (pointers != NULL) pointers->print();
			if (decltypes != NULL) decltypes->print();
		}
		void Decl::cgen()
		{
			std::string dtag = "";
			if (decltypes != NULL) 
			{
				decltypes->cgen();
				decltypes->get_tag(dtag);
			}
			if (pointers != NULL) pointers->cgen();
			if (pointers != NULL)
			{
				pointer_mapping[dtag] = 1;
			}
		}
		std::string Decl::getID()
		{
			return decltypes->getID();
		}
		void Decl::get_tag(std::string& in_tag)
		{
			decltypes->get_tag(in_tag);
		}

		DeclType::DeclType(std::string _ID, DeclType *dt, ParamEllipsisList *pel, Decl* d, int e, Ternary *t, int arr) : ID(_ID), decltypes(dt), paramellipsislist(pel), decl(d), func(e), ternary(t), array(arr) 
		{
			//if (ID != "")
			//{
			//	tag = setOffset();
			//	tag_mapping[ID].resize(glbl_scope + 1);
			//	tag_mapping[ID][glbl_scope] = tag;
			//}
		}
		void DeclType::print()
		{
			if (debug) std::cerr << "DT" << std::endl;
			if (decltypes != NULL) decltypes->print();
			if (paramellipsislist != NULL)
			{
				std::cerr << "(" << " ";
				paramellipsislist->print();
				std::cerr << ")" << " ";
			}
			if (decl != NULL) decl->print();
			if (ID != "") std::cerr << ID << " ";
		}
		void DeclType::cgen()
		{
			if (paramellipsislist != NULL)
			{
				paramellipsislist->cgen();
			}

			if (ID != "")
			{
				tag = setOffset();
				tag_mapping[ID].resize(glbl_scope + 1);
				tag_mapping[ID][glbl_scope] = tag;
			}
			if (decltypes != NULL) decltypes->cgen();
			std::cerr << "\nTAG: " << tag << std::endl;
			std::cerr << "ID: " << ID << std::endl;

			if (array)
			{
				decltypes->set_array();
				if (ternary != NULL)
				{
					std::string decl_type_tag = "";
					int asize = 0;
					ternary->cgen();
					ternary->get_array_size(asize);
					decltypes->get_tag(decl_type_tag);
					
					array_data << std::endl;
					array_data << "array_data_" << decl_type_tag << ":" << "\t.word\t";
					for (int i = 0; i < asize - 1; i++)
					{
						array_data << "0,\t";
					}
					array_data << "0";
					genout << "\tla" << "\t$" << AREG << "," << "array_data_" << decl_type_tag << std::endl;
					genout << "\tsw" << "\t$" << AREG << "," << offset_mapping[decl_type_tag] << "($fp)" << std::endl;
				}
				if (ternary == NULL)
				{
					//std::string decl_type_tag = "";
					//decltypes->get_tag(decl_type_tag);
					
					//array_data << std::endl;
					//array_data << "array_data_" << decl_type_tag << ":" << "\t.word\t";
					//genout << "\tla" << "\t$" << AREG << "," << "array_data_" << decl_type_tag << std::endl;
					//genout << "\tsw" << "\t$" << AREG << "," << offset_mapping[decl_type_tag] << "($fp)" << std::endl;
				}
			}

		}
		void DeclType::set_array()
		{
			if (ID != "")
			{
				array_offset_mapping[tag] = 1;
			}
		}
		std::string DeclType::getID()
		{
			if (decltypes != NULL) return decltypes->getID();
			return ID;
		}
		void DeclType::get_tag(std::string& in_tag)
		{
			if (ID != "")
			{
				in_tag = tag;
			}
			else if ((decltypes != NULL) && (in_tag == ""))
			{
				decltypes->get_tag(in_tag);
			}
			else if ((decl != NULL) && (in_tag == ""))
			{
				decl->get_tag(in_tag);
			}
			else if (ternary != NULL)
			{
				ternary->get_tag(in_tag);
			}
		}

		DeclarationSet::DeclarationSet(Declaration* _d, DeclarationSet* _ds) : declaration(_d), declarationset(_ds) {}
		void DeclarationSet::print()
		{
			if (declarationset != NULL) declarationset->print();
			if (declaration != NULL) declaration->print();
		}
		void DeclarationSet::cgen()
		{
			if (declaration != NULL) declaration->cgen();
			if (declarationset != NULL) declarationset->cgen();
		}

		Declaration::Declaration(DeclSpec *ds, InitDeclList *idl) : declspec(ds), initdecllist(idl) {}
		void Declaration::print()
		{
			if (declspec != NULL) declspec->print();
			if (initdecllist != NULL) initdecllist->print();
			std::cerr << ";" << std::endl;
		}
		void Declaration::cgen()
		{
			if (initdecllist != NULL) 
			{
				initdecllist->cgen();
				array_count = 0;
			}
		}

		Pointer::Pointer(Pointer* point) : pointer(point) {};
		void Pointer::print() {};


		DeclSpec::DeclSpec(std::string _type) : type(_type) {}
		void DeclSpec::print()
		{
			if (debug) std::cerr << "DS" << std::endl;
			if (codegen)
			{
			}
			else std::cerr << type << " ";
		}
	}

%union{
    double doubleval;
	int intval;
	char charval;
	char* stringval;
	class Tree *tree;
	
	class File *fil;
	class Decl *dec;
	class InitList *initList;
	class InitDecl *initDecl;
	class InitDeclList *initDeclList;

	class ExternDecl *externDecl;
	class FuncDec *funcDec;
	class DeclarationSet *declarationSet;
	class Declaration *declarat;
	class DeclSpec *declSpec;	
	class DeclType *declType;
	
	class ParamEllipsisList *paramEllipsisList;
	class ParamList *paramList;
	class Pointer *point;
	class ParamDecl *paramDecl;
	class ArgList *argList;
	
	class Init *ini;
	class Expr *exp;
	class AssignExpr *assignExpr;
	class Ternary *ternar;
	class Factor *fact;
	class AddSub *addSub;
	class MultDivMod *multDivMod;
	class TypeCast *typeCast;
	class Unary *unar;
	class UnaryOp *unaryOp;
	class Postfix *postfi;
	class Prec *prec;

	class StateList *statementList;
	class State *state;
	class ColonStatement *colon;
	class ExprStatement *exprStatement;
	class Jump* jump;
	class Loop* loop;
	class Select* select;
	class Comp* comp;
}

%token <stringval>  TFLOAT TDOUBLE
%token <stringval> TCHAR
%token <stringval> TINT THEX TOCT 
%token <stringval> STR_LIT CHARAC
%token '+' '-' '/' '*' '%'
%token '(' ')' '{' '}' '[' ']'
%token ';' ',' '=' '.'
%token '|' '&' '^' '~' '!' '?' ':'
%token EQ NEQ ARROW_OP LSHIFT RSHIFT LT LTE GT GTE OR AND 
%token PLUSASS MINASS MULASS DIVASS MODASS LSHASS RSHASS ANDASS XORASS ORASS  
%token SIZEOF
%token RETURN GOTO BREAK CONTINUE
%token <stringval> ID

/* type keywords */
%token INT DOUBLE CHAR VOID FLOAT 
%token TYPEDEF ENUM EXTERN STRUCT VOLATILE UNION
%token AUTO CONST UNSIGNED SIGNED LONG SHORT REGISTER STATIC
%token DO WHILE FOR IF ELSE SWITCH CASE DEFAULT
%token ELLIPSIS
%token INC DEC
%token NEWLINE TAB SPACE

%type <fil> file 
/* in order to evaluate the expressions on decimal numbers
we need to include a field of type double in the C union holding the values
and to declare some of the symbols as represented by that field
*/

%type <dec> decl 
%type <initList> init_list
%type <initDecl> init_decl 
%type <initDeclList> init_decl_list 
%type <declarat> declaration 
%type <declarationSet> declaration_set 
%type <declType> decl_type
%type <externDecl> extern_decl 
%type <funcDec> func_dec 
%type <declSpec> decl_spec type_spec storage_class struct_union

%type <paramEllipsisList> param_elipsis_list
%type <paramList> param_list
%type <point> pointer
%type <paramDecl> param_decl
%type <argList> arg_list

%type <statementList> statement_list
%type <colon> colon_statement
%type <state> statement 
%type <comp> compound_statement
%type <loop> loop_statement 
%type <jump> jump_statement 
%type <select> select_statment

%type <ini> init 
%type <exp> expr 
%type <assignExpr> assign_expr 
%type <stringval> assign_op 
%type <ternar> ternary 
%type <fact> factor 
%type <typeCast> type_cast 
%type <prec> log_or log_and bit_or bit_xor bit_and equality relative lr_shift add_sub mult_div_mod
//%type <addSub> add_sub 
//%type <multDivMod> mult_div_mod
%type <unar> unary 
%type <stringval> unary_op 
%type <postfi> postfix 
%type <exprStatement> expr_statement

%%
 
root				: file { base = new Root($1); }
					;
file   				: extern_decl file { $$ = new File($1, $2); }
       				| extern_decl { $$ = new File($1, NULL); }
      				;
extern_decl			: func_dec { $$ = new ExternDecl($1); }
			  		| declaration { $$ = new ExternDecl(NULL, $1); }
					; 
func_dec			: decl_spec decl declaration_set compound_statement { $$ = new FuncDec($1, $2, $3, $4); }
		   			| decl_spec decl compound_statement { $$ = new FuncDec($1, $2, NULL, $3); } 
					| decl declaration_set compound_statement { $$ = new FuncDec(NULL, $1, $2, $3); }
					| decl compound_statement { $$ = new FuncDec(NULL, $1, NULL, $2); }
					;
compound_statement	: '{' '}' { $$ = new Comp(); } 
					| '{' declaration_set '}' { $$ = new Comp($2); }
					| '{' statement_list '}' { $$ = new Comp(NULL, $2); }
					| '{' declaration_set statement_list '}' { $$ = new Comp($2, $3); }
					;
statement_list		: statement { $$ = new StateList($1); } 
					| statement statement_list { $$ = new StateList($1, $2); }
					;
statement			: loop_statement { }
					| expr_statement { }
					| compound_statement { }
					| select_statment { }
					| jump_statement { }
					| colon_statement { }
					;
colon_statement		: ID ':' statement { $$ = new ColonStatement($3, NULL, $1); }
					| CASE ternary ':' statement { $$ = new ColonStatement($4, $2, "", 1); }
					| DEFAULT ':' statement { $$ = new ColonStatement($3, NULL, "", 0, 1); }
					;
jump_statement		: RETURN expr_statement { $$ = new Jump($2, "return"); } 
					| BREAK ';' { $$ = new Jump(NULL, "break"); }
					| CONTINUE ';' { $$ = new Jump(NULL, "continue"); }
					| GOTO ID ';' { $$ = new Jump(NULL, "goto", $2); }
					;
select_statment		: IF '(' expr ')' statement { $$ = new Select($3, $5, "if"); } 
				 	| IF '(' expr ')' statement ELSE statement { $$ = new Select($3, $5, "if", $7, "else"); }
					| SWITCH '(' expr ')' statement { $$ = new Select($3, $5, "switch"); }
				 	;
loop_statement		: WHILE '(' expr ')' statement { $$ = new Loop($3, $5, "while"); } 
					| DO statement WHILE '(' expr ')' ';' { $$ = new Loop($5, $2, "do", NULL, NULL, 1, "while");  } 
					| FOR '(' expr_statement expr_statement ')' statement { $$ = new Loop(NULL, $6, "for", $3, $4); }
					| FOR '(' expr_statement expr_statement expr ')' statement { $$ = new Loop($5, $7, "for", $3, $4); }
					;
expr_statement		: ';' { $$ = new ExprStatement();  }
					| expr ';' { $$ = new ExprStatement($1); }
					;
expr				: assign_expr { $$ = new Expr($1); } 
					| assign_expr ',' expr { $$ = new Expr($1, $3); }
					;
assign_expr			: ternary { $$ = new AssignExpr($1); }
			  		| unary assign_op assign_expr { $$ = new AssignExpr(NULL, $1, $2, $3); } 
			  		;
assign_op			: '=' { $$ = "="; }  
					| PLUSASS { $$ = "+="; }
					| MINASS { $$ = "-="; } 
					| MULASS { $$ = "*="; } 
					| DIVASS { $$ = "/="; } 
					| MODASS { $$ = "%="; } 
					| LSHASS { $$ = "<<="; } 
					| RSHASS { $$ = ">>="; } 
					| ANDASS { $$ = "&="; } 
					| XORASS { $$ = "^="; } 
					| ORASS { $$ = "|="; } 
					;
ternary				: log_or { $$ = new Ternary($1); }
		   			| log_or '?' expr ':' ternary { $$ = new Ternary($1, $3, $5); }
		   			;
log_or				: log_and { $$ = new Prec($1); } 
		  			| log_or OR log_and { $$ = new Prec($1, $3, "||"); }
					;
log_and				: bit_or { $$ = new Prec($1); } 
		   			| log_and AND bit_or { $$ = new Prec($1, $3, "&&"); }
					;
bit_or				: bit_xor { $$ = new Prec($1); }
		  			| bit_or '|' bit_xor { $$ = new Prec($1, $3, "|"); }
					;
bit_xor				: bit_and { $$ = new Prec($1); } 
		   			| bit_xor '^' bit_and { $$ = new Prec($1, $3, "^"); }
					;
bit_and				: equality { $$ = new Prec($1); } 
		   			| bit_and '&' equality { $$ = new Prec($1, $3, "&"); }
					;
equality			: relative { $$ = new Prec($1); } 
		   			| equality EQ relative { $$ = new Prec($1, $3, "=="); }
					| equality NEQ relative { $$ = new Prec($1, $3, "!="); }
					;
relative			: lr_shift { $$ = new Prec($1); } 
		   			| relative LT lr_shift { $$ = new Prec($1, $3, "<"); }
					| relative LTE lr_shift { $$ = new Prec($1, $3, "<="); }
					| relative GT lr_shift { $$ = new Prec($1, $3, ">"); }
					| relative GTE lr_shift { $$ = new Prec($1, $3, ">="); }
					;
lr_shift			: add_sub { $$ = new Prec($1); }
		   			| lr_shift RSHIFT add_sub { $$ = new Prec($1, $3, ">>"); } 
					| lr_shift LSHIFT add_sub { $$ = new Prec($1, $3, "<<"); } 
					;
add_sub				: mult_div_mod { $$ = new Prec(NULL, $1); } 
		   			| add_sub '+' mult_div_mod { $$ = new Prec($1, $3, "+"); }
					| add_sub '-' mult_div_mod { $$ = new Prec($1, $3, "-"); }
					;
mult_div_mod		: type_cast { $$ = new Prec(NULL, NULL, "", $1); }
			  		| mult_div_mod '*' type_cast { $$ = new Prec($1, NULL, "*", $3); }
					| mult_div_mod '/' type_cast { $$ = new Prec($1, NULL, "/", $3); }
					| mult_div_mod '%' type_cast { $$ = new Prec($1, NULL, "%", $3); }
					;
type_cast			: unary { $$ = new TypeCast($1); } 
					| '(' ')' type_cast { $$ = new TypeCast(NULL, $3); }
					;
unary_op			: '&' { $$ = "&"; } 
		   			| '*' { $$ = "*"; }
					| '+' { $$ = "+"; }
					| '-' { $$ = "-"; }
					| '~' { $$ = "~"; }
					| '!' { $$ = "!"; }
					;
unary				: postfix { $$ = new Unary($1); } 
		 			| INC unary { $$ = new Unary(NULL, $2, NULL, "", 1); }
					| DEC unary { $$ = new Unary(NULL, $2, NULL, "", 0, 1); }
					| unary_op type_cast { $$ = new Unary(NULL, NULL, $2, $1); }
					| SIZEOF unary { $$ = new Unary(NULL, $2, NULL, "", 0, 0, 1); }
					| SIZEOF '('  ')' { $$ = new Unary(NULL, NULL, NULL, "", 0, 0, 0, 1); }
					;
arg_list			: assign_expr { $$ = new ArgList($1); } 
		   			| assign_expr ',' arg_list { $$ = new ArgList($1, $3); }
					;
postfix				: factor { $$ = new Postfix($1); }
		   			| postfix INC { $$ = new Postfix(NULL, NULL, NULL, $1, "", "++"); }
					| postfix DEC { $$ = new Postfix(NULL, NULL, NULL, $1, "", "", "--"); }
					| postfix '[' expr ']' { $$ = new Postfix(NULL, $3, NULL, $1); }
					| postfix '(' ')'  { $$ = new Postfix(NULL, NULL, NULL, $1); }
					| postfix '(' arg_list ')' { $$ = new Postfix(NULL, NULL, $3, $1); }
					| postfix '.' ID  { $$ = new Postfix(NULL, NULL, NULL, $1, $3); }
					| postfix ARROW_OP ID { $$ = new Postfix(NULL, NULL, NULL, $1, $3); }
					;
factor 				: ID { $$ = new Factor($1, 0); } 
		   			| '(' expr ')' { $$ = new Factor("", 5, $2); } 
       				| TINT { $$ = new Factor($1, 1); }
					| TDOUBLE { $$ = new Factor($1, 7); } 
					| TFLOAT { $$ = new Factor($1, 7); } 
       				| TCHAR { $$ = new Factor($1, 4); } 
					| TOCT { $$ = new Factor($1, 2); } 
					| THEX { $$ = new Factor($1, 3); } 
					| STR_LIT { $$ = new Factor($1, 6); } 
					;
param_elipsis_list	: param_list { $$ = new ParamEllipsisList($1); }
			 		| param_list ',' ELLIPSIS { $$ = new ParamEllipsisList($1, "..."); }
					;
param_list			: param_decl { $$ = new ParamList($1); }
			 		| param_decl ',' param_list { $$ = new ParamList($1, $3); }
					;
param_decl			: decl_spec decl { $$ = new ParamDecl($1, $2); } 
			 		| decl_spec { $$ = new ParamDecl($1); }
					;
init_decl_list		: init_decl { $$ = new InitDeclList($1); }  
					| init_decl ',' init_decl_list { $$ = new InitDeclList($1, $3); }
					;
init_decl			: decl '=' init { $$ = new InitDecl($1, $3); } 
					| decl  { $$ = new InitDecl($1); }
					;
init_list 			: init { $$ = new InitList($1); }
			 		| init ',' init_list { $$ = new InitList($1, $3); }
					;
init				: assign_expr { $$ = new Init(NULL, $1); } 
					| '{' init_list '}' { $$ = new Init($2); } 
					| '{' init_list ',' '}' { $$ = new Init($2); }
					;
decl				: pointer decl_type { $$ = new Decl($1, $2); } 
					| decl_type { $$ = new Decl(NULL, $1); }
					;
decl_type			: ID { $$ = new DeclType($1); }
					| decl_type '(' param_elipsis_list ')' { $$ = new DeclType("", $1, $3, NULL, 1); }
					/*| decl_type '(' ID_list ')' 			*/
					| decl_type '(' ')' { $$ = new DeclType("", $1, NULL, NULL, 1); }
					| decl_type '[' ternary ']' { $$ = new DeclType("", $1, NULL, NULL, 0, $3, 1); }	
					| decl_type '['  ']' { $$ = new DeclType("", $1, NULL, NULL, 0, NULL, 1); }
					| '(' decl ')' 							
					;
declaration_set		: declaration declaration_set { $$ = new DeclarationSet($1, $2);  } 
					| declaration { $$ = new DeclarationSet($1); }
					;
declaration			: decl_spec  ';' { $$ = new Declaration($1); }
			  		| decl_spec init_decl_list ';' { $$ = new Declaration($1, $2); }
					;
pointer				: '*' { $$ = new Pointer(NULL); }
		   			| pointer '*' { $$ = new Pointer($1); } 
					;
decl_spec			: type_spec  
					| storage_class
					| struct_union
					;
type_spec			: INT { $$ = new DeclSpec("int"); } 
 		 			| DOUBLE {$$ = new DeclSpec("double"); } 
 					| CHAR {$$ = new DeclSpec("char"); } 
 					| FLOAT {$$ = new DeclSpec("float"); } 
 					| VOID {$$ = new DeclSpec("void"); } 
 					;
storage_class		: TYPEDEF {$$ = new DeclSpec("typedef"); } 
					| EXTERN {$$ = new DeclSpec("extern"); } 
			  		| ENUM {$$ = new DeclSpec("enu"); } 
					;
struct_union		: STRUCT {$$ = new DeclSpec("struct"); } 
 					| UNION {$$ = new DeclSpec("union"); } 
 					;



%%


int yyerror(const char* s){ 
    std::cerr << s << std::endl;
    return -1;
}

int main(void) {	

	if(yyparse())
	{
		std::cerr << " Syntax error " << std::endl;
		return 1;
	}
	
	debug = 0;
	
	base->print();
	base->cgen();
	tunit << ".data" << std::endl;
	tunit << array_data.str() << std::endl;
	std::cout << tunit.str() << std::endl;	
	ofile.close();
	

	return 0;
}
