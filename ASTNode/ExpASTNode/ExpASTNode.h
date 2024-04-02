//
// Created by Evan Shaw on 4/22/23.
//

#ifndef CPP_TEST_EXPASTNODE_H
#define CPP_TEST_EXPASTNODE_H


#include <vector>
#include "../../Instruction/Instruction.h"

class ExpASTNode {


protected:
	int output_symbolic_register{};
	Operand output_operand;
	bool has_generated_3AC{false};
public:
	virtual std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) = 0;
	virtual Operand get_output_operand() = 0;
	virtual int get_number_function_calls_in_children() = 0;
    virtual bool is_tmp_node() = 0;


};


#endif //CPP_TEST_EXPASTNODE_H
