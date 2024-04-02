//
// Created by Evan Shaw on 4/27/23.
//

#include <stack>
#include <iostream>
#include "ChaitinBriggsColorer.h"
#include "../Instruction/BranchLinkInstruction.h"

bool ChaitinBriggsColorer::perform_coloring(InterferenceGraph *interference_graph) {
	auto coloring_stack = std::stack<InterferenceNode *>();

	//declare an array of used registers, find out what registers are already in use, and add them to array
	//and also set the assigned register for nodes that are already registers
	bool used_registers[USED_REGISTERS_ARRAY_SIZE]{false};

	//TODO: loop through nodes and determine if node is a real register
	for (auto node : interference_graph->interference_node_table) {
		if (node->node_operand.getOperandType() == OPERAND_TYPE_REGISTER) {
			int register_value = node->node_operand.getOperandValue();
			if (register_value >= 0 && register_value < USED_REGISTERS_ARRAY_SIZE) {
				used_registers[register_value] = true;
				node->assigned_register = register_value;
			} else {
				std::cout << "REGISTER OUT OF BOUNDS IN COLORER - CRITICAL ERROR" << std::endl;
				exit(1);
			}
		}
	}

	InterferenceNode *lowest_degree_node = interference_graph->get_lowest_degree_node();
	while (lowest_degree_node != nullptr) {

		//TODO: should be a method associated with InterferenceNode class
		interference_graph->hide_node(lowest_degree_node);

//		//if is already a register, then add to array and assign register
//		if (lowest_degree_node->node_operand.getOperandType() == OPERAND_TYPE_REGISTER) {
//			used_registers[lowest_degree_node->node_operand.getOperandValue()] = true;
//			lowest_degree_node->assigned_register = lowest_degree_node->node_operand.getOperandValue();
//		}
		coloring_stack.push(lowest_degree_node);

		lowest_degree_node = interference_graph->get_lowest_degree_node();
	}

	//now all nodes should be on the coloring stack
	std::cout << interference_graph->to_string() << std::endl << std::endl;

	//TODO: WHEN DO WE TAKE COPY PREFERENCE INTO ACCOUNT???
	//TODO: WHAT IF WE WANT TO ASSIGN A REGISTER ITS COPY PREFERENCE, BUT IT ENDS UP INTERFERING WITH A FUNCTION CALL???
	//TODO: WELL OBVIOUSLY ONLY TAKE COPY PREFERENCE INTO ACCOUNT IF

	//SOLUTION: WE CAN CHECK COPY PREFERENCE INSIDE THE DIFFERENT METHODS check_unused_callee_saved_registers...
	//          IF A NODE HAS A COPY PREFERENCE THAT IS INSIDE THE RANGE GIVEN BY THE FUNCTION, THEN ASSIGN THAT ONE

	while (!coloring_stack.empty()) {
		InterferenceNode *current_node = coloring_stack.top();
		std::cout << "popped: " << current_node->node_operand.to_string() << std::endl;
		coloring_stack.pop();
		interference_graph->unhide_node(current_node);
		//unassigned registers should have a value of -1
		if (current_node->assigned_register == -1) {
			//if node is unassigned
			//try to find a register that is used first
			int register_confirmed_non_conflict = INT32_MAX;
			bool found_register = false;

			if (is_leaf_node) {
				//is leaf function
				//check if already used caller is available
				int reg = -1;
				reg = check_used_caller_saved_registers(current_node, used_registers);
				if (reg != -1) {
					found_register = true;
					register_confirmed_non_conflict = reg;
					std::cout << "FOUND REG HERE 1" << std::endl;
				} else {
					reg = check_unused_caller_saved_registers(current_node, used_registers);
					if (reg != -1) {
						found_register = true;
						register_confirmed_non_conflict = reg;
						std::cout << "FOUND REG HERE 2" << std::endl;
					} else {
						reg = check_used_callee_saved_registers(current_node, used_registers);
						if (reg != -1) {
							found_register = true;
							register_confirmed_non_conflict = reg;
							std::cout << "FOUND REG HERE 3" << std::endl;
						} else {
							reg = check_unused_callee_saved_registers(current_node, used_registers);
							if (reg != -1) {
								found_register = true;
								register_confirmed_non_conflict = reg;
								std::cout << "FOUND REG HERE 4" << std::endl;
							} else {
								//SPILL
								std::cout << "SPILL POINT 1" << std::endl;
								exit(1);
							}
						}
					}
				}

				//if not, check if non-already used caller is available
				//if not, check if already used callee is available
				//if not, check if non-already used callee is available
				//if not, spill

			} else {
				//is stem function
				//loop through liveness table
				//count number of function calls that has this operand at its lvin AND is not in USE as count_a
				//count number of function calls that has this operand it its lvin AND is in the USE as count_b
				// if count_a > 0 take path a
				// else if count_b > 0 take path b
				// else take path c
				int count_n_function_calls_operand_lvin_not_use = 0;
				int count_n_function_calls_operand_lvin_use_lvout = 0;
				int count_n_function_calls_operand_lvin_use = 0;
				auto interfering_function_calls = std::vector<BranchLinkInstruction *>();
				for (auto table_entry : interference_graph->lv_table_pointer->table) {
					auto *bl = dynamic_cast<BranchLinkInstruction *>(table_entry->instruction);
					if (bl != nullptr) {
						if (table_entry->live_in.contains(current_node->node_operand) &&
						    !table_entry->use_set.contains(current_node->node_operand)) {
							interfering_function_calls.push_back(bl);
							count_n_function_calls_operand_lvin_not_use++;
						} else if ((table_entry->live_in.contains(current_node->node_operand)) &&
						           (table_entry->use_set.contains(current_node->node_operand)) &&
						           (table_entry->live_out.contains(current_node->node_operand))) {
							interfering_function_calls.push_back(bl);
							count_n_function_calls_operand_lvin_use_lvout++;
						} else if (table_entry->live_in.contains(current_node->node_operand) &&
						           table_entry->use_set.contains(current_node->node_operand)) {
							count_n_function_calls_operand_lvin_use++;
						}
					}
				}
				//these two are interfering function calls, if there are any interfering function calls, do the same thing
				if ((count_n_function_calls_operand_lvin_not_use > 0) ||
				    (count_n_function_calls_operand_lvin_use_lvout > 0)) {
					// path a:
					// try to assign callee-saved register first used then unused
					// if not successful, try to assign a caller-saved register
					// if we can assign caller saved register, need to attach it to the instruction, so we can generate
					// push and pop instructions later to save live caller-saved registers

					int reg = -1;
					reg = check_used_callee_saved_registers(current_node, used_registers);
					if (reg != -1) {
						found_register = true;
						register_confirmed_non_conflict = reg;
					} else {
						reg = check_unused_callee_saved_registers(current_node, used_registers);
						if (reg != -1) {
							found_register = true;
							register_confirmed_non_conflict = reg;
						} else {
							reg = check_used_caller_saved_registers(current_node, used_registers);
							if (reg != -1) {
								found_register = true;
								register_confirmed_non_conflict = reg;
								//attach here
								for (auto function_call_instruction : interfering_function_calls) {
									function_call_instruction->register_list_save_restore.emplace_back(
											OPERAND_TYPE_REGISTER, reg);
								}
							} else {
								reg = check_unused_caller_saved_registers(current_node, used_registers);
								if (reg != -1) {
									found_register = true;
									register_confirmed_non_conflict = reg;
									//attach here
									for (auto function_call_instruction : interfering_function_calls) {
										function_call_instruction->register_list_save_restore.emplace_back(
                                                OPERAND_TYPE_REGISTER, reg);
									}
								} else {
									//SPILL
									std::cout << "SPILL POINT 2" << std::endl;
									exit(1);
								}
							}
						}
					}

				} else if (count_n_function_calls_operand_lvin_use > 0) {
					//TODO: will this even ever happen??? bl instructions should first move arguments to r0, r1 ...
					//TODO:
					std::cout << "THIS SHOULD PROBABLY NEVER HAPPEN... (ChaitinBriggsColorer.cpp)" << std::endl;
					exit(1);
					//somehow prefer using the same caller saved registers that the argument uses, not sure if possible
					//else just fall back to callee saved-registers



				} else {
					//variable being assigned a register does not interfere with a method
					//assign caller first, then callee

					//try finding copy preference first
					for (auto edge : current_node->edge_list) {
						if ((edge->is_copy_edge) && (edge->node_pointer->assigned_register != -1)) {
							//check register can be assigned
							int prospective_register = edge->node_pointer->assigned_register;
							if (check_register_can_be_assigned(current_node, prospective_register)) {
								found_register = true;
								register_confirmed_non_conflict = prospective_register;
								break;
							}
						}
					}
					if (!found_register) {
						int reg = -1;
						reg = check_used_caller_saved_registers(current_node, used_registers);
						if (reg != -1) {
							found_register = true;
							register_confirmed_non_conflict = reg;
						} else {
							reg = check_unused_caller_saved_registers(current_node, used_registers);
							if (reg != -1) {
								found_register = true;
								register_confirmed_non_conflict = reg;
							} else {
								reg = check_used_callee_saved_registers(current_node, used_registers);
								if (reg != -1) {
									found_register = true;
									register_confirmed_non_conflict = reg;
								} else {
									reg = check_unused_callee_saved_registers(current_node, used_registers);
									if (reg != -1) {
										found_register = true;
										register_confirmed_non_conflict = reg;
									} else {
										//SPILL
										std::cout << "SPILL POINT 3" << std::endl;
										exit(1);
									}
								}
							}
						}
					}
				}
			}

			//now actually assign the register

			if (found_register) {
				current_node->assigned_register = register_confirmed_non_conflict;
			} else {
				//register could not be assigned, must spill
				std::cout << "SPILL POINT 4, SHOULD HAVE SPILLED ALREADY???" << std::endl;
				exit(1);
			}

		} else {
			//if is already assigned
		}
		registers_used_in_program.insert(current_node->assigned_register);


	}

	std::cout << interference_graph->to_string() << std::endl;

	for (auto node : interference_graph->interference_node_table) {
		operand_assignment_table.emplace_back(node->node_operand, node->assigned_register);
	}
	return true;
}

std::vector<Instruction *> ChaitinBriggsColorer::gen_3AC() {
	auto modified_instructions = std::vector<Instruction *>();

	for (auto &instruction : instructions) {
		for (const auto &pair : operand_assignment_table) {
			instruction->replace_operands(pair.first, Operand(OPERAND_TYPE_REGISTER, pair.second));
		}
		modified_instructions.push_back(instruction);
	}

	return modified_instructions;
}

ChaitinBriggsColorer::ChaitinBriggsColorer(std::vector<Instruction *> instruction_vector, bool is_leaf_node)
		: instructions(
		instruction_vector), is_leaf_node(is_leaf_node) {
	LivenessTable liveness_table = LivenessTable(instructions);
	InterferenceGraph interference_graph = InterferenceGraph(&liveness_table);

	if (perform_coloring(&interference_graph)) {
		//coloring was successful

	} else {
		//coloring was not successful, need to spill
		std::cout << "CANNOT ASSIGN A REGISTER - EXITING" << std::endl;
		exit(1);
	}
}

std::set<int> ChaitinBriggsColorer::get_registers_used_in_program() {
	return registers_used_in_program;
}

int ChaitinBriggsColorer::get_calculated_sp_offset() {
	return calculated_sp_offset;
}

//return -1 if found no registers
int
ChaitinBriggsColorer::check_used_caller_saved_registers(InterferenceNode *operating_node,
                                                        bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]) {
	int found_register = -1;

	//first check copy preferences within this range
	for (auto edge : operating_node->edge_list) {
		if ((edge->is_copy_edge) && (edge->node_pointer->assigned_register != -1) &&
		    (edge->node_pointer->assigned_register >= 0) && (edge->node_pointer->assigned_register < 4)) {
			//check register can be assigned
			std::cout << "FOUND COPY PREFERENCE: " << std::to_string(edge->node_pointer->assigned_register) << std::endl;

			int prospective_register = edge->node_pointer->assigned_register;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				//std::cout << "CONFIRMING COPY PREFERENCE REG" << std::to_string(edge->node_pointer->assigned_register) << std::endl;
				return found_register;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (!used_registers_array[i]) {
			int prospective_register = i;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				break;
			}
		}
	}
	return found_register;
}

int
ChaitinBriggsColorer::check_unused_caller_saved_registers(InterferenceNode *operating_node,
                                                          bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]) {
	int found_register = -1;

	//first check copy preferences within this range
	for (auto edge : operating_node->edge_list) {
		if ((edge->is_copy_edge) && (edge->node_pointer->assigned_register != -1) &&
		    (edge->node_pointer->assigned_register >= 0) && (edge->node_pointer->assigned_register < 4)) {
			//check register can be assigned
			std::cout << "FOUD COPY PREFERENCE: " << std::to_string(edge->node_pointer->assigned_register) << std::endl;

			int prospective_register = edge->node_pointer->assigned_register;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				return found_register;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (!used_registers_array[i]) {
			int prospective_register = i;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				break;
			}
		}
	}
	return found_register;
}

int
ChaitinBriggsColorer::check_used_callee_saved_registers(InterferenceNode *operating_node,
                                                        bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]) {
	int found_register = -1;

	//first check copy preferences within this range
	for (auto edge : operating_node->edge_list) {
		if ((edge->is_copy_edge) && (edge->node_pointer->assigned_register != -1) &&
		    (edge->node_pointer->assigned_register >= 4) &&
		    (edge->node_pointer->assigned_register < USED_REGISTERS_ARRAY_SIZE)) {
			//check register can be assigned
			std::cout << "FOUD COPY PREFERENCE: " << std::to_string(edge->node_pointer->assigned_register) << std::endl;

			int prospective_register = edge->node_pointer->assigned_register;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				return found_register;
			}
		}
	}

	for (int i = 4; i < USED_REGISTERS_ARRAY_SIZE; i++) {
		if (!used_registers_array[i]) {
			int prospective_register = i;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				break;
			}
		}
	}
	return found_register;
}

int
ChaitinBriggsColorer::check_unused_callee_saved_registers(InterferenceNode *operating_node,
                                                          bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]) {
	int found_register = -1;

	//first check copy preferences within this range
	for (auto edge : operating_node->edge_list) {
		if ((edge->is_copy_edge) && (edge->node_pointer->assigned_register != -1) &&
		    (edge->node_pointer->assigned_register >= 4) &&
		    (edge->node_pointer->assigned_register < USED_REGISTERS_ARRAY_SIZE)) {
			//check register can be assigned
			std::cout << "FOUD COPY PREFERENCE: " << std::to_string(edge->node_pointer->assigned_register) << std::endl;
			int prospective_register = edge->node_pointer->assigned_register;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				return found_register;
			}
		}
	}

	for (int i = 4; i < USED_REGISTERS_ARRAY_SIZE; i++) {
		if (!used_registers_array[i]) {
			int prospective_register = i;
			if (check_register_can_be_assigned(operating_node, prospective_register)) {
				found_register = prospective_register;
				break;
			}
		}
	}
	return found_register;
}

bool ChaitinBriggsColorer::check_register_can_be_assigned(InterferenceNode *operating_node, int prospective_register) {
	bool prospective_register_conflicts_with_nodes = false;
	for (auto edge : operating_node->edge_list) {
		//pay attention only to the ones that are not hidden, or are already assigned (but still hidden)
		if (!edge->is_copy_edge) {
			//doesn't matter if edge is hidden or not?????
			//if ((!edge->is_hidden) || (edge->node_pointer->assigned_register != -1) ) {
			if (edge->node_pointer->assigned_register == prospective_register) {
				prospective_register_conflicts_with_nodes = true;
				std::cout << "CONFLICTING NODE: " << edge->node_pointer->assigned_register << std::endl;
				break;
			}
		}
	}
	return !prospective_register_conflicts_with_nodes;
}

