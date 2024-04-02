//
// Created by evan on 5/3/23.
//

#include <iostream>
#include "ArgStringReferenceASTNode.h"
#include "../../Instruction/LoadInstruction.h"

ArgStringReferenceASTNode::ArgStringReferenceASTNode(VariableSymbolTableEntry *var_symtab_entry, int argument_index)
        : var_symtab_entry(var_symtab_entry), arg_index(argument_index) {
    exp_node = nullptr;
}

ArgStringReferenceASTNode::ArgStringReferenceASTNode(VariableSymbolTableEntry *var_symtab_entry, ExpASTNode *exp_node)
        : var_symtab_entry(var_symtab_entry), exp_node(exp_node) {
    has_expression = true;
}

std::vector<Instruction *> ArgStringReferenceASTNode::gen_3AC(int *symbolic_register_counter) {

    //if integer literal, do some left shift

    if (exp_node == nullptr) {
        auto instr_list = std::vector<Instruction *>();
        output_symbolic_register = (*symbolic_register_counter)++;
        int literal_value = (arg_index + 1) * 4;
        auto ldr_string_at_index = new LoadInstruction(LOAD_INSTRUCTION_TYPE_LOAD_FROM_ADDRESS_WITH_OFFSET,
                                                       Operand(OPERAND_TYPE_SYMBOLIC_REGISTER, output_symbolic_register),
                                                       Operand(OPERAND_TYPE_VARIABLE_REFERENCE, 0, var_symtab_entry),
                                                       Operand(OPERAND_TYPE_LITERAL, literal_value));
        instr_list.push_back(ldr_string_at_index);
        has_generated_3AC = true;
        return instr_list;
    } else {
        std::cout << "EXP in ARG REFERENCE NOT SUPPORTED YET, BUT CLOSE" << std::endl;
//        auto instr_list = exp_node->gen_3AC(symbolic_register_counter);
//        auto
//        output_symbolic_register = (*symbolic_register_counter)++;
        return {};
    }


    //TODO: get args base address (from god knows where) then do all the fancy shifting and stuff to get the address of the string we want
}

Operand ArgStringReferenceASTNode::get_output_operand() {
    return {OPERAND_TYPE_SYMBOLIC_REGISTER, output_symbolic_register};
}

int ArgStringReferenceASTNode::get_number_function_calls_in_children() {
    //TODO:
    return 0;
}

bool ArgStringReferenceASTNode::is_tmp_node() {
    return false;
}
