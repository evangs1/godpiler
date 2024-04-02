//
// Created by Evan Shaw on 4/22/23.
//

#ifndef CPP_TEST_INTEGERLITERALEXPASTNODE_H
#define CPP_TEST_INTEGERLITERALEXPASTNODE_H


#include "ExpASTNode.h"

class IntegerLiteralExpASTNode : public ExpASTNode {

private:
	int value;

	bool has_generated_3AC {false};
	std::vector<Instruction> *list_3AC{};
	Operand output_operand;


public:
	explicit IntegerLiteralExpASTNode(int value);
	std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;
	Operand get_output_operand() override;

	int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;

};


#endif //CPP_TEST_INTEGERLITERALEXPASTNODE_H
