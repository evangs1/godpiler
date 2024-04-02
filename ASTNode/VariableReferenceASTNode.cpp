//
// Created by Evan Shaw on 4/21/23.
//

#include "VariableReferenceASTNode.h"

VariableSymbolTableEntry *VariableReferenceASTNode::get_var_reference_to_symtab() {
	return var_reference_to_symtab;
}

VariableReferenceASTNode::VariableReferenceASTNode(VariableSymbolTableEntry *var_reference_to_symtab)
		: var_reference_to_symtab(var_reference_to_symtab) {

}

VariableReferenceASTNode::VariableReferenceASTNode() {

}
