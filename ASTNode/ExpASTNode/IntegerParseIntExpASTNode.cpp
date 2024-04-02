//
// Created by evan on 5/3/23.
//

#include "IntegerParseIntExpASTNode.h"
#include "../../Instruction/MoveInstruction.h"
#include "../../Instruction/BranchLinkInstruction.h"

std::vector<Instruction *> IntegerParseIntExpASTNode::gen_3AC(int *symbolic_register_counter) {
    auto exp_list_3AC = exp_node->gen_3AC(symbolic_register_counter);

    Operand destination_r0 = Operand(OPERAND_TYPE_REGISTER, 0);
    Operand exp_result = exp_node->get_output_operand();
    auto mov_exp = new MoveInstruction(destination_r0, exp_result);
    exp_list_3AC.push_back(mov_exp);

    Operand label_atoi = Operand(OPERAND_TYPE_LABEL, 0, std::string("atoi"));
    auto f_symtab_entry = new FunctionSymbolTableEntry(VARIABLE_TYPE_INT, std::string("atoi"), 0, false, 1, true);
    auto bl_atoi = new BranchLinkInstruction(label_atoi, f_symtab_entry);
    exp_list_3AC.push_back(bl_atoi);

    has_generated_3AC = true;
    return exp_list_3AC;

}

Operand IntegerParseIntExpASTNode::get_output_operand() {
    return {OPERAND_TYPE_REGISTER, 0};
}

int IntegerParseIntExpASTNode::get_number_function_calls_in_children() {
    return 1;
}

bool IntegerParseIntExpASTNode::is_tmp_node() {
    return false;
}

IntegerParseIntExpASTNode::IntegerParseIntExpASTNode(ExpASTNode *exp_node) : exp_node(exp_node) {

}
