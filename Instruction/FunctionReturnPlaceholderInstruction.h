//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_FUNCTIONRETURNPLACEHOLDERINSTRUCTION_H
#define CPP_TEST_FUNCTIONRETURNPLACEHOLDERINSTRUCTION_H


#include "Instruction.h"

class FunctionReturnPlaceholderInstruction: public Instruction {

private:
	FunctionSymbolTableEntry * function_symbol_table_entry;
public:
	FunctionReturnPlaceholderInstruction(FunctionSymbolTableEntry * parent_function_symbol_table_entry);
	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_FUNCTIONRETURNPLACEHOLDERINSTRUCTION_H
