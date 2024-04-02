//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_WHILESTATEMENTASTNODE_H
#define CPP_TEST_WHILESTATEMENTASTNODE_H


#include "StatementASTNode.h"
#include "StatementsASTNode.h"
#include "../ExpASTNode/ExpASTNode.h"

class WhileStatementASTNode : public StatementASTNode{

private:
	ExpASTNode * exp_node;
	StatementASTNode * statement_block;

public:
	WhileStatementASTNode(ExpASTNode * exp_node, StatementASTNode * statement_block);
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;

	int get_number_function_calls_in_children() override;
};


#endif //CPP_TEST_WHILESTATEMENTASTNODE_H
