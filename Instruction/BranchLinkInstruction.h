//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_BRANCHLINKINSTRUCTION_H
#define CPP_TEST_BRANCHLINKINSTRUCTION_H


#include "Instruction.h"
#include "../SymbolTable/FunctionSymbolTableEntry.h"

class BranchLinkInstruction : public Instruction {

private:
	Operand destination_label;
	//might include a pointer here to a label eventually

	//for calling other functions, probably need a reference to the symtab where the FunctionTable entry is
	FunctionSymbolTableEntry *function_symtab_entry_pointer;


public:
	BranchLinkInstruction(Operand destination_label, FunctionSymbolTableEntry *func_symtab_entry);

	std::string to_string() override;

	std::set<Operand> get_use_set() override;

	std::set<Operand> get_def_set() override;

	std::vector<Operand> register_list_save_restore;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_BRANCHLINKINSTRUCTION_H
