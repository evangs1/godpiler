//
// Created by Evan Shaw on 4/25/23.
//

#include <iostream>
#include "LivenessTable.h"
#include "../Instruction/BranchInstruction.h"
#include "../Instruction/ConditionalBranchInstruction.h"

void print_dash(int n_dashes) {
	for (int n = 0; n < n_dashes; n++) {
		std::cout << "-";
	}
}

void LivenessTable::print_table() {
	auto i = std::string("INSTRUCTION");
	padTo(i, 29);
	auto u = std::string("USE");
	padTo(u, 15);
	auto d = std::string("DEF");
	padTo(d, 15);
	auto s = std::string("SUCC");
	padTo(s, 10);


	auto lip = std::string("LVIN PREV");
	padTo(lip, 36);
	auto lop = std::string("LVOUT PREV");
	padTo(lop, 36);


	auto li = std::string("LVIN");
	padTo(li, 36);
	auto lo = std::string("LVOUT");
	padTo(lo, 36);

	std::cout << i << u << d << s << lip << lop << li << lo << std::endl;
	int index = 0;
	for (auto entry : table) {
		print_dash(29 + 15 + 15 + 10 + 36 + 36 + 36 + 36);
//		for (auto succ : entry.successors) {
//			std::cout << succ->index_in_table << std::endl;
//		}



		std::cout << std::endl;
		std::string table_index = std::to_string(index);
		padTo(table_index, 4);
		std::cout << table_index;
		std::cout << entry->to_string() << std::endl;
		index++;
	}

}


LivenessTable::LivenessTable(std::vector<Instruction *> table_input) {
	//add every instruction to a LivenessTableEntry and put in the table

	int table_index = 0;
	for (auto instr : table_input) {
		auto entry = new LivenessTableEntry(instr);
		entry->index_in_table = table_index;
		table_index++;
		table.push_back(entry);
	}
	//loop through LivenessTableEntries. if an entry's instruction is a branch instruction(or a conditional branch from
	// inheritance), then add its target label to its successors list
	int index = 0;
	for (auto &entry : table) {
		bool successor_is_next = true;
		auto b = dynamic_cast<BranchInstruction *>(entry->instruction);
		if (b != nullptr) {
			entry->successors.push_back(b->get_branch_target_label_pointer()->get_parent_liveness_table_entry());
			//now try and cast to ConditionalBranchInstruction
			auto bcond = dynamic_cast<ConditionalBranchInstruction *>(b);
			if (bcond == nullptr) {
				//if it is not a ConditionalBranchInstruction, that means it is a normal branch, and there is no way
				//that its successor is the next instruction
				successor_is_next = false;
			}
		}
		//if an instruction has a next successor, put it in successors list
		if (successor_is_next && index < table.size() - 1) {
			entry->successors.push_back(table[index + 1]);
		}

//		for (auto succ : entry.successors) {
//			std::cout << "AAA:" << succ->index_in_table << std::endl;
//		}

		index++;
	}


	//now start doing liveness algo
	int iterations = 0;
	bool previous_equals_current = false;
	while (!previous_equals_current) {
		for (auto i = table.rbegin(); i != table.rend(); ++i) {
			LivenessTableEntry *entry_ptr = *i;
			// in’[n] := in[n]; out’[n] := out[n]
			entry_ptr->live_in_prev_iteration = entry_ptr->live_in;
			entry_ptr->live_out_prev_iteration = entry_ptr->live_out;

			// out[n] := ∪ {in[s] | s ε succ[n]}
			std::set<Operand> union_in_of_successors;
			for (auto succ : entry_ptr->successors) {
				//			std::set_union(union_in_of_successors.begin(), union_in_of_successors.end(),
				//			               set_2.begin(), set_2.end(),
				//			               std::back_inserter(union_in_of_successors));
				for (const auto &operand_in_live_in : succ->live_in) {
					union_in_of_successors.insert(operand_in_live_in);
				}
			}
			entry_ptr->live_out = union_in_of_successors;


			// in[n] := use[n] ∪ (out[n] - def[n])
			std::vector<Operand> out_minus_def;
			std::set_difference(entry_ptr->live_out.begin(), entry_ptr->live_out.end(),
			                    entry_ptr->def_set.begin(), entry_ptr->def_set.end(),
			                    std::inserter(out_minus_def, out_minus_def.begin()));

//			//put it back into a set (ig the only reason to do this is to ensure they are sorted???)
//			std::set<Operand> set_out_minus_def(out_minus_def.begin(), out_minus_def.end());

			std::set<Operand> use_union_out_minus_def;
			std::set_union(entry_ptr->use_set.begin(), entry_ptr->use_set.end(),
			               out_minus_def.begin(), out_minus_def.end(),
			               std::inserter(use_union_out_minus_def, use_union_out_minus_def.begin()));

			//TODO: should this be copy, or should it be union???
			entry_ptr->live_in = use_union_out_minus_def;


		}

		//loop through again to check if current iteration was the same as the last one
		bool are_same = true;
		for (auto i = table.rbegin(); i != table.rend(); ++i) {
			LivenessTableEntry *entry_ptr = *i;
			if (entry_ptr->live_in == entry_ptr->live_in_prev_iteration) {
				//std::cout << "SAME IN : " << entry_ptr->index_in_table << std::endl;

				if (entry_ptr->live_out == entry_ptr->live_out_prev_iteration) {
					//std::cout << "SAME OUT : " << entry_ptr->index_in_table << std::endl;

				} else {
					are_same = false;
					break;
				}
			} else {
				are_same = false;
				break;
			}
		}
		previous_equals_current = are_same;
//		if (iterations > 10) {
//			break;
//		} else {
//			iterations++;
//		}
		this->print_table();
		std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
	}

}


