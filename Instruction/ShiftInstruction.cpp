//
// Created by evan on 5/3/23.
//

#include "ShiftInstruction.h"

#include <utility>

std::string ShiftInstruction::to_string() {
    std::string ret;
    switch (operation_type) {

        case SHIFT_INSTRUCTION_TYPE_LEFT:
            ret = "lsl " + destination.to_string() + ", " + source.to_string() + ", " + shift_value.to_string();
            break;
        case SHIFT_INSTRUCTION_TYPE_RIGHT:
            ret = "lsr " + destination.to_string() + ", " + source.to_string() + ", " + shift_value.to_string();
            break;

    }
    return ret;
}

std::set<Operand> ShiftInstruction::get_use_set() {
    auto use_set = std::set<Operand>();
    naive_add_operand_to_set(use_set, source);
    naive_add_operand_to_set(use_set, shift_value);
    return use_set;
}

std::set<Operand> ShiftInstruction::get_def_set() {
    auto def_set = std::set<Operand>();
    naive_add_operand_to_set(def_set, destination);
    return def_set;
}

void ShiftInstruction::replace_operands(Operand to_replace, Operand replacer) {
    if (destination == to_replace) {
        destination = replacer;
    }
    if (source == to_replace) {
        source = replacer;
    }
    if (shift_value == to_replace) {
        shift_value = replacer;
    }
}

ShiftInstruction::ShiftInstruction(enum ShiftInstructionType operation_type, Operand destination, Operand source,
                                   Operand shift_value) : operation_type(operation_type),
                                                          destination(std::move(destination)),
                                                          source(std::move(source)),
                                                          shift_value(std::move(shift_value)) {

}
