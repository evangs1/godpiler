//
// Created by evan on 5/3/23.
//

#include "LogicalInverseExpASTNode.h"
#include "../../Instruction/ConditionalMoveInstruction.h"


std::vector<Instruction *> LogicalInverseExpASTNode::gen_3AC(int *symbolic_register_counter) {
    auto instr_list = exp_node->gen_3AC(symbolic_register_counter);

    //TODO: movn should really have its own Instruction class
    output_operand = Operand(OPERAND_TYPE_SYMBOLIC_REGISTER, (*symbolic_register_counter)++);
    auto movn = new ConditionalMoveInstruction(BOOLEAN_OPERATION_TYPE_SPECIAL_NEGATE_MOVE, output_operand,
                                               exp_node->get_output_operand());

    instr_list.push_back(movn);
    has_generated_3AC = true;

    return instr_list;
}

Operand LogicalInverseExpASTNode::get_output_operand() {
    return output_operand;
}

int LogicalInverseExpASTNode::get_number_function_calls_in_children() {
    return exp_node->get_number_function_calls_in_children();
}

bool LogicalInverseExpASTNode::is_tmp_node() {
    return false;
}

LogicalInverseExpASTNode::LogicalInverseExpASTNode(ExpASTNode *exp_node) : exp_node(exp_node) {

}
