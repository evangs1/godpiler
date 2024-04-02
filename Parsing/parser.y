
%{
#define YYDEBUG 0
#include <stdio.h>
#include <string.h>
#include "../Parsing/node.h"
void yyerror(char *);

extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;
extern struct ScopeNode * main_scope;
void set_exp_node_type(struct ASTNode* node, enum NodeType exp_node_type);
int recurse_symbol_table(struct ScopeNode *scope, int starting_offset);

struct ASTNode* root;
%}

// Declares all variants of semantic values. Yacc/Bison copies all variants
// to the generated header file (y.tab.h) enclosed in a C-language union
// declaration, named `YYSTYPE`. Check out the header file to see it.
%union {
    struct ASTNode* node;
    int integer;
    char * string;
}



// Left hand non-terminals. They are all associated to the `node` variant
// declared in the %union section, which is of type `ASTNode *`.
%type <node> Program MainClass VarDecl StaticVarDecl StaticMethodDecl Statement Exp PrimeType Type LeftValue
%type <node> FormalList FormalListTail ExpList Factor ExpOr ExpAnd ExpEq MethodCall ExpLessMore ExpAdd ExpMult
%type <node> Statements Index ExpListStar StaticVarDeclStar StaticMethodDeclStar OptionalExp MoreStaticVarDecl
%type <node> MoreVarDecl MainMethod



// Declares tokens. In the generated y.tab.h file, each token gets declared as 
// an enum constant and assigned with a unique number. These enum constants are
// used in the lex file, returned by `yylex()` to denote the symbolic tokens.

// These keyword-like tokens doesn't need to have a semantic value.
%token KW_BOOLEAN KW_CLASS KW_FALSE KW_INT MAIN KW_PUBLIC KW_PRIVATE KW_TRUE KW_VOID
%token KW_STATIC KW_STRING SYSTEM_OUT_PRINT SYSTEM_OUT_PRINTLN INTEGER_PARSEINT
%token KW_IF KW_ELSE KW_WHILE KW_RETURN KW_LENGTH KW_NEW
%token KW_SHORTCIRCUITOR KW_SHORTCIRCUITAND KW_COMPARISONEQUALS KW_GREATERTHANEQUALS KW_LESSTHANEQUALS KW_NOTEQUALS
%token KW_OPEN_BRACE KW_OPEN_PAREN KW_SEMICOLON KW_EQUALS

// These tokens have additional information aside from what kind of token it
// is, so they carry semantic information.
%token <integer> INTEGER_LITERAL
%token <string> STRING_LITERAL ID

%start Program

%%

Program:                
    MainClass {   
        $$ = new_node(NODETYPE_PROGRAM);
        $$->line_number = yylineno;
        root = $$;
        add_child($$, $1);
    };

MainClass: 
    KW_CLASS ID '{' StaticVarDeclStar StaticMethodDeclStar MainMethod '}'
    {
        $$ = new_node(NODETYPE_MAINCLASS);
        set_string_value($$, $2);
        add_child($$, $4);
        add_child($$, $5);
        add_child($$, $6);
        $$->line_number = yylineno;
    };

MainMethod:
	KW_PUBLIC KW_STATIC KW_VOID MAIN '(' KW_STRING '[' ']' ID ')' '{' Statements '}' {
		$$ = new_node(NODETYPE_MAINMETHOD);
		$$->line_number = yylineno;
		set_string_value($$, $9);
		add_child($$, $12);
        $$->line_number = yylineno;
	};


VarDecl:
    Type ID OptionalExp MoreVarDecl ';' {
        $$ = new_node(NODETYPE_VARDECL);
        set_string_value($$, $2);
        //printf("********VARDECL STRING VALUE: %s", $$->data.value.string_value);
        add_child($$, $1);
        add_child($$, $3);
        add_child($$, $4);
        $$->line_number = yylineno;
    };

StaticVarDecl:
	KW_PRIVATE KW_STATIC Type ID OptionalExp MoreStaticVarDecl ';' {
		$$ = new_node(NODETYPE_STATIC_VARDECL);
		set_string_value($$, $4);
		add_child($$, $3);
		add_child($$, $5);
		add_child($$, $6);
		$$->line_number = yylineno;
    };

OptionalExp:
	'=' Exp {
		$$ = $2;
	};
	| {
		$$ = NULL;
	};

//probably could combine MoreStaticVarDecl and MoreVarDecl into one
MoreStaticVarDecl:
	MoreStaticVarDecl ',' ID OptionalExp {
		$$ = new_node(NODETYPE_MORE_STATIC_VARDECL);
        set_string_value($$, $3);
        add_child($$, $1);
        add_child($$, $4);
        $$->line_number = yylineno;
	};
	| {
		$$ = NULL;
	}

MoreVarDecl:
	MoreVarDecl ',' ID OptionalExp {
		$$ = new_node(NODETYPE_MORE_VARDECL);
        set_string_value($$, $3);
        add_child($$, $1);
        add_child($$, $4);
        $$->line_number = yylineno;
	};
	| {
		$$ = NULL;
	}

StaticVarDeclStar:
	StaticVarDeclStar StaticVarDecl {
		$$ = new_node(NODETYPE_STATIC_VAR_DECL_LIST);
		add_child($$, $1);
		add_child($$, $2);
        $$->line_number = yylineno;
		//????????? MAYBE THIS IS ALL WRONG??!?!?
	};
	| {
		$$ = NULL;
	};

StaticMethodDecl:
	KW_PUBLIC KW_STATIC Type ID '(' FormalList ')' '{' Statements '}' {
		$$ = new_node(NODETYPE_STATIC_METHOD_DECL);
		set_string_value($$, $4);
		//Type
		add_child($$, $3);
		//FormalList
		add_child($$, $6);
		//Statements
		add_child($$, $9);
        $$->line_number = yylineno;
	};

StaticMethodDeclStar:
    StaticMethodDeclStar StaticMethodDecl {
        $$ = new_node(NODETYPE_STATIC_METHOD_DECL_LIST);
        add_child($$, $1);
        add_child($$, $2);
        $$->line_number = yylineno;
	};
	| {
		$$ = NULL;
	}

FormalList:
	Type ID FormalListTail {
		$$ = new_node(NODETYPE_FORMAL_LIST);
		set_string_value($$, $2);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};

FormalListTail:
	FormalListTail ',' Type ID {
		$$ = new_node(NODETYPE_FORMAL_LIST);
        set_string_value($$, $4);
        //reversed these so they correspond with FormalList
        //Type is first child
        add_child($$, $3);
        //FormalListTail is second child
        add_child($$, $1);
        $$->line_number = yylineno;
	};
	| {
		$$ = NULL;
	};

PrimeType:
    KW_INT {
        $$ = new_node(NODETYPE_PRIME_TYPE);
        $$ -> data.type = DATATYPE_INT;
        $$->line_number = yylineno;
    }
    | KW_BOOLEAN {
        $$ = new_node(NODETYPE_PRIME_TYPE);
        $$ -> data.type = DATATYPE_BOOLEAN;
        $$->line_number = yylineno;
    }
    | KW_STRING {
        $$ = new_node(NODETYPE_PRIME_TYPE);
        $$ -> data.type = DATATYPE_STR;
        $$->line_number = yylineno;
    };

Type:
	PrimeType {
		$$ = new_node(NODETYPE_TYPE);
		add_child($$, $1);
        $$->line_number = yylineno;
	};
	| Type '[' ']' {
		$$ = new_node(NODETYPE_TYPE);
		add_child($$, $1);
        $$->line_number = yylineno;
	};


Statement:              
    VarDecl {
        $$ = $1;
    }
    | '{' Statements '}' {
        $$ = new_node(NODETYPE_STATEMENT_BLOCK);
        add_child($$, $2);
        $$->line_number = yylineno;
    };
    | KW_IF '(' Exp ')' Statement KW_ELSE Statement {
        $$ = new_node(NODETYPE_IF_ELSE);
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $7);
        $$->line_number = yylineno;
    };
    | KW_WHILE '(' Exp ')' Statement {
        $$ = new_node(NODETYPE_WHILE);
        add_child($$, $3);
        add_child($$, $5);
        $$->line_number = yylineno;
    };
    | SYSTEM_OUT_PRINTLN '(' Exp ')' ';' {
        $$ = new_node(NODETYPE_PRINTLN);
        add_child($$, $3);
        $$->line_number = yylineno;
    }
    | SYSTEM_OUT_PRINT '(' Exp ')' ';' {
        $$ = new_node(NODETYPE_PRINT);
        add_child($$, $3);
        $$->line_number = yylineno;
    };
    | LeftValue '=' Exp ';' {
        $$ = new_node(NODETYPE_ASSIGNMENT);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
    };
    | KW_RETURN Exp ';' {
        $$ = new_node(NODETYPE_RETURN);
        add_child($$, $2);
        $$->line_number = yylineno;
    };
    | MethodCall ';' {
        $$ = $1;
    };


Statements:
	Statements Statement {
		$$ = new_node(NODETYPE_STATEMENTS);
		//should maybe switch these to make the tree right leaning???
        add_child($$, $1);
        add_child($$, $2);
        $$->line_number = yylineno;
	};
	| {
		$$ = NULL;
	}

LeftValue:
	ID {
		$$ = new_node(NODETYPE_LEFTVALUE);
        set_string_value($$, $1);
        $$->line_number = yylineno;
	};
	| LeftValue '[' Exp ']' {
		$$ = new_node(NODETYPE_LEFTVALUE);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};

MethodCall:
	ID '(' ExpList ')' {
		$$ = new_node(NODETYPE_METHOD_CALL);
	    set_string_value($$, $1);
	    add_child($$, $3);
        $$->line_number = yylineno;
	};
	//INTEGER_PARSEINT is here because it returns a value, it is not a statement
	| INTEGER_PARSEINT '(' Exp ')' {
		$$ = new_node(NODETYPE_METHOD_CALL);
		set_exp_node_type($$, NODETYPE_METHOD_CALL_PARSEINT);
        add_child($$, $3);
        $$->line_number = yylineno;
	};

/*
NODETYPE_EXP
*/

Exp:
	ExpOr {
		$$ = $1;
	};

ExpOr:
	ExpOr KW_SHORTCIRCUITOR ExpAnd {
		$$ = new_node(NODETYPE_EXP_2_BOOL);
		set_exp_node_type($$, NODETYPE_EXP_OR);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpAnd {
		$$ = $1;
	};

ExpAnd:
	ExpAnd KW_SHORTCIRCUITAND ExpEq {
		$$ = new_node(NODETYPE_EXP_2_BOOL);
		set_exp_node_type($$, NODETYPE_EXP_AND);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpEq {
		$$ = $1;
	};

ExpEq:
	ExpEq KW_COMPARISONEQUALS ExpLessMore {
		$$ = new_node(NODETYPE_EXP_2_INT_OR_STRING_OR_BOOL);
        set_exp_node_type($$, NODETYPE_COMPARISON_EQUALS);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpEq KW_NOTEQUALS ExpLessMore {
		$$ = new_node(NODETYPE_EXP_2_INT_OR_STRING_OR_BOOL);
		set_exp_node_type($$, NODETYPE_NOT_EQUALS);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpLessMore {
		$$ = $1;
	};

ExpLessMore:
	ExpLessMore KW_GREATERTHANEQUALS ExpAdd {
		$$ = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type($$, NODETYPE_GREATER_THAN_EQUALS);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpLessMore KW_LESSTHANEQUALS ExpAdd {
        $$ = new_node(NODETYPE_EXP_2_INT);
        set_exp_node_type($$, NODETYPE_LESS_THAN_EQUALS);
		add_child($$, $1);
		add_child($$, $3);
        $$->line_number = yylineno;
    };
	| ExpLessMore '<' ExpAdd {
		$$ = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type($$, NODETYPE_LESS_THAN);
		add_child($$, $1);
		add_child($$, $3);
        $$->line_number = yylineno;
    };
	| ExpLessMore '>' ExpAdd {
		$$ = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type($$, NODETYPE_GREATER_THAN);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpAdd {
		$$ = $1;
	};

ExpAdd:
	ExpAdd '+' ExpMult {
		$$ = new_node(NODETYPE_EXP_2_INT_OR_STRING);
		set_exp_node_type($$, NODETYPE_PLUS);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpAdd '-' ExpMult {
		$$ = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type($$, NODETYPE_MINUS);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpMult {
		$$ = $1;
	};

ExpMult:
	ExpMult '*' Factor {
		$$ = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type($$, NODETYPE_MULTIPLY);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| ExpMult '/' Factor {
		$$ = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type($$, NODETYPE_DIVIDE);
        add_child($$, $1);
        add_child($$, $3);
        $$->line_number = yylineno;
	};
	| Factor {
		$$ = $1;
	};

Factor:
	'!' Factor {
		$$ = new_node(NODETYPE_EXP_1_BOOL);
		set_exp_node_type($$, NODETYPE_FACTOR_NOT);
		add_child($$, $2);
        $$->line_number = yylineno;
	};
	| '+' Factor {
		$$ = new_node(NODETYPE_EXP_1_INT_OR_STRING);
		set_exp_node_type($$, NODETYPE_FACTOR_PLUS);
		add_child($$, $2);
        $$->line_number = yylineno;
	};
	| '-' Factor {
		$$ = new_node(NODETYPE_EXP_1_INT);
		set_exp_node_type($$, NODETYPE_FACTOR_MINUS);
		add_child($$, $2);
        $$->line_number = yylineno;
	};
	| '(' Exp ')' {
		$$ = $2;
	};
	| LeftValue {
		//pass up leftvalue????
		$$ = $1;
	};
	| LeftValue '.' KW_LENGTH {
		$$ = new_node(NODETYPE_LENGTH);
		set_exp_node_type($$, NODETYPE_FACTOR_LENGTH);
		add_child($$, $1);
        $$->line_number = yylineno;
	};
	| INTEGER_LITERAL {
		$$ = new_node(NODETYPE_INTEGER_LITERAL);
	    set_int_value($$, $1);
        $$->line_number = yylineno;
	}
	| STRING_LITERAL {
		$$ = new_node(NODETYPE_STRING_LITERAL);
	    set_string_value($$, $1);
        $$->line_number = yylineno;
	}
	| KW_TRUE {
		$$ = new_node(NODETYPE_BOOL_LITERAL);
	    set_boolean_value($$, true);
        $$->line_number = yylineno;
	}
	| KW_FALSE {
		$$ = new_node(NODETYPE_BOOL_LITERAL);
	    set_boolean_value($$, false);
        $$->line_number = yylineno;
	}
	| MethodCall {
		$$ = $1;

	};
	| KW_NEW PrimeType Index {
		$$ = new_node(NODETYPE_NEW);
		add_child($$, $2);
		add_child($$, $3);
        $$->line_number = yylineno;
	};


ExpList: Exp ExpListStar {
	$$ = new_node(NODETYPE_EXPLIST);
    add_child($$, $1);
    add_child($$, $2);
        $$->line_number = yylineno;
};


ExpListStar:
	ExpListStar ',' Exp {
		$$ = new_node(NODETYPE_EXPLIST);
		//reversed because conforms to ExpList ^^^ layout, (the Exp first, the Other ExpList last)
		add_child($$, $3);
		add_child($$, $1);
        $$->line_number = yylineno;
	};
	| {
		$$ = NULL;
	}
	;

Index:
	'[' Exp ']' {
		$$ = new_node(NODETYPE_INDEX);
		add_child($$, $2);
        $$->line_number = yylineno;
	};
	| Index '[' Exp ']' {
		$$ = new_node(NODETYPE_INDEX);
		add_child($$, $1);
		add_child($$, $3);
        $$->line_number = yylineno;
	};

%%

void yyerror(char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

//int main(int argc, char* argv[] )
//{
//
//	#if YYDEBUG
//        yydebug = 1;
//    #endif
//
//    yyin = fopen( argv[1], "r" );
//
//    // Checks for syntax errors and constructs AST
//    if (yyparse() != 0)
//        return 1;
//
//	printf("DONE!\n\n\n");
//    // Traverse the AST to check for semantic errors if no syntac errors
//    //checkProgram(root);
//
//	//printf("Typechecking:\n\n\n");
//    //Traverse AST a second time to make sure that types match up
//    //type_check_program(root);
//	//printf("DONE!\n\n\n");
//
//	//printf("outer number of ints: %d\n\n", recurse_symbol_table(main_scope, 0));
//	//asm_program(root);
//
//
//	//struct Instruction * final_instruction_list = reg_asn_program(root);
//
//	//printinf symbol table should be done after asm_program because it sets the offsets in the symbol table for local vars
//  //printf("\n\nPrinting Symbol Table:\n\n");
//  //print_tree_of_tables(main_scope, 0);
//
//  //printf("\n\n\n");
//
//	//char buf[200];
//	//strcpy(buf, argv[1]);
//	//char * p = strchr(buf, '.');
//	//strcpy(p, ".s\0");
//
//
//	//freopen(buf, "w", stdout);
//	//print_linked_list(final_instruction_list);
//
//
//
//    return 0;
//}
