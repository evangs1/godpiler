//
// Created by Evan Shaw on 4/25/23.
//

#include "ConditionalBranchInstruction.h"

#include <utility>

ConditionalBranchInstruction::ConditionalBranchInstruction(enum BooleanOperationType boolean_operation_type,
                                                           const Operand& destination_label,
                                                           LabelInstruction *branch_target_label_pointer)
		: BranchInstruction(destination_label, branch_target_label_pointer),
		  boolean_operation_type(boolean_operation_type) {

}

std::string ConditionalBranchInstruction::to_string() {
	std::string branch_suffix;
	switch(boolean_operation_type) {

		case BOOLEAN_OPERATION_TYPE_EQUAL_TO:
			branch_suffix = "eq";
			break;
		case BOOLEAN_OPERATION_TYPE_NOT_EQUAL:
			branch_suffix = "ne";
			break;
		case BOOLEAN_OPERATION_TYPE_GREATER_THAN_OR_EQUAL_TO:
			branch_suffix = "ge";
			break;
		case BOOLEAN_OPERATION_TYPE_LESS_THAN:
			branch_suffix = "lt";
			break;
		case BOOLEAN_OPERATION_TYPE_LESS_THAN_OR_EQUAL_TO:
			branch_suffix = "le";
			break;

	}
	return std::string("b" + branch_suffix + " " + branch_target_label_pointer->get_raw_label());
}

std::set<Operand> ConditionalBranchInstruction::get_use_set() {
	//conditional branch doesn't really use anything except flags
	return std::set<Operand>();
}

std::set<Operand> ConditionalBranchInstruction::get_def_set() {
	//doesn't def anything
	return std::set<Operand>();
}
