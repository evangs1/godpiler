//
// Created by evan on 5/3/23.
//

#ifndef GODPILER_ARGSTRINGREFERENCEASTNODE_H
#define GODPILER_ARGSTRINGREFERENCEASTNODE_H


#include "ExpASTNode.h"

class ArgStringReferenceASTNode : public ExpASTNode {
private:
    ExpASTNode * exp_node;
    //should be variable entry for args
    VariableSymbolTableEntry * var_symtab_entry;
    Operand output_operand;

public:
    explicit ArgStringReferenceASTNode(VariableSymbolTableEntry * var_symtab_entry, int argument_index);
    explicit ArgStringReferenceASTNode(VariableSymbolTableEntry * var_symtab_entry, ExpASTNode * exp_node);
    int arg_index{0};
    bool has_expression{false};

    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    Operand get_output_operand() override;

    int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;
};


#endif //GODPILER_ARGSTRINGREFERENCEASTNODE_H
