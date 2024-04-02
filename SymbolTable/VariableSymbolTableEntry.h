//
// Created by Evan Shaw on 4/24/23.
//

#ifndef CPP_TEST_VARIABLESYMBOLTABLEENTRY_H
#define CPP_TEST_VARIABLESYMBOLTABLEENTRY_H


#include "SymbolTableEntry.h"
class FunctionSymbolTableEntry;

class VariableSymbolTableEntry : public SymbolTableEntry {

private:
	enum VariableType var_type;
	std::string var_id;
	int number_of_arrays;
	bool is_static;
	bool is_function_argument;

public:
	VariableSymbolTableEntry(enum VariableType var_type, std::string var_id, int number_of_arrays, bool is_static,
	                         bool is_function_argument);

	std::string get_var_id();
	FunctionSymbolTableEntry *parent_function{};

	std::string to_string();
	bool get_is_function_argument();
};


#endif //CPP_TEST_VARIABLESYMBOLTABLEENTRY_H
