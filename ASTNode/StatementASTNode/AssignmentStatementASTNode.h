//
// Created by Evan Shaw on 4/24/23.
//

#ifndef CPP_TEST_ASSIGNMENTSTATEMENTASTNODE_H
#define CPP_TEST_ASSIGNMENTSTATEMENTASTNODE_H


#include "../../SymbolTable/VariableSymbolTableEntry.h"
#include "../VariableReferenceASTNode.h"
#include "../ExpASTNode/ExpASTNode.h"
#include "StatementASTNode.h"

class AssignmentStatementASTNode : public StatementASTNode {

private:
	VariableSymbolTableEntry * var_symtab_reference;
	ExpASTNode *exp_node;

	bool has_generated_3AC{false};

public:
	AssignmentStatementASTNode(VariableSymbolTableEntry * var_symtab_reference, ExpASTNode *exp_node);

	std::vector<Instruction*> gen_3AC(int *symbolic_register_counter) override;

	int get_number_function_calls_in_children() override;


};


#endif //CPP_TEST_ASSIGNMENTSTATEMENTASTNODE_H
