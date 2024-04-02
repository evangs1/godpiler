//
// Created by Evan Shaw on 4/22/23.
//

#include "NormalOperationExpASTNode.h"
#include "../../Instruction/NormalOperationInstruction.h"

NormalOperationExpASTNode::NormalOperationExpASTNode(enum NormalOperationASTNodeType operation_type, ExpASTNode *left_exp,
                                                     ExpASTNode *right_exp) : operation_type(operation_type), left_exp(left_exp), right_exp(right_exp) {

}

std::vector<Instruction *> NormalOperationExpASTNode::gen_3AC(int *symbolic_register_counter) {
	//compute left and right expressions' 3AC first
	auto left_exp_list_3AC = left_exp->gen_3AC(symbolic_register_counter);
	auto right_exp_list_3AC = right_exp->gen_3AC(symbolic_register_counter);

	auto instr_list = std::vector<Instruction *>();

	//generate a single operation instruction
	//mov $tx, #<literal_value>
	//is this actually supposed to be a load???

	output_symbolic_register = (*symbolic_register_counter)++;

	Operand destination = Operand(OPERAND_TYPE_SYMBOLIC_REGISTER, output_symbolic_register);
	Operand source_1 = left_exp->get_output_operand();
	Operand source_2 = right_exp->get_output_operand();

	//translate enum values:
	enum OperationType op;
	switch(operation_type) {

		case NORMAL_OPERATION_ASTNODE_TYPE_ADDITION:
			op = NORMAL_OPERATION_INSTRUCTION_TYPE_ADDITION;
			break;
		case NORMAL_OPERATION_ASTNODE_TYPE_SUBTRACTION:
			op = NORMAL_OPERATION_INSTRUCTION_TYPE_SUBTRACTION;
			break;
		case NORMAL_OPERATION_ASTNODE_TYPE_MULTIPLICATION:
			op = NORMAL_OPERATION_INSTRUCTION_TYPE_MULTIPLICATION;
			break;
		case NORMAL_OPERATION_ASTNODE_TYPE_DIVISION:
			op = NORMAL_OPERATION_INSTRUCTION_TYPE_DIVISION;
			break;
		case NORMAL_OPERATION_ASTNODE_TYPE_AND:
			op = NORMAL_OPERATION_INSTRUCTION_TYPE_AND;
			break;
		case NORMAL_OPERATION_ASTNODE_TYPE_OR:
			op = NORMAL_OPERATION_INSTRUCTION_TYPE_OR;
			break;
	}

	auto instr = new NormalOperationInstruction(op, destination, source_1, source_2);
	instr_list.push_back(instr);

	//then attach left and right expressions' 3AC to this one's
	//left gets put on the top, then the right comes next, then this node's instructions
	//but we put in the right first because the left ends up on top of that

	instr_list.insert(instr_list.begin(), right_exp_list_3AC.begin(), right_exp_list_3AC.end());
	instr_list.insert(instr_list.begin(), left_exp_list_3AC.begin(), left_exp_list_3AC.end());

	has_generated_3AC = true;

	return instr_list;
}

Operand NormalOperationExpASTNode::get_output_operand() {
	//if (has_generated_3AC) {
	return Operand(OPERAND_TYPE_SYMBOLIC_REGISTER, output_symbolic_register);
	//} else {
	//	return -1;
	//}
}

int NormalOperationExpASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	n_function_calls += left_exp->get_number_function_calls_in_children();
	n_function_calls += right_exp->get_number_function_calls_in_children();
	return n_function_calls;
}

bool NormalOperationExpASTNode::is_tmp_node() {
    return false;
}
