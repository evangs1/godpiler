//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_IFELSESTATEMENTASTNODE_H
#define CPP_TEST_IFELSESTATEMENTASTNODE_H


#include "StatementASTNode.h"
#include "../ExpASTNode/ExpASTNode.h"
#include "StatementsASTNode.h"

class IfElseStatementASTNode : public StatementASTNode {

private:
	ExpASTNode * exp_node;
	StatementASTNode * statement_block_true;
	StatementASTNode * statement_block_false;


public:
	IfElseStatementASTNode(ExpASTNode * exp_node, StatementASTNode * statement_block_true, StatementASTNode * statement_block_false);
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;
    static int g;
	int get_number_function_calls_in_children() override;

};


#endif //CPP_TEST_IFELSESTATEMENTASTNODE_H
