//
// Created by Evan Shaw on 4/25/23.
//

#include "FunctionASTNode.h"
#include "../Instruction/SaveCalleeSavedRegistersPlaceholderInstruction.h"
#include "../Instruction/ExtendStackPointerPlaceholderInstruction.h"
#include "../Instruction/FunctionReturnPlaceholderInstruction.h"
#include "../Instruction/LabelInstruction.h"
#include "../Instruction/RetractStackPointerPlaceholderInstruction.h"
#include "../Instruction/MoveInstruction.h"

std::vector<Instruction *> FunctionASTNode::gen_3AC(int *symbolic_register_counter) {
	auto instr_list = std::vector<Instruction *>();
	//first the label:
	LabelInstruction * function_label;
	//not sure if this if statement is needed
	if (is_main_function) {
		function_label = new LabelInstruction(std::string("main"));
	} else {
		function_label = new LabelInstruction(function_symtab_entry_pointer->get_function_id());
	}
	instr_list.push_back(function_label);

	//so we need to save callee-saved registers at the beginning

	auto callee_save = new SaveCalleeSavedRegistersPlaceholderInstruction();
	instr_list.push_back(callee_save);

	//modify stack pointer to make room for spills (maybe not required at all lol???)
	auto extend_sp = new ExtendStackPointerPlaceholderInstruction();
	instr_list.push_back(extend_sp);

	//TODO: NEED TO GENERATE A SERIES OF MOVES FROM THE REGISTERS THE ARGUMENTS ARE PASSED THROUGH TO NAMED VARIABLES
	//TODO: !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//don't do if there are more than four args (but should be pretty impossible anyway)
    if (function_symtab_entry_pointer->get_function_needs_program_args()) {
        //find string args variable symtab entry
        auto arg_list = function_symtab_entry_pointer->get_argument_variables_symtab_entries();
        VariableSymbolTableEntry * args_var_symtab_entry = nullptr;
        for (auto f : arg_list) {
            if (f->get_var_id() == std::string("args")) {
                args_var_symtab_entry = f;
                break;
            }
        }
        auto move_string_arg = new MoveInstruction(Operand(OPERAND_TYPE_VARIABLE_REFERENCE, 0, args_var_symtab_entry), Operand(OPERAND_TYPE_REGISTER, 1));
        instr_list.push_back(move_string_arg);
    } else {
        int original_source_register = 0;
        for (auto arg: function_symtab_entry_pointer->get_argument_variables_symtab_entries()) {
            auto move_arg = new MoveInstruction(Operand(OPERAND_TYPE_VARIABLE_REFERENCE, 0, arg),
                                                Operand(OPERAND_TYPE_REGISTER, original_source_register));
            instr_list.push_back(move_arg);
            original_source_register++;
        }
    }
	auto function_body_instructions = statements->gen_3AC(symbolic_register_counter);
	instr_list.insert(instr_list.end(), function_body_instructions.begin(), function_body_instructions.end());

	auto retract_sp = new RetractStackPointerPlaceholderInstruction();
	instr_list.push_back(retract_sp);

	//then at the end, insert return only if method is void, otherwise, return should be covered, maybe by typechecking???
	//TODO: check if i should be doing this, think so but still
	if (function_symtab_entry_pointer->get_return_type() == VARIABLE_TYPE_VOID) {
		auto ret_if_void = new FunctionReturnPlaceholderInstruction(function_symtab_entry_pointer);
		instr_list.push_back(ret_if_void);
	}

	return instr_list;
}

FunctionASTNode::FunctionASTNode(StatementsASTNode *statements, FunctionSymbolTableEntry *function_symtab_entry_pointer,
                                 bool is_main_function) : statements(statements),
                                                          function_symtab_entry_pointer(function_symtab_entry_pointer),
                                                          is_main_function(is_main_function) {

}

int FunctionASTNode::get_number_function_calls_in_children() {
	int n_function_calls = 0;
	n_function_calls += statements->get_number_function_calls_in_children();
	return n_function_calls;
}

bool FunctionASTNode::get_is_main_function() {
    return is_main_function;
}
