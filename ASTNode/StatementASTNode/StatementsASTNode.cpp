//
// Created by Evan Shaw on 4/25/23.
//

#include "StatementsASTNode.h"

StatementsASTNode::StatementsASTNode() = default;

std::vector<Instruction *> StatementsASTNode::gen_3AC(int *symbolic_register_counter) {
	auto instr_list = std::vector<Instruction *>();

	for (StatementASTNode* i : statements_table) {
		auto stmt_instr_list = i->gen_3AC(symbolic_register_counter);
		instr_list.insert(instr_list.end(), stmt_instr_list.begin(), stmt_instr_list.end());
	}

	return instr_list;
}

void StatementsASTNode::add_statement(StatementASTNode *stmt) {
	if (stmt != nullptr) {
		statements_table.push_back(stmt);
	}

}

int StatementsASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	for (auto stmt : statements_table) {
		n_function_calls += stmt->get_number_function_calls_in_children();
	}
	return n_function_calls;
}

