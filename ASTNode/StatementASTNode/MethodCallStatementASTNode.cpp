//
// Created by evan on 5/3/23.
//

#include "MethodCallStatementASTNode.h"

#include <utility>

std::vector<Instruction *> MethodCallStatementASTNode::gen_3AC(int *symbolic_register_counter) {
    return {};
}

int MethodCallStatementASTNode::get_number_function_calls_in_children() {
    int n_function_call_in_children = 1;
    for (auto e : exp_list) {
        n_function_call_in_children += e->get_number_function_calls_in_children();
    }
    return n_function_call_in_children;
}

MethodCallStatementASTNode::MethodCallStatementASTNode(FunctionSymbolTableEntry *symtab_entry,
                                                       std::vector<ExpASTNode *> exp_list) : symtab_entry(symtab_entry), exp_list(std::move(exp_list)) {

}

