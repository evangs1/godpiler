//
// Created by Evan Shaw on 4/21/23.
//

#include <string>
#include <utility>
#include <tuple>
#include "Operand.h"


Operand::Operand(enum OperandType type, int value) {
	this->operand_type = type;
	if (type == OPERAND_TYPE_REGISTER) {
		if (value < 0 || value > 15) {
			throw "Invalid Register Value";
		}
	}
	this->operand_value = value;
}

Operand::Operand(enum OperandType type, int value, VariableSymbolTableEntry *var_reference_to_symtab) : operand_type(
		type), operand_value(value), var_reference_to_symtab(var_reference_to_symtab) {

}

enum OperandType Operand::getOperandType() {
	return this->operand_type;
}

int Operand::getOperandValue() const {
	return this->operand_value;
}

std::string Operand::to_string() {
	std::string ret;
	switch (operand_type) {
		case OPERAND_TYPE_REGISTER:
			if (operand_value == 13) {
				ret = "sp";
			} else if (operand_value == 14) {
				ret = "lr";
			} else if (operand_value == 15) {
				ret = "pc";
			} else {
				ret = "r" + std::to_string(operand_value);
			}
			break;
		case OPERAND_TYPE_SYMBOLIC_REGISTER:
			ret = "$t" + std::to_string(operand_value);
			break;
		case OPERAND_TYPE_LITERAL:
            if (print_ldr_specific_literal) {
                ret = "=" + std::to_string(operand_value);
            } else {
                ret = "#" + std::to_string(operand_value);
            }
			break;
		case OPERAND_TYPE_VARIABLE_REFERENCE:
			ret = var_reference_to_symtab->get_var_id();
			break;
		case OPERAND_TYPE_UNDEFINED:
			ret = "UNDEFINED OPERAND";
			break;
		case OPERAND_TYPE_LABEL:
			ret = "=" + label_string;
			break;
	}
	return ret;
}

Operand::Operand() {
	operand_type = OPERAND_TYPE_UNDEFINED;
	operand_value = -1;
}

Operand::Operand(enum OperandType type, int value, std::string label_string) : operand_type(type), operand_value(value),
                                                                               label_string(std::move(label_string)) {


}

bool Operand::operator==(const Operand &other_operand) const {
	switch (operand_type) {

		case OPERAND_TYPE_UNDEFINED:
			return (this->operand_type == other_operand.operand_type) &&
			       (this->operand_value == other_operand.operand_value);
		case OPERAND_TYPE_REGISTER:
			return (this->operand_type == other_operand.operand_type) &&
			       (this->operand_value == other_operand.operand_value);
		case OPERAND_TYPE_SYMBOLIC_REGISTER:
			return (this->operand_type == other_operand.operand_type) &&
			       (this->operand_value == other_operand.operand_value);
		case OPERAND_TYPE_LITERAL:
			return (this->operand_type == other_operand.operand_type) &&
			       (this->operand_value == other_operand.operand_value);
		case OPERAND_TYPE_VARIABLE_REFERENCE:
			return (this->operand_type == other_operand.operand_type) &&
			       (this->operand_value == other_operand.operand_value) &&
			       (this->var_reference_to_symtab == other_operand.var_reference_to_symtab);
		case OPERAND_TYPE_LABEL:
			return (this->operand_type == other_operand.operand_type) &&
			       (this->label_string == other_operand.label_string);
		default:
			return false;
	}
}

bool Operand::operator<(const Operand &other_operand) const {
	return std::tie(this->operand_type, this->operand_value, this->var_reference_to_symtab) <
	       std::tie(other_operand.operand_type, other_operand.operand_value, other_operand.var_reference_to_symtab);
}

void Operand::set_print_ldr_specific_literal(bool print_ldr_specific_lit) {
    print_ldr_specific_literal = print_ldr_specific_lit;
}


