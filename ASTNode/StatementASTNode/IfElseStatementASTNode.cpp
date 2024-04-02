//
// Created by Evan Shaw on 4/25/23.
//

#include <iostream>
#include "IfElseStatementASTNode.h"
#include "../../Instruction/CompareInstruction.h"
#include "../../Instruction/ConditionalBranchInstruction.h"

//maybe make a file with global/static vars???
int IfElseStatementASTNode::g = 0;


IfElseStatementASTNode::IfElseStatementASTNode(ExpASTNode *exp_node, StatementASTNode *statement_block_true,
                                               StatementASTNode *statement_block_false) : exp_node(exp_node),
                                                                                            statement_block_true(
		                                                                                            statement_block_true),
                                                                                            statement_block_false(
		                                                                                            statement_block_false) {

}

std::vector<Instruction *> IfElseStatementASTNode::gen_3AC(int *symbolic_register_counter) {
    std::cout << "G-------- " << g << std::endl;
    std::string false_label_string = std::string("_false") + std::to_string(g);
    std::string true_label_string = std::string("_true") + std::to_string(g);
    std::string endif_label_string = std::string("_endif") + std::to_string(g);
    g++;

    auto instr_list = exp_node->gen_3AC(symbolic_register_counter);
	Operand exp_node_result_operand = exp_node->get_output_operand();

	//cmp result with #0
	Operand literal_0 = Operand(OPERAND_TYPE_LITERAL, 0);
	auto cmp = new CompareInstruction(exp_node_result_operand, literal_0);
	instr_list.push_back(cmp);

	//conditional branch goes next, but need to create the label it points to to get its reference first

	auto false_label = new LabelInstruction(false_label_string);


	//should branch if equal to zero, so go to the false block if so
	//not sure if this label operand is necessary
	Operand label = Operand(OPERAND_TYPE_LABEL, 0, false_label_string);
	auto conditional_branch = new ConditionalBranchInstruction(BOOLEAN_OPERATION_TYPE_EQUAL_TO, label, false_label);
	instr_list.push_back(conditional_branch);

	//true label
	auto true_label = new LabelInstruction(true_label_string);
	instr_list.push_back(true_label);

    if (statement_block_true != nullptr) {
        auto true_instructions = statement_block_true->gen_3AC(symbolic_register_counter);
        instr_list.insert(instr_list.end(), true_instructions.begin(), true_instructions.end());
    }
	//create endif, needs to be added at the very end, we just do it here for the pointer
	auto endif_label = new LabelInstruction(endif_label_string);

	Operand endif_operand = Operand(OPERAND_TYPE_LABEL, 0, endif_label_string);
	auto branch_endif = new BranchInstruction(endif_operand, endif_label);
	instr_list.push_back(branch_endif);
	//can finally add the _false label
	instr_list.push_back(false_label);
    if (statement_block_false != nullptr) {
        auto false_instructions = statement_block_false->gen_3AC(symbolic_register_counter);
        instr_list.insert(instr_list.end(), false_instructions.begin(), false_instructions.end());
    }

	instr_list.push_back(endif_label);


	//finally increment the counter
	//g++;
	has_generated_3AC = true;
	return instr_list;
}

int IfElseStatementASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	n_function_calls += exp_node->get_number_function_calls_in_children();

	n_function_calls += statement_block_true->get_number_function_calls_in_children();
	n_function_calls += statement_block_false->get_number_function_calls_in_children();

	return n_function_calls;
}

