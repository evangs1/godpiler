//
// Created by Evan Shaw on 4/25/23.
//

#include "ExtendStackPointerPlaceholderInstruction.h"

std::string ExtendStackPointerPlaceholderInstruction::to_string() {
	return std::string("extend-sp <placeholder>");
}

int ExtendStackPointerPlaceholderInstruction::get_change_sp_amount() {
	return change_sp_amount;
}

void ExtendStackPointerPlaceholderInstruction::set_change_sp_amount(int change_sp) {
	this->change_sp_amount = change_sp;
}

std::set<Operand> ExtendStackPointerPlaceholderInstruction::get_use_set() {
	//TODO: shouldn't really USE anything although if support were to be added for dynamic stack allocation or something...
	return std::set<Operand>();
}

std::set<Operand> ExtendStackPointerPlaceholderInstruction::get_def_set() {
	//technically defs the stack pointer, but does it matter????
	return std::set<Operand>();
}

void ExtendStackPointerPlaceholderInstruction::replace_operands(Operand to_replace, Operand replacer) {

}


ExtendStackPointerPlaceholderInstruction::ExtendStackPointerPlaceholderInstruction() = default;
