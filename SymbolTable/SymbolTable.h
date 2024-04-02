//
// Created by Evan Shaw on 4/24/23.
//

#ifndef CPP_TEST_SYMBOLTABLE_H
#define CPP_TEST_SYMBOLTABLE_H


#include <vector>
#include "SymbolTableEntry.h"
#include "VariableSymbolTableEntry.h"
#include "FunctionSymbolTableEntry.h"

class SymbolTable {

private:
    //pair.first = id, pair.second = string literal
    std::vector<std::pair<std::string, std::string> *> string_literal_table;
	std::vector<VariableSymbolTableEntry *> static_variables;
	std::vector<FunctionSymbolTableEntry *> functions;

public:
	SymbolTable();

	//change to int to check if successful???
	void add_static_var_to_symbol_table(VariableSymbolTableEntry *);
	void add_function_to_symbol_table(FunctionSymbolTableEntry *);
    FunctionSymbolTableEntry * find_symtab_entry_by_string(const std::string& match_string);

    std::pair<std::string, std::string> * add_string_literal_to_string(const std::string& id, const std::string& literal);
    std::string string_literals_to_string();

};


#endif //CPP_TEST_SYMBOLTABLE_H
