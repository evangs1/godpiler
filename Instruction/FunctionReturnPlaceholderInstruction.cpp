//
// Created by Evan Shaw on 4/25/23.
//

#include "FunctionReturnPlaceholderInstruction.h"
#include "../SymbolTable/FunctionSymbolTableEntry.h"

std::string FunctionReturnPlaceholderInstruction::to_string() {
	//maybe print a register list to pop later???

	return std::string("ret <placeholder>");
}

std::set<Operand> FunctionReturnPlaceholderInstruction::get_use_set() {
	auto use_set = std::set<Operand>();
	//if the current function returns anything, we should add r0 to the use set
	if (function_symbol_table_entry->get_return_type() != VARIABLE_TYPE_VOID) { //but if it is void, don't do that
		Operand r0 = Operand(OPERAND_TYPE_REGISTER, 0);
		use_set.insert(r0);
	}
	return use_set;
}

FunctionReturnPlaceholderInstruction::FunctionReturnPlaceholderInstruction(
		FunctionSymbolTableEntry *parent_function_symbol_table_entry) : function_symbol_table_entry(
		parent_function_symbol_table_entry) {

}

std::set<Operand> FunctionReturnPlaceholderInstruction::get_def_set() {
	//doesn't def anything
	return std::set<Operand>();
}

void FunctionReturnPlaceholderInstruction::replace_operands(Operand to_replace, Operand replacer) {

}
