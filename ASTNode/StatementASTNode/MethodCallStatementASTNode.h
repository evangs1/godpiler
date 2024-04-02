//
// Created by evan on 5/3/23.
//

#ifndef GODPILER_METHODCALLSTATEMENTASTNODE_H
#define GODPILER_METHODCALLSTATEMENTASTNODE_H


#include "StatementASTNode.h"
#include "../ExpASTNode/ExpASTNode.h"

class MethodCallStatementASTNode : public StatementASTNode {
private:
    FunctionSymbolTableEntry * symtab_entry;
    std::vector<ExpASTNode *> exp_list;

public:
    MethodCallStatementASTNode(FunctionSymbolTableEntry * symtab_entry, std::vector<ExpASTNode *> exp_list);

    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    int get_number_function_calls_in_children() override;
};


#endif //GODPILER_METHODCALLSTATEMENTASTNODE_H
