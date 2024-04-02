//
// Created by Evan Shaw on 4/28/23.
//

#include <utility>
#include <vector>
#include "PushInstruction.h"

std::string PushInstruction::to_string() {
	std::string ret_str = "push {";
	int i = 0;
	for (Operand op : register_list) {
		ret_str += op.to_string();
		if (i < register_list.size() - 1) {
			ret_str += ", ";
		}
		i++;
	}
	ret_str += "}";
	return ret_str;
}

std::set<Operand> PushInstruction::get_use_set() {
	return std::set<Operand>();
}

std::set<Operand> PushInstruction::get_def_set() {
	return std::set<Operand>();
}

void PushInstruction::replace_operands(Operand to_replace, Operand replacer) {

}

PushInstruction::PushInstruction(std::vector<Operand> register_list) : register_list(std::move(register_list)) {

}
