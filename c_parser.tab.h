/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 1 "src/c_parser.y" /* yacc.c:1915  */

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
	


	

#line 61 "c_parser.tab.h" /* yacc.c:1915  */

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
#line 2210 "src/c_parser.y" /* yacc.c:1915  */

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

#line 193 "c_parser.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_PARSER_TAB_H_INCLUDED  */
