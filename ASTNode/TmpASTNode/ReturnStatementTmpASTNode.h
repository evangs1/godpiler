//
// Created by Evan Shaw on 5/1/23.
//

#ifndef CPP_TEST_RETURNSTATEMENTTMPASTNODE_H
#define CPP_TEST_RETURNSTATEMENTTMPASTNODE_H


#include "../ExpASTNode/ExpASTNode.h"
#include "../StatementASTNode/StatementASTNode.h"

class ReturnStatementTmpASTNode : public StatementASTNode {
public:
	ExpASTNode * exp;

    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    int get_number_function_calls_in_children() override;

    explicit ReturnStatementTmpASTNode(ExpASTNode * exp);
};


#endif //CPP_TEST_RETURNSTATEMENTTMPASTNODE_H
