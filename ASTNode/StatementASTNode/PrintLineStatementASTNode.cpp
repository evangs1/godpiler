//
// Created by Evan Shaw on 4/25/23.
//

#include "PrintLineStatementASTNode.h"
#include "../../Instruction/LoadInstruction.h"
#include "../../Instruction/MoveInstruction.h"
#include "../../Instruction/BranchLinkInstruction.h"
#include "../ExpASTNode/StringLiteralExpNode.h"

PrintLineStatementASTNode::PrintLineStatementASTNode(ExpASTNode *exp_node,
                                                     FunctionSymbolTableEntry *printf_symtab_entry, bool should_print_newline, bool int_format) : exp_node(
		exp_node), printf_symtab_entry(printf_symtab_entry), should_print_newline(should_print_newline), int_format(int_format) {

}

std::vector<Instruction *> PrintLineStatementASTNode::gen_3AC(int *symbolic_register_counter) {

	auto exp_list_3AC = exp_node->gen_3AC(symbolic_register_counter);

	//TODO: only doing ints for now

	//need a mov into r1 for the expression
	//this is before loading the format string into r0 because there is the chance that our input happens to be in r0
	Operand destination_r1 = Operand(OPERAND_TYPE_REGISTER, 1);
	Operand exp_result = exp_node->get_output_operand();
    MoveInstruction * mov_exp{};
    if (exp_result.getOperandType() == OPERAND_TYPE_REGISTER && exp_result.getOperandValue() == 1) {
        //if result is already in r1, no need to do anything... except check if the exp is a string literal, in which case we make it a string format print
        auto string_literal_node = dynamic_cast<StringLiteralExpNode *>(exp_node);
        if (string_literal_node != nullptr) {
            int_format = false;
        }
    } else {
        mov_exp = new MoveInstruction(destination_r1, exp_result);
    }

	//need an ldr into r0 for the string literal
    std::string format_string_label;
    std::string format_string_literal;
    if (!should_print_newline && !int_format) {
        format_string_label = "str_fmt_s";
        format_string_literal = "%s";
    } else if (!should_print_newline && int_format) {
        format_string_label = "str_fmt_d";
        format_string_literal = "%d";
    } else if (should_print_newline && !int_format) {
        format_string_label = "str_fmt_sn";
        format_string_literal = "%s\n";
    } else {
        format_string_label = "str_fmt_dn";
        format_string_literal = "%d\n";
    }
	Operand source_fmt_label = Operand(OPERAND_TYPE_LABEL, 0, format_string_label);
	Operand destination_r0 = Operand(OPERAND_TYPE_REGISTER, 0);

	auto ldr_format_string = new LoadInstruction(LOAD_INSTRUCTION_TYPE_LABEL, destination_r0, source_fmt_label);

	//need a bl instruction with printf label
	Operand label_printf = Operand(OPERAND_TYPE_LABEL, 0, std::string("printf"));
	auto bl_printf = new BranchLinkInstruction(label_printf, printf_symtab_entry);

    if (mov_exp != nullptr) {
        exp_list_3AC.push_back(mov_exp);
    }
	exp_list_3AC.push_back(ldr_format_string);
	exp_list_3AC.push_back(bl_printf);

	has_generated_3AC = true;

	return exp_list_3AC;
}

int PrintLineStatementASTNode::get_number_function_calls_in_children() {
	//this counts as a function call
	int n_function_calls = 1;
	n_function_calls += exp_node->get_number_function_calls_in_children();

	return n_function_calls;
}

