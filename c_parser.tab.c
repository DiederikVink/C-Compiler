/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "c_parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c_parser.tab.h".  */
#ifndef YY_YY_C_PARSER_TAB_H_INCLUDED
# define YY_YY_C_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/c_parser.y" /* yacc.c:355  */

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
	


	

#line 114 "c_parser.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TFLOAT = 258,
    TDOUBLE = 259,
    TCHAR = 260,
    TINT = 261,
    THEX = 262,
    TOCT = 263,
    STR_LIT = 264,
    CHARAC = 265,
    EQ = 266,
    NEQ = 267,
    ARROW_OP = 268,
    LSHIFT = 269,
    RSHIFT = 270,
    LT = 271,
    LTE = 272,
    GT = 273,
    GTE = 274,
    OR = 275,
    AND = 276,
    PLUSASS = 277,
    MINASS = 278,
    MULASS = 279,
    DIVASS = 280,
    MODASS = 281,
    LSHASS = 282,
    RSHASS = 283,
    ANDASS = 284,
    XORASS = 285,
    ORASS = 286,
    SIZEOF = 287,
    RETURN = 288,
    GOTO = 289,
    BREAK = 290,
    CONTINUE = 291,
    ID = 292,
    INT = 293,
    DOUBLE = 294,
    CHAR = 295,
    VOID = 296,
    FLOAT = 297,
    TYPEDEF = 298,
    ENUM = 299,
    EXTERN = 300,
    STRUCT = 301,
    VOLATILE = 302,
    UNION = 303,
    AUTO = 304,
    CONST = 305,
    UNSIGNED = 306,
    SIGNED = 307,
    LONG = 308,
    SHORT = 309,
    REGISTER = 310,
    STATIC = 311,
    DO = 312,
    WHILE = 313,
    FOR = 314,
    IF = 315,
    ELSE = 316,
    SWITCH = 317,
    CASE = 318,
    DEFAULT = 319,
    ELLIPSIS = 320,
    INC = 321,
    DEC = 322,
    NEWLINE = 323,
    TAB = 324,
    SPACE = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 2210 "src/c_parser.y" /* yacc.c:355  */

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

#line 246 "c_parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "c_parser.tab.c" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 17 "src/c_parser.y" /* yacc.c:359  */

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
	

#line 2459 "c_parser.tab.c" /* yacc.c:359  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   781

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    15,    27,     2,
      16,    17,    14,    11,    23,    12,    25,    13,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    22,
       2,    24,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,    26,    19,    29,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  2330,  2330,  2332,  2333,  2335,  2336,  2338,  2339,  2340,
    2341,  2343,  2344,  2345,  2346,  2348,  2349,  2351,  2352,  2353,
    2354,  2355,  2356,  2358,  2359,  2360,  2362,  2363,  2364,  2365,
    2367,  2368,  2369,  2371,  2372,  2373,  2374,  2376,  2377,  2379,
    2380,  2382,  2383,  2385,  2386,  2387,  2388,  2389,  2390,  2391,
    2392,  2393,  2394,  2395,  2397,  2398,  2400,  2401,  2403,  2404,
    2406,  2407,  2409,  2410,  2412,  2413,  2415,  2416,  2417,  2419,
    2420,  2421,  2422,  2423,  2425,  2426,  2427,  2429,  2430,  2431,
    2433,  2434,  2435,  2436,  2438,  2439,  2441,  2442,  2443,  2444,
    2445,  2446,  2448,  2449,  2450,  2451,  2452,  2453,  2455,  2456,
    2458,  2459,  2460,  2461,  2462,  2463,  2464,  2465,  2467,  2468,
    2469,  2470,  2471,  2472,  2473,  2474,  2475,  2477,  2478,  2480,
    2481,  2483,  2484,  2486,  2487,  2489,  2490,  2492,  2493,  2495,
    2496,  2497,  2499,  2500,  2502,  2503,  2505,  2506,  2507,  2508,
    2510,  2511,  2513,  2514,  2516,  2517,  2519,  2520,  2521,  2523,
    2524,  2525,  2526,  2527,  2529,  2530,  2531,  2533,  2534
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TFLOAT", "TDOUBLE", "TCHAR", "TINT",
  "THEX", "TOCT", "STR_LIT", "CHARAC", "'+'", "'-'", "'/'", "'*'", "'%'",
  "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", "'='", "'.'",
  "'|'", "'&'", "'^'", "'~'", "'!'", "'?'", "':'", "EQ", "NEQ", "ARROW_OP",
  "LSHIFT", "RSHIFT", "LT", "LTE", "GT", "GTE", "OR", "AND", "PLUSASS",
  "MINASS", "MULASS", "DIVASS", "MODASS", "LSHASS", "RSHASS", "ANDASS",
  "XORASS", "ORASS", "SIZEOF", "RETURN", "GOTO", "BREAK", "CONTINUE", "ID",
  "INT", "DOUBLE", "CHAR", "VOID", "FLOAT", "TYPEDEF", "ENUM", "EXTERN",
  "STRUCT", "VOLATILE", "UNION", "AUTO", "CONST", "UNSIGNED", "SIGNED",
  "LONG", "SHORT", "REGISTER", "STATIC", "DO", "WHILE", "FOR", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "ELLIPSIS", "INC", "DEC", "NEWLINE",
  "TAB", "SPACE", "$accept", "root", "file", "extern_decl", "func_dec",
  "compound_statement", "statement_list", "statement", "colon_statement",
  "jump_statement", "select_statment", "loop_statement", "expr_statement",
  "expr", "assign_expr", "assign_op", "ternary", "log_or", "log_and",
  "bit_or", "bit_xor", "bit_and", "equality", "relative", "lr_shift",
  "add_sub", "mult_div_mod", "type_cast", "unary_op", "unary", "arg_list",
  "postfix", "factor", "param_elipsis_list", "param_list", "param_decl",
  "init_decl_list", "init_decl", "init_list", "init", "decl", "decl_type",
  "declaration_set", "declaration", "pointer", "decl_spec", "type_spec",
  "storage_class", "struct_union", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    43,    45,    47,    42,    37,    40,    41,   123,   125,
      91,    93,    59,    44,    61,    46,   124,    38,    94,   126,
      33,    63,    58,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     177,  -108,    -1,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,    20,  -108,   177,  -108,   294,     9,
    -108,     0,    -5,  -108,  -108,  -108,    16,  -108,  -108,   205,
    -108,    21,   383,    -5,   188,   140,  -108,     9,  -108,    38,
      22,   264,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,   412,  -108,  -108,  -108,  -108,  -108,   628,
     469,    -6,    40,    42,    15,   379,    53,    62,    68,    74,
     661,    69,   692,   692,  -108,   107,   379,  -108,  -108,  -108,
    -108,  -108,   106,   108,  -108,   -12,    86,   104,   109,   105,
      23,    48,    31,    65,    36,  -108,   661,   291,     7,  -108,
     292,  -108,  -108,   110,  -108,   119,   116,   127,    -1,  -108,
    -108,   121,  -108,  -108,    -1,   500,  -108,    21,   661,   136,
     533,  -108,  -108,   133,  -108,  -108,   379,    77,   661,   469,
     661,   661,   126,   379,   661,  -108,  -108,  -108,  -108,  -108,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,   661,   564,   661,   100,   101,  -108,  -108,  -108,
     143,  -108,    76,   383,  -108,  -108,  -108,   500,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,   148,   149,   469,   151,
     154,   379,  -108,  -108,   142,    86,   104,   109,   105,    23,
      48,    48,    31,    31,    31,    31,    65,    65,    36,    36,
    -108,  -108,  -108,  -108,  -108,   155,   160,   144,  -108,  -108,
    -108,  -108,  -108,    25,   156,   661,   379,   597,   379,   379,
    -108,   661,   661,  -108,  -108,  -108,   153,   500,   163,  -108,
     379,   164,    99,  -108,  -108,  -108,  -108,  -108,   161,  -108,
     379,   379,  -108,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   144,     0,   134,   149,   150,   151,   153,   152,   154,
     156,   155,   157,   158,     0,     2,     4,     5,     0,   133,
       6,     0,     0,   146,   147,   148,     0,     1,     3,     0,
      10,     0,   141,     0,     0,     0,   145,   132,   142,     0,
     123,   126,   139,   112,   111,   113,   110,   115,   114,   116,
      88,    89,    87,     0,    11,    37,    86,    90,    91,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,    15,    22,    21,    20,
      17,    18,     0,    39,    41,    54,    56,    58,    60,    62,
      64,    66,    69,    74,    77,    80,     0,    84,    92,   100,
       0,     9,   140,   126,   136,     0,   117,   119,   122,   138,
     108,     0,    84,   143,     0,     0,     8,     0,     0,     0,
       0,    96,    26,     0,    27,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    13,    16,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,   101,   102,    12,
       0,   135,     0,     0,   121,   137,   124,     0,   129,   125,
       7,    85,   109,    97,    29,    23,     0,     0,     0,     0,
       0,     0,    25,    40,     0,    57,    59,    61,    63,    65,
      67,    68,    70,    71,    72,    73,    76,    75,    78,    79,
      82,    81,    83,    42,   104,    98,     0,     0,   106,   107,
      14,   118,   120,     0,   127,     0,     0,     0,     0,     0,
      24,     0,     0,   105,   103,   130,     0,     0,     0,    33,
       0,     0,    30,    32,    55,    99,   131,   128,     0,    35,
       0,     0,    34,    36,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   168,  -108,  -108,   -13,   -69,   -63,  -108,  -108,
    -108,  -108,   -57,   -49,  -107,  -108,   -34,  -108,    43,    47,
      51,    55,    46,   -54,   -52,   -51,   -50,   -84,  -108,   -35,
     -46,  -108,  -108,  -108,    18,  -108,    88,  -108,   -44,    89,
      19,   194,    14,    10,  -108,     6,  -108,  -108,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   172,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     226,    98,    99,   105,   106,   107,    39,    40,   233,   234,
      18,    19,    31,    32,    21,    33,    23,    24,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     112,   111,   127,   122,   119,    30,    22,   138,   188,     1,
      20,     2,   160,     1,    36,     2,     2,    38,   101,   141,
      27,    26,    22,   173,   121,    34,    20,   174,   116,    35,
     142,   180,   175,    42,   191,   112,   132,   135,   136,    29,
     108,    41,   176,   100,   245,   114,   102,   126,   246,   157,
     158,   159,   103,   123,     3,   117,   147,   148,     3,     3,
     113,   112,   124,   195,   125,   223,   225,   153,   154,   128,
     202,   119,   198,   220,   221,   222,   155,   156,   129,   197,
     188,   199,   200,   112,   130,   119,   149,   150,   151,   152,
     131,   203,   204,   210,   211,   177,   178,   212,   213,   214,
     215,   133,   216,   217,   190,   218,   219,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   227,   137,   184,   139,   143,
     144,   140,   146,   103,   115,   225,   181,   145,   240,   182,
     188,   237,   185,    43,    44,    45,    46,    47,    48,    49,
     183,    50,    51,   192,    52,   194,    53,   196,   201,   228,
     229,   109,   230,   231,   235,   244,   236,    56,   238,    57,
      58,   239,   256,   249,   241,   252,   253,   243,   242,   247,
     258,   260,   261,   262,    28,   205,   248,   259,   251,   108,
     206,     1,   209,     2,    59,   207,   255,   263,   264,   110,
     208,   232,   186,   257,   189,   104,   112,   254,    43,    44,
      45,    46,    47,    48,    49,    37,    50,    51,     0,    52,
       0,    53,     0,    29,    54,     0,     0,    55,    72,    73,
       0,     0,    56,     0,    57,    58,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,    59,
      60,    61,    62,    63,    64,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,     0,     0,
       0,     0,    29,     0,    65,    66,    67,    68,   115,    69,
      70,    71,     0,    72,    73,    43,    44,    45,    46,    47,
      48,    49,     0,    50,    51,     0,    52,     0,    53,     0,
      29,   179,    29,     0,    55,   161,     0,     0,     0,    56,
       0,    57,    58,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,    59,    60,    61,    62,
      63,    64,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,     0,    69,    70,    71,     0,
      72,    73,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,     0,    52,     0,    53,     0,    29,     0,     0,
       0,    55,     0,     0,     0,     0,    56,     0,    57,    58,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,     0,    50,    51,     0,    52,     0,    53,   118,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    56,
       0,    57,    58,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,     0,     0,    65,    66,
      67,    68,     0,    69,    70,    71,    59,    72,    73,     0,
       0,   110,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,     0,    52,     0,    53,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,    56,     0,    57,    58,
      72,    73,     0,    43,    44,    45,    46,    47,    48,    49,
       0,    50,    51,     0,    52,     0,    53,     0,   187,     0,
       0,     0,     0,    59,     0,     0,     0,    56,   110,    57,
      58,     0,     0,     0,     0,     0,    43,    44,    45,    46,
      47,    48,    49,     0,    50,    51,     0,    52,     0,    53,
     193,     0,     0,     0,    59,     0,     0,    72,    73,   110,
      56,     0,    57,    58,     0,     0,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,     0,    52,     0,
      53,   224,     0,     0,     0,     0,     0,    59,    72,    73,
       0,    56,   110,    57,    58,     0,     0,     0,     0,     0,
      43,    44,    45,    46,    47,    48,    49,     0,    50,    51,
       0,    52,     0,    53,   250,     0,     0,     0,    59,     0,
       0,    72,    73,   110,    56,     0,    57,    58,     0,     0,
       0,    43,    44,    45,    46,    47,    48,    49,     0,    50,
      51,     0,    52,     0,   120,     0,     0,     0,     0,     0,
       0,    59,    72,    73,     0,    56,   110,    57,    58,     0,
       0,     0,     0,     0,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,     0,    52,     0,    53,     0,     0,
       0,     0,    59,     0,     0,    72,    73,   110,    56,     0,
      57,    58,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,     0,    50,    51,     0,    52,     0,   134,     0,
       0,     0,     0,     0,     0,    59,    72,    73,     0,    56,
     110,    57,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,     0,    72,
      73,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73
};

static const yytype_int16 yycheck[] =
{
      35,    35,    65,    60,    53,    18,     0,    76,   115,    14,
       0,    16,    96,    14,    14,    16,    16,    22,    31,    31,
       0,     2,    16,    16,    59,    16,    16,    20,    41,    20,
      42,   100,    25,    17,   118,    70,    70,    72,    73,    18,
      34,    22,    35,    29,    19,    23,    32,    32,    23,    13,
      14,    15,    33,    59,    59,    41,    33,    34,    59,    59,
      22,    96,    22,   126,    22,   172,   173,    36,    37,    16,
     133,   120,   129,   157,   158,   159,    11,    12,    16,   128,
     187,   130,   131,   118,    16,   134,    38,    39,    40,    41,
      16,   140,   141,   147,   148,    88,    89,   149,   150,   151,
     152,    32,   153,   154,   117,   155,   156,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   174,    19,   108,    22,    43,
      26,    23,    27,   114,    24,   242,    17,    28,   201,    23,
     247,   198,    21,     3,     4,     5,     6,     7,     8,     9,
      23,    11,    12,    17,    14,    22,    16,    80,    32,    59,
      59,    21,    19,    87,    16,    21,    17,    27,    17,    29,
      30,    17,    19,   236,    32,   238,   239,    17,    23,    23,
      17,    17,    83,    22,    16,   142,   235,   250,   237,   183,
     143,    14,   146,    16,    54,   144,   242,   260,   261,    59,
     145,   183,   114,   247,   115,    17,   241,   241,     3,     4,
       5,     6,     7,     8,     9,    21,    11,    12,    -1,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    22,    88,    89,
      -1,    -1,    27,    -1,    29,    30,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    79,    80,    81,    82,    24,    84,
      85,    86,    -1,    88,    89,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    -1,    16,    -1,
      18,    19,    18,    -1,    22,    24,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    54,    55,    56,    57,
      58,    59,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    80,    81,    82,    -1,    84,    85,    86,    -1,
      88,    89,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    14,    -1,    16,    -1,    18,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    -1,    16,    17,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    27,
      -1,    29,    30,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    -1,    -1,    -1,    79,    80,
      81,    82,    -1,    84,    85,    86,    54,    88,    89,    -1,
      -1,    59,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    29,    30,
      88,    89,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    14,    -1,    16,    -1,    18,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    27,    59,    29,
      30,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    -1,    16,
      17,    -1,    -1,    -1,    54,    -1,    -1,    88,    89,    59,
      27,    -1,    29,    30,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    14,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    54,    88,    89,
      -1,    27,    59,    29,    30,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    14,    -1,    16,    17,    -1,    -1,    -1,    54,    -1,
      -1,    88,    89,    59,    27,    -1,    29,    30,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    88,    89,    -1,    27,    59,    29,    30,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    14,    -1,    16,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    88,    89,    59,    27,    -1,
      29,    30,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    88,    89,    -1,    27,
      59,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    88,
      89,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    16,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    70,    94,    95,    96,    97,   133,   134,
     136,   137,   138,   139,   140,   141,   133,     0,    95,    18,
      98,   135,   136,   138,    16,    20,    14,   134,    22,   129,
     130,   133,    17,     3,     4,     5,     6,     7,     8,     9,
      11,    12,    14,    16,    19,    22,    27,    29,    30,    54,
      55,    56,    57,    58,    59,    79,    80,    81,    82,    84,
      85,    86,    88,    89,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   124,   125,
     135,    98,   135,   133,    17,   126,   127,   128,   138,    21,
      59,   109,   122,    22,    23,    24,    98,   135,    17,   106,
      16,   122,   105,    59,    22,    22,    32,   100,    16,    16,
      16,    16,   109,    32,    16,   122,   122,    19,    99,    22,
      23,    31,    42,    43,    26,    28,    27,    33,    34,    38,
      39,    40,    41,    36,    37,    11,    12,    13,    14,    15,
     120,    24,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   108,    16,    20,    25,    35,    88,    89,    19,
      99,    17,    23,    23,   133,    21,   129,    18,   107,   132,
      98,   120,    17,    17,    22,   100,    80,   106,   105,   106,
     106,    32,   100,   106,   106,   111,   112,   113,   114,   115,
     116,   116,   117,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   120,   107,    17,   107,   123,   106,    59,    59,
      19,    87,   127,   131,   132,    16,    17,   105,    17,    17,
     100,    32,    23,    17,    21,    19,    23,    23,   106,   100,
      17,   106,   100,   100,   109,   123,    19,   131,    17,   100,
      17,    83,    22,   100,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   101,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   115,   116,
     116,   116,   116,   116,   117,   117,   117,   118,   118,   118,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   122,   122,   122,   122,   122,   122,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   139,   139,   139,   140,   140,   140,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     3,     3,
       2,     2,     3,     3,     4,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     2,     2,     3,
       5,     7,     5,     5,     7,     6,     7,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     1,     3,
       1,     2,     2,     4,     3,     4,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     2,     1,     1,     3,     3,     1,     1,     3,     1,
       3,     4,     2,     1,     1,     4,     3,     4,     3,     3,
       2,     1,     2,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 2330 "src/c_parser.y" /* yacc.c:1661  */
    { base = new Root((yyvsp[0].fil)); }
#line 3846 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 2332 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fil) = new File((yyvsp[-1].externDecl), (yyvsp[0].fil)); }
#line 3852 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 2333 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fil) = new File((yyvsp[0].externDecl), NULL); }
#line 3858 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 2335 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.externDecl) = new ExternDecl((yyvsp[0].funcDec)); }
#line 3864 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 2336 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.externDecl) = new ExternDecl(NULL, (yyvsp[0].declarat)); }
#line 3870 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 2338 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.funcDec) = new FuncDec((yyvsp[-3].declSpec), (yyvsp[-2].dec), (yyvsp[-1].declarationSet), (yyvsp[0].comp)); }
#line 3876 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 2339 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.funcDec) = new FuncDec((yyvsp[-2].declSpec), (yyvsp[-1].dec), NULL, (yyvsp[0].comp)); }
#line 3882 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 2340 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.funcDec) = new FuncDec(NULL, (yyvsp[-2].dec), (yyvsp[-1].declarationSet), (yyvsp[0].comp)); }
#line 3888 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 2341 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.funcDec) = new FuncDec(NULL, (yyvsp[-1].dec), NULL, (yyvsp[0].comp)); }
#line 3894 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 2343 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.comp) = new Comp(); }
#line 3900 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 2344 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.comp) = new Comp((yyvsp[-1].declarationSet)); }
#line 3906 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 2345 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.comp) = new Comp(NULL, (yyvsp[-1].statementList)); }
#line 3912 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 2346 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.comp) = new Comp((yyvsp[-2].declarationSet), (yyvsp[-1].statementList)); }
#line 3918 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 2348 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.statementList) = new StateList((yyvsp[0].state)); }
#line 3924 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 2349 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.statementList) = new StateList((yyvsp[-1].state), (yyvsp[0].statementList)); }
#line 3930 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 2351 "src/c_parser.y" /* yacc.c:1661  */
    { }
#line 3936 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 2352 "src/c_parser.y" /* yacc.c:1661  */
    { }
#line 3942 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 2353 "src/c_parser.y" /* yacc.c:1661  */
    { }
#line 3948 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 2354 "src/c_parser.y" /* yacc.c:1661  */
    { }
#line 3954 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 2355 "src/c_parser.y" /* yacc.c:1661  */
    { }
#line 3960 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 2356 "src/c_parser.y" /* yacc.c:1661  */
    { }
#line 3966 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 2358 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.colon) = new ColonStatement((yyvsp[0].state), NULL, (yyvsp[-2].stringval)); }
#line 3972 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 2359 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.colon) = new ColonStatement((yyvsp[0].state), (yyvsp[-2].ternar), "", 1); }
#line 3978 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 2360 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.colon) = new ColonStatement((yyvsp[0].state), NULL, "", 0, 1); }
#line 3984 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 2362 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.jump) = new Jump((yyvsp[0].exprStatement), "return"); }
#line 3990 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 2363 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.jump) = new Jump(NULL, "break"); }
#line 3996 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 2364 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.jump) = new Jump(NULL, "continue"); }
#line 4002 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 2365 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.jump) = new Jump(NULL, "goto", (yyvsp[-1].stringval)); }
#line 4008 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 2367 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.select) = new Select((yyvsp[-2].exp), (yyvsp[0].state), "if"); }
#line 4014 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 2368 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.select) = new Select((yyvsp[-4].exp), (yyvsp[-2].state), "if", (yyvsp[0].state), "else"); }
#line 4020 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 2369 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.select) = new Select((yyvsp[-2].exp), (yyvsp[0].state), "switch"); }
#line 4026 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 2371 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.loop) = new Loop((yyvsp[-2].exp), (yyvsp[0].state), "while"); }
#line 4032 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 2372 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.loop) = new Loop((yyvsp[-2].exp), (yyvsp[-5].state), "do", NULL, NULL, 1, "while");  }
#line 4038 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 2373 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.loop) = new Loop(NULL, (yyvsp[0].state), "for", (yyvsp[-3].exprStatement), (yyvsp[-2].exprStatement)); }
#line 4044 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 2374 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.loop) = new Loop((yyvsp[-2].exp), (yyvsp[0].state), "for", (yyvsp[-4].exprStatement), (yyvsp[-3].exprStatement)); }
#line 4050 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 2376 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.exprStatement) = new ExprStatement();  }
#line 4056 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 2377 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.exprStatement) = new ExprStatement((yyvsp[-1].exp)); }
#line 4062 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 2379 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.exp) = new Expr((yyvsp[0].assignExpr)); }
#line 4068 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 2380 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.exp) = new Expr((yyvsp[-2].assignExpr), (yyvsp[0].exp)); }
#line 4074 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 2382 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.assignExpr) = new AssignExpr((yyvsp[0].ternar)); }
#line 4080 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 2383 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.assignExpr) = new AssignExpr(NULL, (yyvsp[-2].unar), (yyvsp[-1].stringval), (yyvsp[0].assignExpr)); }
#line 4086 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 2385 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "="; }
#line 4092 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 2386 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "+="; }
#line 4098 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 2387 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "-="; }
#line 4104 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 2388 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "*="; }
#line 4110 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 2389 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "/="; }
#line 4116 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 2390 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "%="; }
#line 4122 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 2391 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "<<="; }
#line 4128 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 2392 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = ">>="; }
#line 4134 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 2393 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "&="; }
#line 4140 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 2394 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "^="; }
#line 4146 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 2395 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "|="; }
#line 4152 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 2397 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.ternar) = new Ternary((yyvsp[0].prec)); }
#line 4158 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 2398 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.ternar) = new Ternary((yyvsp[-4].prec), (yyvsp[-2].exp), (yyvsp[0].ternar)); }
#line 4164 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 2400 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4170 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 2401 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "||"); }
#line 4176 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 2403 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4182 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 2404 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "&&"); }
#line 4188 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 2406 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4194 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 2407 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "|"); }
#line 4200 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 2409 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4206 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 2410 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "^"); }
#line 4212 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 2412 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4218 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 2413 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "&"); }
#line 4224 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 2415 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4230 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 2416 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "=="); }
#line 4236 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 2417 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "!="); }
#line 4242 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 2419 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4248 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 2420 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "<"); }
#line 4254 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 2421 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "<="); }
#line 4260 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 2422 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), ">"); }
#line 4266 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 2423 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), ">="); }
#line 4272 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 2425 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[0].prec)); }
#line 4278 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 2426 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), ">>"); }
#line 4284 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 2427 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "<<"); }
#line 4290 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 2429 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec(NULL, (yyvsp[0].prec)); }
#line 4296 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 2430 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "+"); }
#line 4302 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 2431 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), (yyvsp[0].prec), "-"); }
#line 4308 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 2433 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec(NULL, NULL, "", (yyvsp[0].typeCast)); }
#line 4314 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 2434 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), NULL, "*", (yyvsp[0].typeCast)); }
#line 4320 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 2435 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), NULL, "/", (yyvsp[0].typeCast)); }
#line 4326 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 2436 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.prec) = new Prec((yyvsp[-2].prec), NULL, "%", (yyvsp[0].typeCast)); }
#line 4332 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 2438 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.typeCast) = new TypeCast((yyvsp[0].unar)); }
#line 4338 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 2439 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.typeCast) = new TypeCast(NULL, (yyvsp[0].typeCast)); }
#line 4344 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 2441 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "&"; }
#line 4350 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 2442 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "*"; }
#line 4356 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 2443 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "+"; }
#line 4362 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 2444 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "-"; }
#line 4368 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 2445 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "~"; }
#line 4374 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 2446 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.stringval) = "!"; }
#line 4380 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 2448 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.unar) = new Unary((yyvsp[0].postfi)); }
#line 4386 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 2449 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.unar) = new Unary(NULL, (yyvsp[0].unar), NULL, "", 1); }
#line 4392 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 2450 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.unar) = new Unary(NULL, (yyvsp[0].unar), NULL, "", 0, 1); }
#line 4398 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 2451 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.unar) = new Unary(NULL, NULL, (yyvsp[0].typeCast), (yyvsp[-1].stringval)); }
#line 4404 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 2452 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.unar) = new Unary(NULL, (yyvsp[0].unar), NULL, "", 0, 0, 1); }
#line 4410 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 2453 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.unar) = new Unary(NULL, NULL, NULL, "", 0, 0, 0, 1); }
#line 4416 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 2455 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.argList) = new ArgList((yyvsp[0].assignExpr)); }
#line 4422 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 2456 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.argList) = new ArgList((yyvsp[-2].assignExpr), (yyvsp[0].argList)); }
#line 4428 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 2458 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix((yyvsp[0].fact)); }
#line 4434 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 2459 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix(NULL, NULL, NULL, (yyvsp[-1].postfi), "", "++"); }
#line 4440 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 2460 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix(NULL, NULL, NULL, (yyvsp[-1].postfi), "", "", "--"); }
#line 4446 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 2461 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix(NULL, (yyvsp[-1].exp), NULL, (yyvsp[-3].postfi)); }
#line 4452 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 2462 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix(NULL, NULL, NULL, (yyvsp[-2].postfi)); }
#line 4458 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 2463 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix(NULL, NULL, (yyvsp[-1].argList), (yyvsp[-3].postfi)); }
#line 4464 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 2464 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix(NULL, NULL, NULL, (yyvsp[-2].postfi), (yyvsp[0].stringval)); }
#line 4470 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 2465 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.postfi) = new Postfix(NULL, NULL, NULL, (yyvsp[-2].postfi), (yyvsp[0].stringval)); }
#line 4476 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 2467 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 0); }
#line 4482 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 2468 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor("", 5, (yyvsp[-1].exp)); }
#line 4488 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 2469 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 1); }
#line 4494 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 2470 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 7); }
#line 4500 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 2471 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 7); }
#line 4506 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 2472 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 4); }
#line 4512 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 2473 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 2); }
#line 4518 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 2474 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 3); }
#line 4524 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 2475 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.fact) = new Factor((yyvsp[0].stringval), 6); }
#line 4530 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 2477 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.paramEllipsisList) = new ParamEllipsisList((yyvsp[0].paramList)); }
#line 4536 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 2478 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.paramEllipsisList) = new ParamEllipsisList((yyvsp[-2].paramList), "..."); }
#line 4542 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 2480 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.paramList) = new ParamList((yyvsp[0].paramDecl)); }
#line 4548 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 2481 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.paramList) = new ParamList((yyvsp[-2].paramDecl), (yyvsp[0].paramList)); }
#line 4554 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 2483 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.paramDecl) = new ParamDecl((yyvsp[-1].declSpec), (yyvsp[0].dec)); }
#line 4560 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 2484 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.paramDecl) = new ParamDecl((yyvsp[0].declSpec)); }
#line 4566 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 2486 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.initDeclList) = new InitDeclList((yyvsp[0].initDecl)); }
#line 4572 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 2487 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.initDeclList) = new InitDeclList((yyvsp[-2].initDecl), (yyvsp[0].initDeclList)); }
#line 4578 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 2489 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.initDecl) = new InitDecl((yyvsp[-2].dec), (yyvsp[0].ini)); }
#line 4584 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 2490 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.initDecl) = new InitDecl((yyvsp[0].dec)); }
#line 4590 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 2492 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.initList) = new InitList((yyvsp[0].ini)); }
#line 4596 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 2493 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.initList) = new InitList((yyvsp[-2].ini), (yyvsp[0].initList)); }
#line 4602 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 2495 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.ini) = new Init(NULL, (yyvsp[0].assignExpr)); }
#line 4608 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 2496 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.ini) = new Init((yyvsp[-1].initList)); }
#line 4614 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 2497 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.ini) = new Init((yyvsp[-2].initList)); }
#line 4620 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 2499 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.dec) = new Decl((yyvsp[-1].point), (yyvsp[0].declType)); }
#line 4626 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 2500 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.dec) = new Decl(NULL, (yyvsp[0].declType)); }
#line 4632 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 2502 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declType) = new DeclType((yyvsp[0].stringval)); }
#line 4638 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 2503 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declType) = new DeclType("", (yyvsp[-3].declType), (yyvsp[-1].paramEllipsisList), NULL, 1); }
#line 4644 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 2505 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declType) = new DeclType("", (yyvsp[-2].declType), NULL, NULL, 1); }
#line 4650 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 2506 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declType) = new DeclType("", (yyvsp[-3].declType), NULL, NULL, 0, (yyvsp[-1].ternar), 1); }
#line 4656 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 2507 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declType) = new DeclType("", (yyvsp[-2].declType), NULL, NULL, 0, NULL, 1); }
#line 4662 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 2510 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declarationSet) = new DeclarationSet((yyvsp[-1].declarat), (yyvsp[0].declarationSet));  }
#line 4668 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 2511 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declarationSet) = new DeclarationSet((yyvsp[0].declarat)); }
#line 4674 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 2513 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declarat) = new Declaration((yyvsp[-1].declSpec)); }
#line 4680 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 2514 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declarat) = new Declaration((yyvsp[-2].declSpec), (yyvsp[-1].initDeclList)); }
#line 4686 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 2516 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.point) = new Pointer(NULL); }
#line 4692 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 2517 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.point) = new Pointer((yyvsp[-1].point)); }
#line 4698 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 2523 "src/c_parser.y" /* yacc.c:1661  */
    { (yyval.declSpec) = new DeclSpec("int"); }
#line 4704 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 2524 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("double"); }
#line 4710 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 2525 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("char"); }
#line 4716 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 2526 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("float"); }
#line 4722 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 2527 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("void"); }
#line 4728 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 2529 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("typedef"); }
#line 4734 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 2530 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("extern"); }
#line 4740 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 2531 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("enu"); }
#line 4746 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 2533 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("struct"); }
#line 4752 "c_parser.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 2534 "src/c_parser.y" /* yacc.c:1661  */
    {(yyval.declSpec) = new DeclSpec("union"); }
#line 4758 "c_parser.tab.c" /* yacc.c:1661  */
    break;


#line 4762 "c_parser.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2539 "src/c_parser.y" /* yacc.c:1906  */



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
