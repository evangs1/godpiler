//
// Created by Evan Shaw on 4/30/23.
//

#include "IntegerProgramArgumentExpASTNode.h"

std::vector<Instruction *> IntegerProgramArgumentExpASTNode::gen_3AC(int *symbolic_register_counter) {
	return std::vector<Instruction *>();
}

Operand IntegerProgramArgumentExpASTNode::get_output_operand() {
	return Operand();
}

int IntegerProgramArgumentExpASTNode::get_number_function_calls_in_children() {
	return 0;
}

IntegerProgramArgumentExpASTNode::IntegerProgramArgumentExpASTNode(int arg_index) : argument_index(arg_index) {

}

bool IntegerProgramArgumentExpASTNode::is_tmp_node() {
    return false;
}
