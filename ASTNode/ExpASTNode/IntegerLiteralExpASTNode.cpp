//
// Created by Evan Shaw on 4/22/23.
//

#include "IntegerLiteralExpASTNode.h"
#include "../../Instruction/MoveInstruction.h"
#include "../../Instruction/LoadInstruction.h"

IntegerLiteralExpASTNode::IntegerLiteralExpASTNode(int value) : value(value) {
	has_generated_3AC = false;
}

std::vector<Instruction *> IntegerLiteralExpASTNode::gen_3AC(int *symbolic_register_counter) {
	auto instr_list = std::vector<Instruction *>();

	//generate a single mov instruction
	//mov $tx, #<literal_value>

	output_symbolic_register = (*symbolic_register_counter)++;

	Operand destination = Operand(OPERAND_TYPE_SYMBOLIC_REGISTER, output_symbolic_register);
	Operand literal = Operand(OPERAND_TYPE_LITERAL, value);


	output_operand = destination;

	//auto instr = new MoveInstruction(destination, literal);
    auto instr = new LoadInstruction(LOAD_INSTRUCTION_TYPE_LOAD_LITERAL, destination, literal);

    instr_list.push_back(instr);

	has_generated_3AC = true;

	return instr_list;
}

//probably should put this in the Abstract Class ExpASTNode
Operand IntegerLiteralExpASTNode::get_output_operand() {
		return output_operand;
}

int IntegerLiteralExpASTNode::get_number_function_calls_in_children() {
	return 0;
}

bool IntegerLiteralExpASTNode::is_tmp_node() {
    return false;
}
