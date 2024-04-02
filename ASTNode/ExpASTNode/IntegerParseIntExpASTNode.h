//
// Created by evan on 5/3/23.
//

#ifndef GODPILER_INTEGERPARSEINTEXPASTNODE_H
#define GODPILER_INTEGERPARSEINTEXPASTNODE_H


#include "ExpASTNode.h"

class IntegerParseIntExpASTNode : public ExpASTNode {
private:
    ExpASTNode * exp_node;
    bool has_generated_3AC{false};
    Operand output_operand;


public:
    explicit IntegerParseIntExpASTNode(ExpASTNode * exp_node);
    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    Operand get_output_operand() override;

    int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;

};


#endif //GODPILER_INTEGERPARSEINTEXPASTNODE_H
