#ifndef NODE_H
#define NODE_H
#define MAX_NUM_CHILDREN 3

#include <stdbool.h>

enum DataType { DATATYPE_UNDEFINED, DATATYPE_STR, DATATYPE_INT, DATATYPE_BOOLEAN };

// Returns the name of the given data type.
static inline const char *type_string(enum DataType t) {
    static const char *names[] = {"Undefined", "String", "Integer", "Boolean"};
    return names[t % 4];
}

struct SemanticData {
    enum DataType type;
    union value_t {
        char* string_value;
        int int_value;
        bool boolean_value;
    } value;
};

enum NodeType {
    NODETYPE_PROGRAM,
    NODETYPE_MAINCLASS,
    NODETYPE_MAINMETHOD,

    NODETYPE_STATEMENT,
	NODETYPE_STATEMENTS,
	NODETYPE_STATEMENT_BLOCK,
	NODETYPE_EXP_OR,
	NODETYPE_EXP_AND,
	NODETYPE_COMPARISON_EQUALS,
	NODETYPE_NOT_EQUALS,
	NODETYPE_GREATER_THAN_EQUALS, //10
	NODETYPE_LESS_THAN_EQUALS,
	NODETYPE_LESS_THAN,
	NODETYPE_GREATER_THAN,
	NODETYPE_PLUS,
	NODETYPE_MINUS,
	NODETYPE_MULTIPLY,
	NODETYPE_DIVIDE,

	NODETYPE_FACTOR_NOT,
	NODETYPE_FACTOR_PLUS,
	NODETYPE_FACTOR_MINUS, //20
	NODETYPE_FACTOR_PARENS,
	NODETYPE_FACTOR_LENGTH,
	NODETYPE_EXPLIST,
	NODETYPE_INDEX,

    NODETYPE_VARDECL,
	NODETYPE_MORE_VARDECL,
    NODETYPE_STATIC_VARDECL,
	NODETYPE_STATIC_VAR_DECL_LIST,
	NODETYPE_MORE_STATIC_VARDECL,
	NODETYPE_STATIC_METHOD_DECL, //30
	NODETYPE_STATIC_METHOD_DECL_LIST,
    NODETYPE_FORMAL_LIST,
    NODETYPE_ASSIGNMENT,
    NODETYPE_LEFTVALUE,
	NODETYPE_LEFTVALUE_INDEX,
    NODETYPE_PRINT,
    NODETYPE_PRINTLN,
    NODETYPE_METHOD_CALL,
    NODETYPE_NEW,




    NODETYPE_IF_ELSE, //40
    NODETYPE_WHILE,
    NODETYPE_RETURN,
    
    NODETYPE_TYPE, //43
    NODETYPE_PRIME_TYPE, //44
    NODETYPE_EXP,


	NODETYPE_EXP_1_BOOL,
    NODETYPE_EXP_2_BOOL,
	NODETYPE_EXP_2_INT,
    NODETYPE_EXP_2_INT_OR_STRING,
    NODETYPE_EXP_2_INT_OR_STRING_OR_BOOL,
	NODETYPE_EXP_1_INT,
	NODETYPE_EXP_1_INT_OR_STRING,




    NODETYPE_INTEGER_LITERAL,
    NODETYPE_BOOL_LITERAL,
    NODETYPE_STRING_LITERAL,

    NODETYPE_LENGTH,
	NODETYPE_METHOD_CALL_PARSEINT
};


struct RealType {
	//is base return type if is_function
	enum DataType base_data_type;
	//number of arrays added to the return type
	int number_of_arrays;
	//if the reference is a function
	bool is_function;
	//if the table entry is a function variable
	bool is_function_argument;
};

struct ASTNode {
    struct ASTNode* children[MAX_NUM_CHILDREN];
    int num_children;
    
    enum NodeType node_type;
    enum NodeType exp_node_type;
    struct SemanticData data;
    //struct TableEntryDeclaration * reference_to_symtab_entry;
    struct RealType real_type;
    int line_number;

};



// Creates a new node with 0 children on the heap using `malloc()`.
struct ASTNode* new_node(enum NodeType t);
// Adds the given children to the parent node. Returns -1 if the capacity is full.
int add_child(struct ASTNode* parent, struct ASTNode* child);

// Sets the data of the node to the given value and the corresponding type.

void set_string_value(struct ASTNode* node, char* s);
void set_int_value(struct ASTNode* node, int i);
void set_boolean_value(struct ASTNode* node, bool b);

struct RealType parse_real_type(struct ASTNode *node);

#endif
