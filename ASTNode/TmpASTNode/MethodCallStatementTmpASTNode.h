//
// Created by Evan Shaw on 5/1/23.
//

#ifndef CPP_TEST_METHODCALLTMPASTNODE_H
#define CPP_TEST_METHODCALLTMPASTNODE_H

#include "../ExpASTNode/ExpASTNode.h"
#include "../StatementASTNode/StatementASTNode.h"

class MethodCallStatementTmpASTNode : public StatementASTNode {
public:
	std::string method_id;
	std::vector<ExpASTNode *> index_exp_list;

    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    int get_number_function_calls_in_children() override;

    MethodCallStatementTmpASTNode(std::string method_id, std::vector<ExpASTNode *> index_exp_list);
};


#endif //CPP_TEST_METHODCALLTMPASTNODE_H
