//
// Created by Evan Shaw on 4/25/23.
//

#include "CompareInstruction.h"

#include <utility>

CompareInstruction::CompareInstruction(Operand cmp_left_operand, Operand cmp_right_operand) : cmp_left_operand(
		std::move(cmp_left_operand)), cmp_right_operand(std::move(cmp_right_operand)) {

}

std::string CompareInstruction::to_string() {
	return std::string("cmp ") + cmp_left_operand.to_string() + ", " + cmp_right_operand.to_string();
}

std::set<Operand> CompareInstruction::get_use_set() {
	auto use_set = std::set<Operand>();
	naive_add_operand_to_set(use_set, cmp_left_operand);
	naive_add_operand_to_set(use_set, cmp_right_operand);
	return use_set;
}

std::set<Operand> CompareInstruction::get_def_set() {
	//defs some flags, but that doesn't really matter
	return std::set<Operand>();
}

void CompareInstruction::replace_operands(Operand to_replace, Operand replacer) {
	if (cmp_left_operand == to_replace) {
		cmp_left_operand = replacer;
	}
	if (cmp_right_operand == to_replace) {
		cmp_right_operand = replacer;
	}
}
