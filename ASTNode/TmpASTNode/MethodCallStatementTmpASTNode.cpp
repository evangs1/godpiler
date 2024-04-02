//
// Created by Evan Shaw on 5/1/23.
//

#include "MethodCallStatementTmpASTNode.h"

#include <utility>

std::vector<Instruction *> MethodCallStatementTmpASTNode::gen_3AC(int *symbolic_register_counter) {
    return {};
}

int MethodCallStatementTmpASTNode::get_number_function_calls_in_children() {
    //TODO: not correct, but still provides sameish functionality
    return 1;
}

MethodCallStatementTmpASTNode::MethodCallStatementTmpASTNode(std::string method_id,
                                                             std::vector<ExpASTNode *> index_exp_list) : method_id(std::move(method_id)), index_exp_list(std::move(index_exp_list)) {

}
