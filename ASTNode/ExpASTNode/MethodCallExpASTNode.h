
//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_METHODCALLEXPASTNODE_H
#define CPP_TEST_METHODCALLEXPASTNODE_H


#include "../../SymbolTable/FunctionSymbolTableEntry.h"
#include "ExpASTNode.h"

class MethodCallExpASTNode : public ExpASTNode {

private:
	FunctionSymbolTableEntry *function_reference_to_symtab_entry;
	std::vector<ExpASTNode *> arg_exp_list;
	bool has_generated_3AC {false};

	Operand output_operand;


public:
	MethodCallExpASTNode(FunctionSymbolTableEntry *function_reference_to_symtab_entry, std::vector<ExpASTNode *>  arg_exp_list);

	Operand get_output_operand() override;
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;

	int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;
};


#endif //CPP_TEST_METHODCALLEXPASTNODE_H
