//
// Created by Evan Shaw on 4/25/23.
//

#include "WhileStatementASTNode.h"
#include "../../Instruction/CompareInstruction.h"
#include "../../Instruction/LabelInstruction.h"
#include "../../Instruction/ConditionalBranchInstruction.h"

int global_while_label_counter = 0;

WhileStatementASTNode::WhileStatementASTNode(ExpASTNode *exp_node, StatementASTNode *statement_block) : exp_node(
		exp_node), statement_block(statement_block) {

}

std::vector<Instruction *> WhileStatementASTNode::gen_3AC(int *symbolic_register_counter) {
	auto instr_list = std::vector<Instruction *>();
	std::string loop_label_string = std::string("_loop") + std::to_string(global_while_label_counter);
    std::string endloop_label_string = std::string("_endloop") + std::to_string(global_while_label_counter);
    global_while_label_counter++;

	auto loop_label = new LabelInstruction(loop_label_string);
	instr_list.push_back(loop_label);

	auto exp_list = exp_node->gen_3AC(symbolic_register_counter);
	Operand exp_node_result_operand = exp_node->get_output_operand();
	//add exp instructions to list
	instr_list.insert(instr_list.end(), exp_list.begin(), exp_list.end());

	//cmp result with #0
	Operand literal_0 = Operand(OPERAND_TYPE_LITERAL, 0);
	auto cmp = new CompareInstruction(exp_node_result_operand, literal_0);
	instr_list.push_back(cmp);

	//conditional branch goes next, but need to create the label it points to to get its reference first
	auto endloop_label = new LabelInstruction(endloop_label_string);

	//should branch if equal to zero, so go to the false block if so
	//not sure if this label operand is necessary
	Operand label = Operand(OPERAND_TYPE_LABEL, 0, endloop_label_string);
	auto conditional_branch = new ConditionalBranchInstruction(BOOLEAN_OPERATION_TYPE_EQUAL_TO, label, endloop_label);
	instr_list.push_back(conditional_branch);

	//loop body
    if (statement_block != nullptr) {
        auto loop_body_instructions = statement_block->gen_3AC(symbolic_register_counter);
        instr_list.insert(instr_list.end(), loop_body_instructions.begin(), loop_body_instructions.end());
    }

	//branch to loop
	Operand loop_label_operand = Operand(OPERAND_TYPE_LABEL, 0, loop_label_string);
	auto branch_loop = new BranchInstruction(loop_label_operand, loop_label);
	instr_list.push_back(branch_loop);

	//_endloop_label
	instr_list.push_back(endloop_label);

	return instr_list;
}

int WhileStatementASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	n_function_calls += exp_node->get_number_function_calls_in_children();

	n_function_calls += statement_block->get_number_function_calls_in_children();

	return n_function_calls;
}
