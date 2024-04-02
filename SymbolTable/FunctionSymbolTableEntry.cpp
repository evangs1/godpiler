//
// Created by Evan Shaw on 4/24/23.
//

#include "FunctionSymbolTableEntry.h"

#include <utility>

FunctionSymbolTableEntry::FunctionSymbolTableEntry(enum VariableType ret_type, std::string function_id,
                                                   int ret_number_of_arrays, bool is_main, int num_args, bool is_extern) : ret_type(ret_type),
                                                                                             function_id(std::move(function_id)),
                                                                                             ret_number_of_arrays(
		                                                                                             ret_number_of_arrays),
                                                                                             is_main(is_main), number_of_arguments(num_args), is_extern(is_extern) {

}

std::string FunctionSymbolTableEntry::to_string() {
	std::string return_type;
	switch (ret_type) {
		case VARIABLE_TYPE_INT:
			return_type = "int   ";
			break;
		case VARIABLE_TYPE_STRING:
			return_type = "string";
			break;
		case VARIABLE_TYPE_BOOLEAN:
			return_type = "bool  ";
			break;
		case VARIABLE_TYPE_VOID:
			return_type = "void  ";
			break;
	}
	std::string ret =
			"FUNCTION: ret_type: " + return_type + " n_arrays: " + std::to_string(ret_number_of_arrays) + "is_main: " +
			std::to_string(is_main) + " id: " + function_id + "\n";

	for (auto e : table) {
		ret += e->to_string() + "\n";
	}

	return ret;
}

void FunctionSymbolTableEntry::add_entry(VariableSymbolTableEntry *var_entry) {
	var_entry->parent_function = this;
	table.push_back(var_entry);
}

std::string FunctionSymbolTableEntry::get_function_id() {
	return function_id;
}

enum VariableType FunctionSymbolTableEntry::get_return_type() {
	return ret_type;
}

enum VariableType FunctionSymbolTableEntry::get_ret_type() {
	return ret_type;
}

int FunctionSymbolTableEntry::get_number_of_arguments() {
	return number_of_arguments;
}

std::vector<VariableSymbolTableEntry *> FunctionSymbolTableEntry::get_argument_variables_symtab_entries() {
	auto ret = std::vector<VariableSymbolTableEntry *>();
	for (auto &var_symtab_entry : table) {
		if (var_symtab_entry->get_is_function_argument()) {
			ret.push_back(var_symtab_entry);
		}
	}
	return ret;
}

VariableSymbolTableEntry *FunctionSymbolTableEntry::find_var_symtab_entry_by_string(const std::string& var_id) {
    for (auto var_entry : table) {
        if (var_entry->get_var_id() == var_id) {
            return var_entry;
        }
    }
    return nullptr;
}

void FunctionSymbolTableEntry::set_return_type(enum VariableType vt) {
    ret_type = vt;
}

void FunctionSymbolTableEntry::set_number_of_arguments(int n) {
    number_of_arguments = n;
}

void FunctionSymbolTableEntry::set_ret_number_of_arrays(int n) {
    ret_number_of_arrays = n;
}

void FunctionSymbolTableEntry::set_is_main(bool is_main_func) {
    is_main = is_main_func;
}

void FunctionSymbolTableEntry::set_is_extern(bool is_extern_func) {
    is_extern = is_extern_func;
}

void FunctionSymbolTableEntry::set_function_needs_program_args(bool func_needs_program_args) {
    function_needs_program_args = func_needs_program_args;
}

bool FunctionSymbolTableEntry::get_function_needs_program_args() {
    return function_needs_program_args;
}
