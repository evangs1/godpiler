//
// Created by Evan Shaw on 4/25/23.
//

#include "BooleanOperationExpASTNode.h"
#include "../../Instruction/CompareInstruction.h"
#include "../../Instruction/MoveInstruction.h"
#include "../../Instruction/ConditionalMoveInstruction.h"

BooleanOperationExpASTNode::BooleanOperationExpASTNode(enum BooleanOperationType boolean_operation_type,
                                                       ExpASTNode *left_exp, ExpASTNode *right_exp)
		: boolean_operation_type(boolean_operation_type), left_exp(
		left_exp), right_exp(right_exp) {

}

Operand BooleanOperationExpASTNode::get_output_operand() {
	return output_operand;
}

std::vector<Instruction *> BooleanOperationExpASTNode::gen_3AC(int *symbolic_register_counter) {
	auto instr_list = std::vector<Instruction *>();

	auto left_exp_instr_list = left_exp->gen_3AC(symbolic_register_counter);
	auto right_exp_instr_list = right_exp->gen_3AC(symbolic_register_counter);

	instr_list.insert(instr_list.end(), left_exp_instr_list.begin(), left_exp_instr_list.end());
	instr_list.insert(instr_list.end(), right_exp_instr_list.begin(), right_exp_instr_list.end());

	Operand left_exp_result_operand = left_exp->get_output_operand();
	Operand right_exp_result_operand = right_exp->get_output_operand();

	//cmp instruction
	auto cmp_instr = new CompareInstruction(left_exp_result_operand, right_exp_result_operand);
	instr_list.push_back(cmp_instr);

	//mov 0 to set up for conditional mov
	Operand destination = Operand(OPERAND_TYPE_SYMBOLIC_REGISTER, (*symbolic_register_counter)++);
	Operand literal_0 = Operand(OPERAND_TYPE_LITERAL, 0);
	auto mov_0 = new MoveInstruction(destination, literal_0);
	instr_list.push_back(mov_0);

	//conditional mov
	Operand literal_1 = Operand(OPERAND_TYPE_LITERAL, 1);
	auto conditional_mov = new ConditionalMoveInstruction(boolean_operation_type, destination, literal_1);
	instr_list.push_back(conditional_mov);

	output_operand = destination;

	has_generated_3AC = true;

	return instr_list;
}

int BooleanOperationExpASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	n_function_calls += left_exp->get_number_function_calls_in_children();
	n_function_calls += right_exp->get_number_function_calls_in_children();
	return n_function_calls;
}

bool BooleanOperationExpASTNode::is_tmp_node() {
    return false;
}


