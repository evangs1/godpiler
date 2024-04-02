//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_RETURNSTATEMENTASTNODE_H
#define CPP_TEST_RETURNSTATEMENTASTNODE_H


#include "StatementASTNode.h"
#include "../ExpASTNode/ExpASTNode.h"

class ReturnStatementASTNode : public StatementASTNode {

private:
	ExpASTNode * exp_node;
	FunctionSymbolTableEntry * function_symtab_entry;

public:
	ReturnStatementASTNode(FunctionSymbolTableEntry * function_symtab_entry, ExpASTNode * exp_node);
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;

	int get_number_function_calls_in_children() override;
};


#endif //CPP_TEST_RETURNSTATEMENTASTNODE_H
