//
// Created by Evan Shaw on 4/24/23.
//

#ifndef CPP_TEST_STATEMENTASTNODE_H
#define CPP_TEST_STATEMENTASTNODE_H


#include <vector>
//#include "../ASTNode.h"
#include "../../Instruction/Instruction.h"

class StatementASTNode {
protected:
	bool has_generated_3AC{false};

public:
	virtual std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) = 0;
	virtual int get_number_function_calls_in_children() = 0;

};


#endif //CPP_TEST_STATEMENTASTNODE_H
