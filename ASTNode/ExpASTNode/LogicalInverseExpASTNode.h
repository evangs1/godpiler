//
// Created by evan on 5/3/23.
//

#ifndef GODPILER_LOGICALINVERSEEXPASTNODE_H
#define GODPILER_LOGICALINVERSEEXPASTNODE_H


#include "ExpASTNode.h"

class LogicalInverseExpASTNode : public ExpASTNode {
private:
    ExpASTNode * exp_node;

public:
    explicit LogicalInverseExpASTNode(ExpASTNode * exp_node);

    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    Operand get_output_operand() override;

    int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;
};


#endif //GODPILER_LOGICALINVERSEEXPASTNODE_H
