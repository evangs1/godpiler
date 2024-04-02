//
// Created by Evan Shaw on 4/23/23.
//

#include <iostream>
#include "NormalOperationInstruction.h"

std::string NormalOperationInstruction::to_string() {
	std::string op;
	switch (operation_type) {
		case NORMAL_OPERATION_INSTRUCTION_TYPE_ADDITION:
			op = "add";
			break;
		case NORMAL_OPERATION_INSTRUCTION_TYPE_SUBTRACTION:
			op = "sub";
			break;
		case NORMAL_OPERATION_INSTRUCTION_TYPE_MULTIPLICATION:
			op = "mul";
			break;
		case NORMAL_OPERATION_INSTRUCTION_TYPE_DIVISION:
			op = "div";
			break;
		case NORMAL_OPERATION_INSTRUCTION_TYPE_AND:
			op = "and";
			break;
		case NORMAL_OPERATION_INSTRUCTION_TYPE_OR:
			op = "orr";
			break;
		default:
			std::cout << "Instruction Print Error: Unknown Type" << std::endl;
			exit(1);
	}
	std::string ret = op + " " + destination.to_string() + ", " + source_1.to_string() + ", " + source_2.to_string();
	return ret;
}

NormalOperationInstruction::NormalOperationInstruction(enum OperationType operation_type, Operand destination,
                                                       Operand source_1, Operand source_2)
		: operation_type(operation_type), destination(destination), source_1(source_1), source_2(source_2) {

}

std::set<Operand> NormalOperationInstruction::get_use_set() {
	auto use_set = std::set<Operand>();
	naive_add_operand_to_set(use_set, source_1);
	naive_add_operand_to_set(use_set, source_2);
	return use_set;
}

std::set<Operand> NormalOperationInstruction::get_def_set() {
	auto def_set = std::set<Operand>();
	naive_add_operand_to_set(def_set, destination);
	return def_set;
}

void NormalOperationInstruction::replace_operands(Operand to_replace, Operand replacer) {
	if (destination == to_replace) {
		destination = replacer;
	}
	if (source_1 == to_replace) {
		source_1 = replacer;
	}
	if (source_2 == to_replace) {
		source_2 = replacer;
	}
}

enum OperationType NormalOperationInstruction::get_operation_type() {
    return operation_type;
}

Operand NormalOperationInstruction::get_destination_operand() {
    return destination;
}

Operand NormalOperationInstruction::get_source_1_operand() {
    return source_1;
}


