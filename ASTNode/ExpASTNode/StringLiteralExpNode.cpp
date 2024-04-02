//
// Created by evan on 5/3/23.
//

#include "StringLiteralExpNode.h"
#include "../../Instruction/LoadInstruction.h"

std::vector<Instruction *> StringLiteralExpNode::gen_3AC(int *symbolic_register_counter) {
    auto instr_list = std::vector<Instruction *>();

    auto string_literal_label = get_str_literal_table_pointer()->first;

    Operand source_fmt_label = Operand(OPERAND_TYPE_LABEL, 0, string_literal_label);
    Operand destination_r1 = Operand(OPERAND_TYPE_REGISTER, 1);

    auto ldr_string = new LoadInstruction(LOAD_INSTRUCTION_TYPE_LABEL, destination_r1, source_fmt_label);
    instr_list.push_back(ldr_string);

    has_generated_3AC = true;
    output_operand = destination_r1;

    return instr_list;
}

Operand StringLiteralExpNode::get_output_operand() {
    return output_operand;
}

int StringLiteralExpNode::get_number_function_calls_in_children() {
    return 0;
}

bool StringLiteralExpNode::is_tmp_node() {
    return false;
}

StringLiteralExpNode::StringLiteralExpNode(std::pair<std::string, std::string> *str_lit_table_pointer) : str_lit_table_pointer(str_lit_table_pointer) {

}

std::pair<std::string, std::string> *StringLiteralExpNode::get_str_literal_table_pointer() {
    return str_lit_table_pointer;
}
