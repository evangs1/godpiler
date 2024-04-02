//
// Created by Evan Shaw on 4/22/23.
//

#ifndef CPP_TEST_NORMALOPERATIONEXPASTNODE_H
#define CPP_TEST_NORMALOPERATIONEXPASTNODE_H


#include "ExpASTNode.h"

enum NormalOperationASTNodeType {
	NORMAL_OPERATION_ASTNODE_TYPE_ADDITION,
	NORMAL_OPERATION_ASTNODE_TYPE_SUBTRACTION,
	NORMAL_OPERATION_ASTNODE_TYPE_MULTIPLICATION,
	NORMAL_OPERATION_ASTNODE_TYPE_DIVISION,
	NORMAL_OPERATION_ASTNODE_TYPE_AND,
	NORMAL_OPERATION_ASTNODE_TYPE_OR
};

class NormalOperationExpASTNode : public ExpASTNode {

private:
	enum NormalOperationASTNodeType operation_type;
	ExpASTNode* left_exp;
	ExpASTNode* right_exp;

	//should include list of instructions???

	//should probably be in abstract class
	bool has_generated_3AC {false};

	Operand output_operand;

public:
	NormalOperationExpASTNode(enum NormalOperationASTNodeType operation_type, ExpASTNode* left_exp, ExpASTNode* right_exp);
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;
	Operand get_output_operand() override;

	int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;
};


#endif //CPP_TEST_NORMALOPERATIONEXPASTNODE_H
