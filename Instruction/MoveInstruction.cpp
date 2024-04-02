//
// Created by Evan Shaw on 4/24/23.
//

#include "MoveInstruction.h"

#include <utility>

MoveInstruction::MoveInstruction(Operand destination, Operand source) : destination(std::move(destination)), source(std::move(source)) {

}

std::string MoveInstruction::to_string() {
	std::string instr;
	instr = "mov " + destination.to_string() + ", " + source.to_string();
	return instr;
}

std::set<Operand> MoveInstruction::get_use_set() {
	auto use_set = std::set<Operand>();
	naive_add_operand_to_set(use_set, source);
	return use_set;
}

std::set<Operand> MoveInstruction::get_def_set() {
	auto def_set = std::set<Operand>();
	naive_add_operand_to_set(def_set, destination);
	return def_set;}

void MoveInstruction::replace_operands(Operand to_replace, Operand replacer) {
	if (destination == to_replace) {
		destination = replacer;
	}
	if (source == to_replace) {
		source = replacer;
	}
}

Operand MoveInstruction::get_destination_operand() {
	return destination;
}

Operand MoveInstruction::get_source_operand() {
	return source;
}
