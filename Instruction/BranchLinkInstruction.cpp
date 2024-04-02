//
// Created by Evan Shaw on 4/25/23.
//

#include "BranchLinkInstruction.h"

#include <utility>
#include <iostream>


BranchLinkInstruction::BranchLinkInstruction(Operand destination_label, FunctionSymbolTableEntry * func_symtab_entry) : destination_label(std::move(destination_label)), function_symtab_entry_pointer(func_symtab_entry) {

}

std::string BranchLinkInstruction::to_string() {
	return "bl " + destination_label.label_string;
}

std::set<Operand> BranchLinkInstruction::get_use_set() {
	auto use_set = std::set<Operand>();

	//determine how many arguments bl has, then set those to the USE set
	int number_of_arguments = function_symtab_entry_pointer->get_number_of_arguments();
	for (int i = 0; i < number_of_arguments; i++) {
		if (i >= 4) {
			std::cout << "ADDING MORE THAN 4 ARGUMENTS TO THE USE SET - NOT GOOD" << std::endl;
		}
		Operand reg = Operand(OPERAND_TYPE_REGISTER, i);
		use_set.insert(reg);
	}

	return use_set;
}

std::set<Operand> BranchLinkInstruction::get_def_set() {
	return std::set<Operand>();
}

void BranchLinkInstruction::replace_operands(Operand to_replace, Operand replacer) {

}
