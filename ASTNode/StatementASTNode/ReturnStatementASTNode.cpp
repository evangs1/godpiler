//
// Created by Evan Shaw on 4/25/23.
//

#include "ReturnStatementASTNode.h"
#include "../../Instruction/MoveInstruction.h"
#include "../../Instruction/FunctionReturnPlaceholderInstruction.h"

ReturnStatementASTNode::ReturnStatementASTNode(FunctionSymbolTableEntry *function_symtab_entry, ExpASTNode *exp_node)
		: function_symtab_entry(function_symtab_entry), exp_node(exp_node) {

}

std::vector<Instruction *> ReturnStatementASTNode::gen_3AC(int *symbolic_register_counter) {
    auto exp_list_3AC = std::vector<Instruction *>();
    if (exp_node != nullptr) {
	    exp_list_3AC = exp_node->gen_3AC(symbolic_register_counter);

        Operand exp_result_operand = exp_node->get_output_operand();
        //if exp result is stored in register r0
        if (exp_result_operand.getOperandType() == OPERAND_TYPE_REGISTER && exp_result_operand.getOperandValue() == 0) {
            //do nothing
        } else {
            //else we have to move it to r0
            Operand destination = Operand(OPERAND_TYPE_REGISTER, 0);
            auto mov = new MoveInstruction(destination, exp_result_operand);
            exp_list_3AC.push_back(mov);
        }
    }

	//theoretically have to restore callee-saved registers right here
	//maybe emit some made up instruction that isn't part of arm, but is a placeholder for later?

	//could either simply put pop {pc} at everywhere in the program where there is a return, or jump to a label at the end
	//of the program that pops

	//how about just the placeholder for now
	auto ret_placeholder = new FunctionReturnPlaceholderInstruction(function_symtab_entry);
	exp_list_3AC.push_back(ret_placeholder);

	has_generated_3AC = true;

	return exp_list_3AC;
}

int ReturnStatementASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	n_function_calls += exp_node->get_number_function_calls_in_children();

	return n_function_calls;
}


