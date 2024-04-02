//
// Created by Evan Shaw on 4/25/23.
//

#include "ConditionalMoveInstruction.h"

#include <utility>

ConditionalMoveInstruction::ConditionalMoveInstruction(enum BooleanOperationType boolean_operation_type,
                                                       Operand destination, Operand source) : boolean_operation_type(
		boolean_operation_type), destination(std::move(destination)), source(std::move(source)) {

}

std::string ConditionalMoveInstruction::to_string() {
	std::string move_suffix;
	switch(boolean_operation_type) {

		case BOOLEAN_OPERATION_TYPE_EQUAL_TO:
			move_suffix = "eq";
			break;
		case BOOLEAN_OPERATION_TYPE_NOT_EQUAL:
			move_suffix = "ne";
			break;
		case BOOLEAN_OPERATION_TYPE_GREATER_THAN_OR_EQUAL_TO:
			move_suffix = "ge";
			break;
		case BOOLEAN_OPERATION_TYPE_LESS_THAN:
			move_suffix = "lt";
			break;
		case BOOLEAN_OPERATION_TYPE_LESS_THAN_OR_EQUAL_TO:
			move_suffix = "le";
			break;
        case BOOLEAN_OPERATION_TYPE_GREATER_THAN:
            move_suffix = "gt";
            break;
        case BOOLEAN_OPERATION_TYPE_SPECIAL_NEGATE_MOVE:
            return std::string("mvn ") + destination.to_string() + ", " + source.to_string();
            break;
    }
	return std::string("mov") + move_suffix + " " + destination.to_string() + ", " + source.to_string();
}

std::set<Operand> ConditionalMoveInstruction::get_use_set() {
	auto use_set = std::set<Operand>();
	naive_add_operand_to_set(use_set, source);
	return use_set;
}

std::set<Operand> ConditionalMoveInstruction::get_def_set() {
	auto def_set = std::set<Operand>();
	naive_add_operand_to_set(def_set, destination);
	return def_set;
}

void ConditionalMoveInstruction::replace_operands(Operand to_replace, Operand replacer) {
	if (destination == to_replace) {
		destination = replacer;
	}
	if (source == to_replace) {
		source = replacer;
	}
}
