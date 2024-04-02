//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_STATEMENTSASTNODE_H
#define CPP_TEST_STATEMENTSASTNODE_H


#include <vector>
#include "StatementASTNode.h"

class StatementsASTNode : public StatementASTNode {

private:


public:
    std::vector<StatementASTNode *> statements_table;

	StatementsASTNode();

	void add_statement(StatementASTNode * stmt);

	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;

	int get_number_function_calls_in_children() override;
};


#endif //CPP_TEST_STATEMENTSASTNODE_H
