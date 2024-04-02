//
// Created by Evan Shaw on 4/24/23.
//

#include "VariableSymbolTableEntry.h"

#include <utility>

std::string VariableSymbolTableEntry::to_string() {
	std::string base_type;
	switch (var_type) {
		case VARIABLE_TYPE_INT:
			base_type = "int   ";
			break;
		case VARIABLE_TYPE_STRING:
			base_type = "string";
			break;
		case VARIABLE_TYPE_BOOLEAN:
			base_type = "bool  ";
			break;
		case VARIABLE_TYPE_VOID:
			base_type = "void  ";
			break;
	}
	std::string ret = "base type: " + base_type + " num arrays: " + std::to_string(number_of_arrays) + " is_static: " +
	                  std::to_string(is_static) + " is_function_argument: " + std::to_string(is_static) + " id: " +
	                  var_id;
	return ret;

}

VariableSymbolTableEntry::VariableSymbolTableEntry(enum VariableType var_type, std::string var_id, int number_of_arrays,
                                                   bool is_static, bool is_function_argument) : var_type(var_type),
                                                                                                var_id(std::move(
		                                                                                                var_id)),
                                                                                                number_of_arrays(
		                                                                                                number_of_arrays),
                                                                                                is_static(is_static),
                                                                                                is_function_argument(
		                                                                                                is_function_argument) {

}

std::string VariableSymbolTableEntry::get_var_id() {
	return var_id;
}

bool VariableSymbolTableEntry::get_is_function_argument() {
	return is_function_argument;
}
