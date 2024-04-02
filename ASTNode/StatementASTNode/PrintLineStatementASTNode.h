//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_PRINTLINESTATEMENTASTNODE_H
#define CPP_TEST_PRINTLINESTATEMENTASTNODE_H


#include "../ExpASTNode/ExpASTNode.h"
#include "StatementASTNode.h"

class PrintLineStatementASTNode : public StatementASTNode {
private:
	ExpASTNode *exp_node;
	bool has_generated_3AC{false};
	FunctionSymbolTableEntry * printf_symtab_entry;
    bool should_print_newline{true};
    //if this is false, it should print string format
    bool int_format{true};

public:
	explicit PrintLineStatementASTNode(ExpASTNode *exp_node, FunctionSymbolTableEntry * printf_symtab_entry, bool should_print_newline, bool int_format);
	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;

	int get_number_function_calls_in_children() override;
};


#endif //CPP_TEST_PRINTLINESTATEMENTASTNODE_H
