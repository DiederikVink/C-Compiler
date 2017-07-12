#ifndef C_PARSER_H
#define C_PARSER_H

class Tree;
class Root;
class File;
class ExternDecl;
class FuncDec;
class Comp;
class StateList;
class State;
class Jump;
class Select;
class Loop;
class ExprStatement;
class Expr;
class AssignExpr;
class AssignOp;
class Ternary;
class LogOr;
class LogAnd;
class BitOr;
class BitXor;
class BitAnd;
class Equality;
class Relative;
class LRShift;
class AddSub;
class MultDivMod;
class TypeCast;
class Unary;
class ArgList;
class Postfix;
class Factor;
class ParamEllipsisList;
class ParamList;
class ParamDecl;
class InitDeclList;
class InitDecl;
class InitList;
class Init;
class Decl;
class DeclType;
class DeclarationSet;
class Declaration;
class Pointer;
class DeclSpec;

typedef std::string Tag;

class Tree
{
public:
	Tree() {};
	Tree(int inp);
	virtual void print() =0;
	virtual void cgen() {}
	virtual void get_arg_size(int& val) {}
	virtual ~Tree();
protected:
	Tag tag;
	int scope;
};

class Root
{
public:
	Root(File *f = NULL);
	void print();
	void cgen();
private:
	File* file;
};

class File
{
public:
	File (ExternDecl *ed = NULL, File *f = NULL);
	void print();
	void cgen();
private:
	ExternDecl *externdecl;
	File *file;
};

class ExternDecl : public Tree
{
public:
	ExternDecl(FuncDec* _fd = NULL, Declaration* _d = NULL);
	void print();
	void cgen();
private:
	FuncDec *funcdec;
	Declaration* declaration;
};

class FuncDec : public Tree
{
public:
	FuncDec(DeclSpec* _ds = NULL, Decl* _d = NULL, DeclarationSet* _dset = NULL, Comp* _c = NULL);
	void print();
	void cgen();
private:
	DeclSpec* declspec;
	Decl* decl;
	DeclarationSet* declarationset;
	Comp* compstate;
};

class Comp : public Tree
{
public:
	Comp(DeclarationSet* ds = NULL, StateList* sl = NULL);
	void print();
	void cgen();
	void get_arg_size(int& val);
private:
	DeclarationSet *declarationset;
	StateList *statelist;
};

class StateList : public Tree
{
public:
	StateList(State *s = NULL, StateList *sl = NULL);
	void print();
	void cgen();
	void get_arg_size(int& val);
private:
	State *state;
	StateList *statelist;
};

class State : public Tree {};

class ColonStatement : public Tree
{
public:
	ColonStatement(State *s = NULL, Ternary *t = NULL, std::string id = "", int c = 0, int d = 0);
	void print();
	void cgen();
	void get_arg_size(int& val);
private:
	State *state;
	Ternary *ternary;
	std::string ID;
	int vcase;
	int vdefault;
};

class Jump : public Tree 
{
public:
	Jump (ExprStatement *e = NULL, std::string j = "", std::string id = "");
	void print();
	void cgen();
	void get_arg_size(int& val);
private:
	ExprStatement* exprstatement;
	std::string jump;
	std::string id;
};

class Select : public Tree
{
public:
	Select (Expr *e = NULL, State *s = NULL, std::string sel = "", State *s2 = NULL, std::string sel2 = "");
	void print();
	void cgen();
	void get_arg_size(int& val);
private:
	Expr * expr;
	State* state;
	State* state2;
	std::string select;
	std::string select2;
};

class Loop : public Tree
{
public:
	Loop(Expr* e = NULL, State* s = NULL, std::string l = "", ExprStatement *es = NULL, ExprStatement *es2 = NULL, int d = 0, std::string l2 = "");
	void print();
	void cgen();
	void get_arg_size(int& val);
private:
	Expr* expr;
	State* state;
	std::string loop;
	std::string loop2;
	ExprStatement *exprstatement;
	ExprStatement *exprstatement2;
	int doing;
};

class ExprStatement : public Tree
{
public:
	ExprStatement(Expr *e = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	void get_arg_size(int& val);
private:
	Expr* expr;
};

class Expr : public Tree
{
public:
	Expr(AssignExpr *ae = NULL, Expr *e = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	void get_arg_size(int& val);
private:
	AssignExpr* assignexpr;
	Expr* expr;
};

class AssignExpr : public Tree
{
public:
	AssignExpr(Ternary *t = NULL, Unary *u = NULL, std::string ao = "", AssignExpr *ae = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	void get_arg_size(int& val);
private:
	Ternary* ternary;
	Unary* unary;
	std::string assignop;
	AssignExpr* assignexpr;
};

class Ternary : public Tree
{
public:
	Ternary(Prec *lo = NULL, Expr *e = NULL, Ternary *t = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	void get_arg_size(int& val);
	void get_array_size(int& asize);
	void set_return_type(int& rtype);
	void get_type(int& type);
private:
	Prec *logor;
	Expr *expr;
	Ternary *ternary;
};

class Prec : public Tree
{
public:
	Prec (Prec *p1 = NULL, Prec *p2 = NULL, std::string o = "", TypeCast *as = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	void get_arg_size(int& val);
	void get_array_size(int& asize);
	void set_return_type(int& rtype);
	void get_type(int& type);
private:
	Prec* rhs;
	Prec* lhs;
	TypeCast *typecast;
	std::string op;
};

class TypeCast : public Tree
{
public:
	TypeCast(Unary *u = NULL, TypeCast *tc = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	void get_arg_size(int& val);
	void get_array_size(int& asize);
	void set_return_type(int& rtype);
	void get_type(int& type);
private:
	Unary* unary;
	TypeCast *typecast;
};

class Unary : public Tree
{
public:
	Unary(Postfix *p = NULL, Unary *u = NULL, TypeCast *tc = NULL, std::string uo = "", int i = 0, int d = 0, int s = 0, int e = 0 );
	void print();
	void cgen();
	void get_type(int& type);
	void get_tag(std::string& in_tag);
	void set_return_type(int& rtype);
	void get_arg_size(int& val);
	void get_array_size(int& asize);
	void set_inc_dec(int set);
private:
	Postfix* postfix;
	Unary* unary;
	TypeCast* typecast;
	std::string unaryop;
	int incdec;
	int return_type;
	int inc;
	int dec;
	int size;
	int empty;
};

class ArgList : public Tree
{
public:
	ArgList(AssignExpr* ae = NULL, ArgList* al = NULL);
	void cgen();
	void print();
	void get_arg_size(int& val);
private:
	AssignExpr* assignexpr;
	ArgList* arglist;
};

class Postfix : public Tree
{
public:
	Postfix(Factor *f = NULL, Expr *e = NULL, ArgList *a = NULL, Postfix* p = NULL, std::string _ID = "", std::string _inc = "", std::string _dec = "");
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	void get_arg_size(int& val);
	void get_type(int& type);
	void set_return_type(int& rtype);
	std::string get_ID();
	void get_array_size(int& asize);
	void set_inc_dec(int set);
private:
	Factor* factor;
	Expr* expr;
	ArgList* arglist;
	Postfix* postfix;
	int return_type;
	int incdec;
	std::string ID;
	std::string inc;
	std::string dec;
};

class Factor : public Tree
{
public:
	Factor(std::string v = "", int t = -1, Expr *e = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
	std::string get_ID();
	void get_array_size(int& asize);
private:
	std::string val;
	int rvalue;
	int type;
	Expr *expr;
};

class ParamEllipsisList : public Tree
{
public:
	ParamEllipsisList(ParamList* pl = NULL, std::string e = "");
	void print();
	void cgen();
private:
	ParamList* paramlist;
	std::string ellipsis;
};

class ParamList : public Tree
{
public:
	ParamList(ParamDecl *pd = NULL, ParamList *pl = NULL);
	void print();
	void cgen();
private:
	ParamDecl* paramdecl;
	ParamList* paramlist;
};

class ParamDecl : public Tree
{
public:
	ParamDecl(DeclSpec* ds = NULL, Decl *d = NULL);
	void print();
	void cgen();
private:
	DeclSpec* declspec;
	Decl* decl;
};

class InitDeclList : public Tree
{
public: 
	InitDeclList(InitDecl *id = NULL, InitDeclList *idl = NULL);
	void print();
	void cgen();	
	void get_tag(std::string& in_tag);
private:
	InitDecl* initdecl;
	InitDeclList* initdecllist;
};

class InitDecl : public Tree
{
public:
	InitDecl(Decl *d = NULL, Init *ini = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
private:
	Decl* decl;
	Init* init;
};

class InitList : public Tree
{
public:
	InitList(Init *i = NULL, InitList *il = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
private:
	InitList* initlist;
	Init* init;
};

class Init : public Tree
{
public:
	Init(InitList *idl = NULL, AssignExpr *ae = NULL);
	void print();
	void cgen();
	void get_tag(std::string& in_tag);
private:
	AssignExpr* assignexpr;
	InitList* initlist;	
};

class Decl : public Tree
{
public:
	Decl(Pointer *p = NULL, DeclType *_dt = NULL);
	void print();
	void cgen();
	std::string getID();
	void get_tag(std::string& in_tag);
private:
	Pointer* pointers;
	DeclType* decltypes;	
};

class DeclType : public Tree
{
public:
	DeclType(std::string _ID = "", DeclType *dt = NULL, ParamEllipsisList *pel = NULL, Decl *d = NULL, int e = 0, Ternary *t = NULL, int arr = 0);
	void print();
	void cgen();
	std::string getID();
	void set_array();
	void get_tag(std::string& in_tag);
private:
	Decl* decl;
	DeclType* decltypes;
	ParamEllipsisList* paramellipsislist;
	Ternary *ternary;
	std::string ID;
	int func;
	int array;
	int type_array;
};

class DeclarationSet : public Tree
{
public:
	DeclarationSet(Declaration *_d = NULL, DeclarationSet *_ds = NULL);
	void print();
	void cgen();
private:
	Declaration* declaration;
	DeclarationSet* declarationset;
};

class Declaration : public Tree
{
public:
	Declaration(DeclSpec *ds = NULL, InitDeclList *idl = NULL);
	void print();
	void cgen();
private:
	DeclSpec* declspec;
	InitDeclList* initdecllist;
};

class Pointer : public Tree
{
public:
	Pointer(Pointer* point = NULL);
	void print();
private:
	Pointer* pointer;
};

class DeclSpec : public Tree
{
public:
	DeclSpec(std::string _type = "");
	void print();
private:
	std::string type;
};



#endif
