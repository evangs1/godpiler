//
// Created by evan on 5/3/23.
//

#ifndef GODPILER_STRINGLITERALEXPNODE_H
#define GODPILER_STRINGLITERALEXPNODE_H


#include "ExpASTNode.h"

class StringLiteralExpNode : public ExpASTNode {
private:
    std::pair<std::string, std::string> * str_lit_table_pointer;
    Operand output_operand;

public:
    explicit StringLiteralExpNode(std::pair<std::string, std::string> * str_lit_table_pointer);
    std::vector<Instruction *> gen_3AC(int *symbolic_register_counter) override;

    Operand get_output_operand() override;

    std::pair<std::string, std::string> * get_str_literal_table_pointer();
    int get_number_function_calls_in_children() override;

    bool is_tmp_node() override;

};


#endif //GODPILER_STRINGLITERALEXPNODE_H
