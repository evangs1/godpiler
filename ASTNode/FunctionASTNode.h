//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_FUNCTIONASTNODE_H
#define CPP_TEST_FUNCTIONASTNODE_H


#include "StatementASTNode/StatementsASTNode.h"
#include "../SymbolTable/FunctionSymbolTableEntry.h"

//TODO: does this need to inherit anything?
class FunctionASTNode {

private:
	StatementsASTNode * statements;
	FunctionSymbolTableEntry * function_symtab_entry_pointer;
	bool is_main_function;

public:
	FunctionASTNode(StatementsASTNode * statements, FunctionSymbolTableEntry * function_symtab_entry_pointer, bool is_main_function);
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter);
	int get_number_function_calls_in_children();
    bool get_is_main_function();

};


#endif //CPP_TEST_FUNCTIONASTNODE_H
