//
// Created by Evan Shaw on 4/25/23.
//

#include "BranchInstruction.h"

#include <utility>

BranchInstruction::BranchInstruction(Operand destination_label, LabelInstruction *branch_target_label_pointer)
		: destination_label(std::move(destination_label)), branch_target_label_pointer(branch_target_label_pointer) {

}

std::string BranchInstruction::to_string() {
	return std::string("b " + branch_target_label_pointer->get_raw_label());
}

std::set<Operand> BranchInstruction::get_use_set() {
	//should be empty because a simple branch does not use anything
	return std::set<Operand>();
}

std::set<Operand> BranchInstruction::get_def_set() {
	return std::set<Operand>();
}

LabelInstruction *BranchInstruction::get_branch_target_label_pointer() {
	return branch_target_label_pointer;
}

void BranchInstruction::replace_operands(Operand to_replace, Operand replacer) {

}
