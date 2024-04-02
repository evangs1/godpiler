//
// Created by Evan Shaw on 4/28/23.
//

#include <set>
#include "RetractStackPointerPlaceholderInstruction.h"

std::string RetractStackPointerPlaceholderInstruction::to_string() {
	return std::string("retract-sp <placeholder>");
}

int RetractStackPointerPlaceholderInstruction::get_change_sp_amount() {
	return change_sp_amount;
}

void RetractStackPointerPlaceholderInstruction::set_change_sp_amount(int change_sp) {
	this->change_sp_amount = change_sp;
}

std::set<Operand> RetractStackPointerPlaceholderInstruction::get_use_set() {
	//TODO: shouldn't really USE anything although if support were to be added for dynamic stack allocation or something...
	return std::set<Operand>();
}

std::set<Operand> RetractStackPointerPlaceholderInstruction::get_def_set() {
	//technically defs the stack pointer, but does it matter????
	return std::set<Operand>();
}

void RetractStackPointerPlaceholderInstruction::replace_operands(Operand to_replace, Operand replacer) {

}


RetractStackPointerPlaceholderInstruction::RetractStackPointerPlaceholderInstruction() = default;