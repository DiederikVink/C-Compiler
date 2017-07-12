%{
#include "c_parser.tab.h"

%}

%option noyywrap

SRC_FILE_1	#[ ][0-9]+[ ]

SRC_FILE_2	["]"/".*["] 

SRC_FILE_3	([ ][1])?([ ][2])?([ ][3])?([ ][4])?$

str_lit		["](\\.|[^\\"])*["]
charac		['](\\.|[^\\'])*[']

integer 	[0-9]+[uUlL]?[uUlL]?
oct			0[0-7]*[uUlL]?[uUlL]?
hex			0[x|X]([a-fA-F]|[0-9])+[uUlL]?[uUlL]?
float1		(([0-9]+[.][0-9]*|[0-9]*[.][0-9]+)([eE][+-]?[0-9]+)?([fFlL])?)	
float2		[0-9]+[eE][+-]?[0-9]+([fFlL])?

d			[0-9]
i			[_a-zA-Z]
h			[a-fA-F0-9]
o			[0-7]
e			[eE][+-]?{d}+
u			[uUlL]*
f			[fFlL]

id			[_a-zA-Z][_a-zA-Z0-9]*

NEWLINE		\n
TAB			(\t)*
SPACE		[  ]*

%%

"int"			{ return INT; }
"double"		{ return DOUBLE; }
"char"			{ return CHAR; }
"void"			{ return VOID; }
"float"			{ return FLOAT; }
"enum"			{ return ENUM; }
"extern"		{ return EXTERN; }
"struct"		{ return STRUCT; }
"volatile"		{ return VOLATILE; }
"union"			{ return UNION; }
"auto"			{ return AUTO; }
"const"			{ return CONST; }
"unsigned"		{ return UNSIGNED; }
"signed"		{ return SIGNED; }
"long"			{ return LONG; }
"short"			{ return SHORT; }
"register"		{ return REGISTER; }
"static"		{ return STATIC; }
"typedef"		{ return TYPEDEF; }
"return"		{ return RETURN; }
"break"			{ return BREAK; }
"continue"		{ return CONTINUE; }
"goto"			{ return GOTO; } 
"while"			{ return WHILE; }
"for"			{ return FOR; }
"if"			{ return IF; }
"else"			{ return ELSE; }
"do"			{ return DO; }
"switch"		{ return SWITCH; }
"case"			{ return CASE; }
"default"		{ return DEFAULT; }


{id}            		{ yylval.stringval = strdup(yytext); return ID; }

0[xX]({h})+({u})?		{ yylval.stringval = strdup(yytext); return THEX; }

0({o})+({u})?		{ yylval.stringval = strdup(yytext); return TOCT; }

({d})+({u})? 		{ yylval.stringval = strdup(yytext); return TINT; } 

({d})+({e})({f})?		{ yylval.stringval = strdup(yytext); return TFLOAT; }

({d})*"."({d})+({e})?({f})? { yylval.stringval = strdup(yytext); return TFLOAT; }

({d})+"."({d})*({e})?({f})? { yylval.stringval = strdup(yytext); return TFLOAT; }
				

{str_lit}		{ yylval.stringval = strdup(yytext); return STR_LIT; }
{charac}		{ yylval.stringval = strdup(yytext); return TCHAR; }			

";"             { return ';'; }
"..."			{ return ELLIPSIS; }
"=="			{ return EQ; }
"!="			{ return NEQ; }
"->"			{ return ARROW_OP; }
"<<="			{ return LSHASS; }
">>="			{ return RSHASS; }
"<<"			{ return LSHIFT; }
">>"			{ return RSHIFT; }
"<="			{ return LTE; }
">="			{ return GTE; }
"<"				{ return LT; }
">"				{ return GT; }
"||"			{ return OR; }
"&&"			{ return AND; }
"+="			{ return PLUSASS; }
"-="			{ return MINASS; }
"*="			{ return MULASS; }
"/="			{ return DIVASS; }
"%="			{ return MODASS; }
"^="			{ return XORASS; }
"&="			{ return ANDASS; }
"|="			{ return ORASS; }
"sizeof"		{ return SIZEOF; }
"++"			{ return INC; }
"--"			{ return DEC; }
"+"             { return '+'; }
"*"             { return '*'; }
"/"				{ return '/'; }
"%"				{ return '%'; }
"-"				{ return '-'; }
"["				{ return '['; }
"]"				{ return ']'; }
"("             { return '('; }
")"             { return ')'; }
"="				{ return '='; }
"{"				{ return '{'; }
"}"				{ return '}'; }
","				{ return ','; }
":"				{ return ':'; }
"|"				{ return '|'; }
"&"				{ return '&'; }
"."				{ return '.'; }
"~"				{ return '~'; }
"^"				{ return '^'; }
"?"				{ return '?'; }
"!"				{ return '!'; }

{NEWLINE}		{ }
{TAB}			{ }
{SPACE}			{ }
