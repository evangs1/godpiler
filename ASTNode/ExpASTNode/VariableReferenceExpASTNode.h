//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_VARIABLEREFERENCEEXPASTNODE_H
#define CPP_TEST_VARIABLEREFERENCEEXPASTNODE_H


#include "ExpASTNode.h"
#include "../VariableReferenceASTNode.h"
#include "../TmpASTNode/VariableReferenceTmpASTNode.h"

class VariableReferenceExpASTNode : public ExpASTNode {

private:
	VariableSymbolTableEntry *var_symtab_entry{};
	//VariableReferenceTmpASTNode *tmp_var_reference{};

	Operand output_operand;
	bool has_generated_3AC {false};


public:
	explicit VariableReferenceExpASTNode(VariableSymbolTableEntry *var_symtab_entry);
	//explicit VariableReferenceExpASTNode(VariableReferenceTmpASTNode *tmp_var_reference);
	//in the future, have gen_3AC do different things for different array accesses

	//TODO: HAVE TWO OPTIONS:
	//DO A STANDARD LDR OR MOV OR SOMETHING OF THE VARIABLE INTO A TEMP REGISTER AND HOPE SPILLING WORKS
	//OR MAKE UP SOME SCHEME WHERE THIS DOESNT REALLY RETURN ANY 3AC AND JUST PASSES ALONG ITS VARIABLE

	//SECOND SOUNDS BETTER SORT OF, BUT I STILL PLAN TO DO SPILLING

	Operand get_output_operand() override;

	int get_number_function_calls_in_children() override;

	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;

    bool is_tmp_node() override;
};


#endif //CPP_TEST_VARIABLEREFERENCEEXPASTNODE_H
