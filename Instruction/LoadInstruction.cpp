//
// Created by Evan Shaw on 4/25/23.
//

#include "LoadInstruction.h"

#include <utility>

LoadInstruction::LoadInstruction(enum LoadInstructionType operation_type, Operand destination, Operand source_1,
                                 Operand source_2) : operation_type(operation_type),
                                                     destination(std::move(destination)), source_1(std::move(source_1)),
                                                     source_2(std::move(source_2)) {

}

LoadInstruction::LoadInstruction(enum LoadInstructionType operation_type, Operand destination, Operand source_1)
		: operation_type(operation_type), destination(std::move(destination)), source_1(std::move(source_1)),
		  source_2() {

}

std::string LoadInstruction::to_string() {
	std::string ret = "ldr ";
	switch (operation_type) {

		case LOAD_INSTRUCTION_TYPE_LABEL:
			ret = ret + destination.to_string() + ", " + source_1.to_string();
			break;
		case LOAD_INSTRUCTION_TYPE_LOAD_FROM_ADDRESS_WITH_OFFSET:
			ret += destination.to_string() + ", [" + source_1.to_string() + ", " + source_2.to_string() + "]";
			break;
        case LOAD_INSTRUCTION_TYPE_LOAD_LITERAL:
            source_1.set_print_ldr_specific_literal(true);
            ret = ret + destination.to_string() + ", " + source_1.to_string();
            break;
    }
	return ret;
}

std::set<Operand> LoadInstruction::get_use_set() {
	auto use_set = std::set<Operand>();
	switch (operation_type) {

		case LOAD_INSTRUCTION_TYPE_LABEL:
			break;
		case LOAD_INSTRUCTION_TYPE_LOAD_FROM_ADDRESS_WITH_OFFSET:
			//ldr $tx, [sp, #4]
			//theoretically source_1 could be a real operand
            if (source_1.getOperandType() == OPERAND_TYPE_REGISTER && source_1.getOperandValue() == 13) {
                //if source_1 is sp, don't add to use set
            } else {
                naive_add_operand_to_set(use_set, source_1);
            }

			break;
        case LOAD_INSTRUCTION_TYPE_LOAD_LITERAL:
            //TODO: not sure anything needs to be done here???
            break;
    }
	return use_set;
}

std::set<Operand> LoadInstruction::get_def_set() {
	auto def_set = std::set<Operand>();
	naive_add_operand_to_set(def_set, destination);
	return def_set;
}

void LoadInstruction::replace_operands(Operand to_replace, Operand replacer) {
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


