//
// Created by Evan Shaw on 5/1/23.
//

#include "ReturnStatementTmpASTNode.h"

ReturnStatementTmpASTNode::ReturnStatementTmpASTNode(ExpASTNode *exp) : exp(exp) {

}

std::vector<Instruction *> ReturnStatementTmpASTNode::gen_3AC(int *symbolic_register_counter) {
    return std::vector<Instruction *>();
}

int ReturnStatementTmpASTNode::get_number_function_calls_in_children() {
    if (exp != nullptr) {
        return exp->get_number_function_calls_in_children();
    } else {
        return 0;
    }

}
