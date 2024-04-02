//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_BOOLEANOPERATIONEXPASTNODE_H
#define CPP_TEST_BOOLEANOPERATIONEXPASTNODE_H


#include "ExpASTNode.h"
#include "../../BooleanOperationTypeEnum.h"


class BooleanOperationExpASTNode : public ExpASTNode {

private:
	enum BooleanOperationType boolean_operation_type;
	ExpASTNode * left_exp;
	ExpASTNode * right_exp;

public:
	BooleanOperationExpASTNode(enum BooleanOperationType boolean_operation_type, ExpASTNode * left_exp, ExpASTNode * right_exp);
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;
	Operand get_output_operand() override;

	int get_number_function_calls_in_children() override;

	bool is_tmp_node() override;
};


#endif //CPP_TEST_BOOLEANOPERATIONEXPASTNODE_H
