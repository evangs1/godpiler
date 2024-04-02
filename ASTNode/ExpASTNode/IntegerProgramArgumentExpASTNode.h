//
// Created by Evan Shaw on 4/30/23.
//

#ifndef CPP_TEST_INTEGERPROGRAMARGUMENTEXPASTNODE_H
#define CPP_TEST_INTEGERPROGRAMARGUMENTEXPASTNODE_H


#include "ExpASTNode.h"

class IntegerProgramArgumentExpASTNode : public ExpASTNode {

	int argument_index;

public:
	explicit IntegerProgramArgumentExpASTNode(int arg_index);

	std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

	Operand get_output_operand() override;

	int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;
};


#endif //CPP_TEST_INTEGERPROGRAMARGUMENTEXPASTNODE_H
