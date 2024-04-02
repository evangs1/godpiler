//
// Created by Evan Shaw on 4/21/23.
//

#ifndef CPP_TEST_VARIABLEREFERENCEASTNODE_H
#define CPP_TEST_VARIABLEREFERENCEASTNODE_H


#include "../SymbolTable/VariableSymbolTableEntry.h"

class VariableReferenceASTNode {

private:
	VariableSymbolTableEntry *var_reference_to_symtab{};

public:
	VariableReferenceASTNode(VariableSymbolTableEntry *var_reference_to_symtab);
	VariableReferenceASTNode();

	VariableSymbolTableEntry *get_var_reference_to_symtab();

};


#endif //CPP_TEST_VARIABLEREFERENCEASTNODE_H
