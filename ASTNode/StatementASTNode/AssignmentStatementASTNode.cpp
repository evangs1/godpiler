//
// Created by Evan Shaw on 4/24/23.
//

#include "AssignmentStatementASTNode.h"
#include "../../Instruction/MoveInstruction.h"

std::vector<Instruction *> AssignmentStatementASTNode::gen_3AC(int *symbolic_register_counter) {
	//TODO: CONSIDER DOING SOMETHING WHERE THE TOP AND FINAL EXPRESSION GETS MARKED BY ASSIGNMENT, THEN IT CAN
	//DIRECTLY PUT ITS VAR REFERENCE ONTO THE RESULT OF THE TOP AND FINAL EXPRESSION

	//generate 3AC for the expression
	auto left_exp_list_3AC = exp_node->gen_3AC(symbolic_register_counter);

	Operand exp_result_symbolic_register = exp_node->get_output_operand();
	Operand var_reference = Operand(OPERAND_TYPE_VARIABLE_REFERENCE, 0,
	                                var_symtab_reference);

	auto instr_list = std::vector<Instruction *>();

	//mov <var>, $tx
	auto instr = new MoveInstruction(var_reference, exp_result_symbolic_register);
	instr_list.push_back(instr);

	//insert expression's code above this code (probably more efficient to not insert above, just do reverse order)
	instr_list.insert(instr_list.begin(), left_exp_list_3AC.begin(), left_exp_list_3AC.end());

	has_generated_3AC = true;


	return instr_list;
}

AssignmentStatementASTNode::AssignmentStatementASTNode(VariableSymbolTableEntry * var_symtab_reference,
                                                       ExpASTNode *exp_node) : var_symtab_reference(var_symtab_reference),
                                                                               exp_node(exp_node) {

}

int AssignmentStatementASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	n_function_calls += exp_node->get_number_function_calls_in_children();

	return n_function_calls;
}
