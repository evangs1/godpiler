#include "node.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct ASTNode* new_node(enum NodeType t){
    struct ASTNode* ast_node = malloc(sizeof(struct ASTNode));
    memset(ast_node, 0, sizeof(struct ASTNode));
    ast_node->node_type = t;
    return ast_node;
}

int add_child(struct ASTNode* parent, struct ASTNode* child){
    if (parent->num_children < MAX_NUM_CHILDREN) {
        parent -> children[parent->num_children] = child;
        parent -> num_children++;
        return 0;
    } else {
        return -1;
    }
}

void set_string_value(struct ASTNode* node, char* s){
    node->data.type = DATATYPE_STR;
    node->data.value.string_value = s;
    if (node->data.value.string_value[0] == '"') {
        node->data.value.string_value = node->data.value.string_value + 1;
        int index = 1;
        while(node->data.value.string_value[index] != '"') {
            index++;
        }
        node->data.value.string_value[index] = '\0';
    }

}

void set_int_value(struct ASTNode* node, int i){
    node->data.type = DATATYPE_INT;
    node->data.value.int_value = i;
}

void set_boolean_value(struct ASTNode* node, bool b){
    node->data.type = DATATYPE_BOOLEAN;
    node->data.value.boolean_value = b;
}

void set_exp_node_type(struct ASTNode* node, enum NodeType exp_node_type) {
	node->exp_node_type = exp_node_type;
}



struct RealType parse_real_type(struct ASTNode *node) {
    assert(node->node_type == NODETYPE_TYPE);
    //need to count number of Type nodes in chain
    struct ASTNode *next_child = node->children[0];
    int number_of_extra_type_nodes = 0;
    while (next_child != NULL) {
        if (next_child->node_type == NODETYPE_PRIME_TYPE) {
            break;
        } else if (next_child->node_type == NODETYPE_TYPE) {
            next_child = next_child->children[0];
            number_of_extra_type_nodes++;
        } else {
#if DEBUG
            printf("!!! BAD NODETYPE IN TYPE CHECK !!!\n");
#endif
            exit(1);
        }
    }
    struct RealType real_type;
    real_type.base_data_type = next_child->data.type;
    real_type.number_of_arrays = number_of_extra_type_nodes;
    //we cannot determine whether or not it is a function or function argument (but set to false anyway)
    real_type.is_function = false;
    real_type.is_function_argument = false;
    return real_type;
}