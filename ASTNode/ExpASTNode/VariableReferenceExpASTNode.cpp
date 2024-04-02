//
// Created by Evan Shaw on 4/25/23.
//

#include "VariableReferenceExpASTNode.h"

std::vector<Instruction *> VariableReferenceExpASTNode::gen_3AC(int *symbolic_register_counter) {
	//all this function should do is effectively pass up its operand
	output_operand = Operand(OPERAND_TYPE_VARIABLE_REFERENCE, 0, var_symtab_entry);

	has_generated_3AC = true;

	return std::vector<Instruction *>();
}

VariableReferenceExpASTNode::VariableReferenceExpASTNode(VariableSymbolTableEntry *var_symtab_entry)
		: var_symtab_entry(var_symtab_entry),
		  output_operand(OPERAND_TYPE_VARIABLE_REFERENCE, 0, var_symtab_entry) {

}

Operand VariableReferenceExpASTNode::get_output_operand() {
	return output_operand;
}

int VariableReferenceExpASTNode::get_number_function_calls_in_children() {
	return 0;
}

bool VariableReferenceExpASTNode::is_tmp_node() {
    return false;
}

//VariableReferenceExpASTNode::VariableReferenceExpASTNode(VariableReferenceTmpASTNode *tmp_var_reference) : tmp_var_reference(tmp_var_reference) {
//
//}
