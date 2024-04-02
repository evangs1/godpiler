//
// Created by Evan Shaw on 4/25/23.
//

#include "LabelInstruction.h"

#include <utility>

LabelInstruction::LabelInstruction(std::string label_string) : label_string(std::move(label_string)) {

}

std::string LabelInstruction::to_string() {
	return label_string + ":";
}

std::string LabelInstruction::get_raw_label() {
	return label_string;
}

std::set<Operand> LabelInstruction::get_use_set() {
	return std::set<Operand>();
}

std::set<Operand> LabelInstruction::get_def_set() {
	return std::set<Operand>();
}

void LabelInstruction::replace_operands(Operand to_replace, Operand replacer) {

}


