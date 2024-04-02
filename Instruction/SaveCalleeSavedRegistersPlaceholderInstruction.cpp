//
// Created by Evan Shaw on 4/25/23.
//

#include "SaveCalleeSavedRegistersPlaceholderInstruction.h"

std::string SaveCalleeSavedRegistersPlaceholderInstruction::to_string() {
	return std::string("callee-save <placeholder>");
}

std::set<Operand> SaveCalleeSavedRegistersPlaceholderInstruction::get_use_set() {
	//this shouldn't really use anything
	return std::set<Operand>();
}

std::set<Operand> SaveCalleeSavedRegistersPlaceholderInstruction::get_def_set() {
	//shouldn't def anything either
	return std::set<Operand>();
}

void SaveCalleeSavedRegistersPlaceholderInstruction::replace_operands(Operand to_replace, Operand replacer) {

}

SaveCalleeSavedRegistersPlaceholderInstruction::SaveCalleeSavedRegistersPlaceholderInstruction() = default;
