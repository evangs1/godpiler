//
// Created by evan on 5/2/23.
//

#ifndef GODPILER_METHODCALLTMPEXPASTNODE_H
#define GODPILER_METHODCALLTMPEXPASTNODE_H


#include "../ExpASTNode/ExpASTNode.h"

class MethodCallTmpExpASTNode : public ExpASTNode{
public:
    std::string method_id;
    std::vector<ExpASTNode *> exp_list;
    MethodCallTmpExpASTNode(std::string method_id, std::vector<ExpASTNode *> exp_list);


    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    Operand get_output_operand() override;

    int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;
};


#endif //GODPILER_METHODCALLTMPEXPASTNODE_H
