//
// Created by Evan Shaw on 4/28/23.
//

#include "PopInstruction.h"

std::string PopInstruction::to_string() {
	std::string ret_str = "pop {";
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

std::set<Operand> PopInstruction::get_use_set() {
	return std::set<Operand>();
}

std::set<Operand> PopInstruction::get_def_set() {
	return std::set<Operand>();
}

void PopInstruction::replace_operands(Operand to_replace, Operand replacer) {

}

PopInstruction::PopInstruction(std::vector<Operand> register_list) : register_list(std::move(register_list)) {

}
