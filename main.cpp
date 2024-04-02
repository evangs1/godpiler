
#include <iostream>
#include <stack>
#include <fstream>
#include "ASTNode/ExpASTNode/ExpASTNode.h"
#include "ASTNode/ExpASTNode/NormalOperationExpASTNode.h"
#include "ASTNode/ExpASTNode/VariableReferenceExpASTNode.h"
#include "ASTNode/ExpASTNode/IntegerLiteralExpASTNode.h"
#include "SymbolTable/SymbolTable.h"
#include "ASTNode/StatementASTNode/AssignmentStatementASTNode.h"
#include "ASTNode/StatementASTNode/PrintLineStatementASTNode.h"
#include "ASTNode/StatementASTNode/StatementsASTNode.h"
#include "ASTNode/ExpASTNode/MethodCallExpASTNode.h"
#include "ASTNode/StatementASTNode/ReturnStatementASTNode.h"
#include "ASTNode/ExpASTNode/BooleanOperationExpASTNode.h"
#include "ASTNode/StatementASTNode/IfElseStatementASTNode.h"
#include "ASTNode/StatementASTNode/WhileStatementASTNode.h"
#include "Liveness/LivenessTable.h"
#include "Interference/InterferenceGraph.h"
#include "Coloring/ChaitinBriggsColorer.h"
#include "ASTNode/FunctionASTNode.h"
#include "Instruction/PushInstruction.h"
#include "Instruction/PopInstruction.h"
#include "Instruction/SaveCalleeSavedRegistersPlaceholderInstruction.h"
#include "Instruction/FunctionReturnPlaceholderInstruction.h"
#include "Instruction/NormalOperationInstruction.h"
#include "Instruction/ExtendStackPointerPlaceholderInstruction.h"
#include "Instruction/RetractStackPointerPlaceholderInstruction.h"
#include "Instruction/BranchLinkInstruction.h"
#include "Instruction/MoveInstruction.h"
#include "Parsing/ASTConstructor.cpp"

extern "C" {
    extern FILE *yyin;
#include "Parsing/lexer.h"
#include "Parsing/parser.h"
}
//int yyparse();

extern struct ASTNode* root;



int main(int argc, char* argv[] ) {


    yyin = fopen( argv[1], "r" );
    if (yyin == NULL) {
        std::cout << "couldn't find file" << std::endl;
    }
    std::cout << "opened file" << std::endl;
    if (yyparse() != 0)
        return 1;

    std::cout << "finished parsing" << std::endl;

    auto ast_constructor = ASTConstructor(root);



/*
 stuff inside this multiline comment is working

	//static variables?
	SymbolTable *symbol_table;
	std::vector<FunctionASTNode *> functions;



	//construct simple symbol table
	auto symtab = SymbolTable();

	auto add_two_ints_func = FunctionSymbolTableEntry(VARIABLE_TYPE_INT, std::string("add_two_ints"), 0, false, 2, false);
	auto var_input_1 = VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string("i1"), 0, false, true);
	auto var_input_2 = VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string("i2"), 0, false, true);
	add_two_ints_func.add_entry(&var_input_1);
	add_two_ints_func.add_entry(&var_input_2);

	auto main_func = FunctionSymbolTableEntry(VARIABLE_TYPE_VOID, std::string("main"), 0, true, 0, false);
	auto printf_func = FunctionSymbolTableEntry(VARIABLE_TYPE_VOID, std::string("printf"), 0, false, 2, true);
	auto var_a = VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string("a"), 0, false, false);
	auto var_b = VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string("b"), 0, false, false);
	main_func.add_entry(&var_a);
	std::cout << main_func.to_string() << std::endl;


 */


	//construct a simple exp AST tree just as an example

	//a
//	auto var_ref = VariableReferenceASTNode(&var_a);
//
//	int global_symbolic_register_counter = 0;
//	//a (exp)
//	auto l = VariableReferenceExpASTNode(&var_ref);
//	//2 (exp)
//	auto r = IntegerLiteralExpASTNode(2);
//
//	//a + 2 (exp)
//	auto plus = NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_ADDITION, &l, &r);
//
//	//a = a + 2
//	auto assignment = AssignmentStatementASTNode(&var_ref, &plus);
//
//	auto print_a = PrintLineStatementASTNode(&l);
//
//	auto statements = StatementsASTNode();
//	statements.add_statement(&assignment);
//	statements.add_statement(&print_a);
//
//
//
//	auto second_func_symtab_entry = FunctionSymbolTableEntry(VARIABLE_TYPE_INT, std::string("function1"), 0, false);
//	auto exp_arg_list = std::vector<ExpASTNode *>();
//	exp_arg_list.push_back(&l);
//	auto four = IntegerLiteralExpASTNode(4);
//	exp_arg_list.push_back(&four);
//	auto call_func = MethodCallExpASTNode(&second_func_symtab_entry, exp_arg_list);
//	auto print_func = PrintLineStatementASTNode(&call_func);
//	statements.add_statement(&print_func);
//	auto ret = ReturnStatementASTNode(&main_func, &l);
//	statements.add_statement(&ret);
//	auto list_3AC = statements.gen_3AC(&global_symbolic_register_counter);
//
//	for (Instruction *i : list_3AC) {
//		std::cout << i->to_string() << std::endl;
//	}










//	auto a_ref = VariableReferenceASTNode(&var_a);
//	auto b_ref = VariableReferenceASTNode(&var_b);
//	int global_symbolic_register_counter = 0;
//	auto a_ref_exp = VariableReferenceExpASTNode(&a_ref);
//	auto b_ref_exp = VariableReferenceExpASTNode(&b_ref);
//
//	auto literal_2 = IntegerLiteralExpASTNode(2);
//	auto literal_4 = IntegerLiteralExpASTNode(4);
//	auto assignment = AssignmentStatementASTNode(&a_ref, &literal_2);
//	auto assignment2 = AssignmentStatementASTNode(&b_ref, &literal_4);
//	auto if_exp = BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_LESS_THAN, &a_ref_exp, &b_ref_exp);
//	auto literal_1 = IntegerLiteralExpASTNode(1);
//	auto literal_0 = IntegerLiteralExpASTNode(0);
//	auto print_1 = PrintLineStatementASTNode(&literal_1);
//	auto print_0 = PrintLineStatementASTNode(&literal_0);
//
//	auto statements = StatementsASTNode();
//	statements.add_statement(&assignment);
//	statements.add_statement(&assignment2);
//
//	auto true_statements = StatementsASTNode();
//	auto false_statements = StatementsASTNode();
//	true_statements.add_statement(&print_1);
//	false_statements.add_statement(&print_0);
//
//	auto if_else = IfElseStatementASTNode(&if_exp, &true_statements, &false_statements);
//	statements.add_statement(&if_else);
//
//	auto list_3AC = statements.gen_3AC(&global_symbolic_register_counter);
//
//	for (Instruction *i : list_3AC) {
//		std::cout << i->to_string() << std::endl;
//	}













/*

 stuff inside this multi-line comment is working

	auto input_1_ref = VariableReferenceASTNode(&var_input_1);
	auto input_2_ref = VariableReferenceASTNode(&var_input_2);
	auto input_1_ref_exp = VariableReferenceExpASTNode(&input_1_ref);
	auto input_2_ref_exp = VariableReferenceExpASTNode(&input_2_ref);



	auto plus = NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_ADDITION, &input_1_ref_exp, &input_2_ref_exp);


	auto return_from_add_func = ReturnStatementASTNode(&add_two_ints_func, &plus);
	auto add_func_statements = StatementsASTNode();
	add_func_statements.add_statement(&return_from_add_func);
	auto add_func = FunctionASTNode(&add_func_statements, &add_two_ints_func, false);
	functions.push_back(&add_func);


	auto a_ref = VariableReferenceASTNode(&var_a);
	//auto b_ref = VariableReferenceASTNode(&var_b);
	int global_symbolic_register_counter = 0;
	auto a_ref_exp = VariableReferenceExpASTNode(&a_ref);
	//auto b_ref_exp = VariableReferenceExpASTNode(&b_ref);

	//auto literal_2 = IntegerLiteralExpASTNode(2);
	auto literal_10 = IntegerLiteralExpASTNode(10);
	auto literal_0 = IntegerLiteralExpASTNode(0);
	auto assignment = AssignmentStatementASTNode(&a_ref, &literal_0);
	//auto assignment2 = AssignmentStatementASTNode(&b_ref, &literal_4);
	auto while_exp = BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_LESS_THAN, &a_ref_exp, &literal_10);
	auto literal_1 = IntegerLiteralExpASTNode(1);

	auto print_a = PrintLineStatementASTNode(&a_ref_exp, &printf_func);
	//auto print_0 = PrintLineStatementASTNode(&literal_0);

	auto a_plus_1 = NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_ADDITION, &a_ref_exp, &literal_1);
	auto a_assign = AssignmentStatementASTNode(&a_ref, &a_plus_1);


	auto statements = StatementsASTNode();
	statements.add_statement(&assignment);
	//statements.add_statement(&assignment2);

	auto loop_body = StatementsASTNode();
	loop_body.add_statement(&a_assign);
	loop_body.add_statement(&print_a);

	auto while_stmt = WhileStatementASTNode(&while_exp, &loop_body);
	statements.add_statement(&while_stmt);

	FunctionASTNode func = FunctionASTNode(&statements, &main_func, true);

	functions.push_back(&func);

//	auto list_3AC = func.gen_3AC(&global_symbolic_register_counter);
//
//	for (Instruction *i : list_3AC) {
//		std::cout << i->to_string() << std::endl;
//	}

//	std::cout << std::endl << std::endl;

//	auto reg_asn = ChaitinBriggsColorer(list_3AC);

//	for (Instruction *i : reg_asn.gen_3AC()) {
//		std::cout << i->to_string() << std::endl;
//	}


//	auto lv_table = LivenessTable(list_3AC);
//	lv_table.print_table();

//	InterferenceGraph interference_graph = InterferenceGraph(&lv_table);
//	//interference_graph.hide_node(interference_graph.interference_node_table[0]);
//	std::cout << interference_graph.to_string() << std::endl << std::endl;







*/


    char buf[200];
    strcpy(buf, argv[1]);
    char * p = strchr(buf, '.');
    strcpy(p, ".s\0");

    std::ofstream output_file;
    output_file.open(buf);
    output_file << ".global main" << std::endl;
    output_file << ".extern printf" << std::endl;
    output_file << ".extern atoi" << std::endl;
    output_file << ".section .text" << std::endl << std::endl;

    output_file << ast_constructor.symtab->string_literals_to_string();

    std::cout << ast_constructor.symtab->string_literals_to_string();
    output_file << ".align" << std::endl << std::endl;


	for (auto function : ast_constructor.function_list) {
		int symbolic_register_counter = 0;
		bool is_leaf_node = function->get_number_function_calls_in_children() <= 0;

		ChaitinBriggsColorer cbc = ChaitinBriggsColorer(function->gen_3AC(&symbolic_register_counter), is_leaf_node);

		auto instruction_list = cbc.gen_3AC();
		int extend_sp_amount = cbc.get_calculated_sp_offset();
		auto extend_sp = new NormalOperationInstruction(
				NORMAL_OPERATION_INSTRUCTION_TYPE_SUBTRACTION, Operand(OPERAND_TYPE_REGISTER, 13),
				Operand(OPERAND_TYPE_REGISTER, 13), Operand(OPERAND_TYPE_LITERAL, extend_sp_amount));

		auto *retract_sp = new NormalOperationInstruction(
				NORMAL_OPERATION_INSTRUCTION_TYPE_SUBTRACTION, Operand(OPERAND_TYPE_REGISTER, 13),
				Operand(OPERAND_TYPE_REGISTER, 13), Operand(OPERAND_TYPE_LITERAL, extend_sp_amount));

		std::set<int> registers_used_in_program = cbc.get_registers_used_in_program();
		std::vector<Operand> callee_saved_operands = std::vector<Operand>();
		for (int r : registers_used_in_program) {
			if (r >= 4) {
				callee_saved_operands.emplace_back(OPERAND_TYPE_REGISTER, r);
			}
		}
        std::vector<Operand> push_registers;
        std::vector<Operand> pop_registers;
        //if function is main, we don't have to save all the callee-saved registers
        if (!function->get_is_main_function()) {
            push_registers = callee_saved_operands;
            pop_registers = callee_saved_operands;
        }




        //add r14 (lr) to push
		push_registers.emplace_back(OPERAND_TYPE_REGISTER, 14);
		//add r15 (pc) to push
		pop_registers.emplace_back(OPERAND_TYPE_REGISTER, 15);
		//construct push and pop
		auto *push = new PushInstruction(push_registers);
		auto *pop = new PopInstruction(pop_registers);

		for(auto it = instruction_list.begin(); it != instruction_list.end();) {
			auto extend_sp_placeholder = dynamic_cast<ExtendStackPointerPlaceholderInstruction *>(*it);
			if (extend_sp_placeholder != nullptr) {
				if (extend_sp_amount > 0) {
					*it = extend_sp;
					it++;
					continue;
				} else {
					it = instruction_list.erase(it);
					continue;
				}
			}
			auto retract_sp_placeholder = dynamic_cast<RetractStackPointerPlaceholderInstruction *>(*it);
			if (retract_sp_placeholder != nullptr) {
				if (extend_sp_amount > 0) {
					*it = extend_sp;
					it++;
					continue;
				} else {
					it = instruction_list.erase(it);
					continue;
				}
			}
			it++;
		}

//			//TODO: CHECK OUT THE INDEXES ON THIS, IS IT CORRECT???
//
//		for (int index = 0; index < instruction_list.size(); index++) {
//			Instruction *&instr = instruction_list[index];
//
//			auto extend_sp_placeholder = dynamic_cast<ExtendStackPointerPlaceholderInstruction *>(instr);
//			if (extend_sp_placeholder != nullptr) {
//				if (extend_sp_amount > 0) {
//					instr = extend_sp;
//					continue;
//				} else {
//					//remove placeholder instruction from list if sp does not need to be modified, dont increment index
//					instruction_list.erase(instruction_list.begin() + index);
//					index--;
//					continue;
//				}
//			}
//			auto retract_sp_placeholder = dynamic_cast<RetractStackPointerPlaceholderInstruction *>(instr);
//			if (retract_sp_placeholder != nullptr) {
//				if (extend_sp_amount > 0) {
//					instr = retract_sp;
//					continue;
//				} else {
//					//remove placeholder instruction from list if sp does not need to be modified, dont increment index
//					instruction_list.erase(instruction_list.begin() + index);
//					index--;
//					continue;
//				}
//			}
//		}

		for (auto &i : instruction_list) {
			auto callee_placeholder = dynamic_cast<SaveCalleeSavedRegistersPlaceholderInstruction *>(i);

			if (callee_placeholder != nullptr) {
				i = push;
				continue;
			}
			auto ret_placeholder = dynamic_cast<FunctionReturnPlaceholderInstruction *>(i);
			if (ret_placeholder != nullptr) {
				i = pop;
				continue;
			}
		}

//		//next we remove redundant moves (this code block is sus; I don't like messing with the index)
//		for (int index = 0; index < instruction_list.size(); index++) {
//			Instruction *&instr = instruction_list[index];
//
//			auto mov = dynamic_cast<MoveInstruction *>(instr);
//			if (mov != nullptr) {
//				if (mov->get_destination_operand() == mov->get_source_operand()) {
//					instruction_list.erase(instruction_list.begin() + index);
//					index--;
//				}
//			}
//		}

		//next we remove redundant moves
		for(auto it = instruction_list.begin(); it != instruction_list.end();) {
			auto mov = dynamic_cast<MoveInstruction *>(*it);
			if (mov != nullptr) {
				if (mov->get_destination_operand() == mov->get_source_operand()) {
					it = instruction_list.erase(it);
				} else {
					it++;
					continue;
				}
			} else {
				it++;
			}
		}


		//last we need to insert push and pop instructions to save caller-saved registers that interfere with function nodes

        auto size = instruction_list.size();
        for (std::vector<Instruction *>::size_type i = 0; i < size; ++i) {
            auto * bl = dynamic_cast<BranchLinkInstruction *>(instruction_list[i]);
            if (bl != nullptr) {
                if (!bl->register_list_save_restore.empty()) {
                    auto push_regs = new PushInstruction(bl->register_list_save_restore);
                    auto pop_regs = new PopInstruction(bl->register_list_save_restore);
                    instruction_list.insert(instruction_list.begin() + i, push_regs);
                    instruction_list.insert(instruction_list.begin() + i + 2, pop_regs);
                    i += 2;
                }
            }
        }

		for (Instruction *i : instruction_list) {
			auto * bl = dynamic_cast<BranchLinkInstruction *>(i);
			if (bl != nullptr) {
				if (!bl->register_list_save_restore.empty()) {
                    //wtf is the purpose of this code block?
					std::cout << "function call needs to save registers" << std::endl;
				}
			}
		}

        //loops through resultant instruction list and prints the instructions to file

        for (Instruction *i : instruction_list) {
            std::cout << i->to_string() << std::endl;
            output_file << i->to_string() << std::endl;
        }
        output_file << std::endl;


	}


    output_file.close();

	return 0;


}
