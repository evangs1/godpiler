//
// Created by evan on 5/2/23.
//

#include "MethodCallTmpExpASTNode.h"

#include <utility>

std::vector<Instruction *> MethodCallTmpExpASTNode::gen_3AC(int *symbolic_register_counter) {
    return std::vector<Instruction *>();
}

Operand MethodCallTmpExpASTNode::get_output_operand() {
    return Operand();
}

int MethodCallTmpExpASTNode::get_number_function_calls_in_children() {
    return 1;
}

MethodCallTmpExpASTNode::MethodCallTmpExpASTNode(std::string method_id, std::vector<ExpASTNode *> exp_list) : method_id(std::move(method_id)), exp_list(std::move(exp_list)) {

}

bool MethodCallTmpExpASTNode::is_tmp_node() {
    return true;
}
