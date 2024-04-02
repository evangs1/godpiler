//
// Created by Evan Shaw on 4/25/23.
//

#include <iostream>
#include "LivenessTableEntry.h"
#include "../StaticHelperFunctions.h"

LivenessTableEntry::LivenessTableEntry(Instruction *instruction) : instruction(instruction) {
	successors = std::vector<LivenessTableEntry *>();
	use_set = instruction->get_use_set();
	def_set = instruction->get_def_set();
	live_in = std::set<Operand>();
	live_out = std::set<Operand>();
	live_in_prev_iteration = std::set<Operand>();
	live_out_prev_iteration = std::set<Operand>();
	instruction->set_parent_liveness_table_entry(this);
	index_in_table = 0;
}

std::string LivenessTableEntry::to_string() {

	std::string instr_string = instruction->to_string();
	padTo(instr_string, 25);

	std::string use_set_string;
	for (auto u : use_set) {
		use_set_string += u.to_string();
		use_set_string += " ";
	}
	padTo(use_set_string, 15);

	std::string def_set_string;
	for (auto d : def_set) {
		def_set_string += d.to_string();
		def_set_string += " ";
	}
	padTo(def_set_string, 15);

	std::string successors_string;
	for (auto s : successors) {
		successors_string += std::to_string(s->index_in_table);
		successors_string += " ";
	}
	padTo(successors_string, 10);


	std::string live_out_prev_string;
	for (auto lop : live_out_prev_iteration) {
		live_out_prev_string += lop.to_string();
		live_out_prev_string += " ";
	}
	padTo(live_out_prev_string, 36);

	std::string live_in_prev_string;
	for (auto lip : live_in_prev_iteration) {
		live_in_prev_string += lip.to_string();
		live_in_prev_string += " ";
	}
	padTo(live_in_prev_string, 36);




	std::string live_out_string;
	for (auto lo : live_out) {
		live_out_string += lo.to_string();
		live_out_string += " ";
	}
	padTo(live_out_string, 36);

	std::string live_in_string;
	for (auto li : live_in) {
		live_in_string += li.to_string();
		live_in_string += " ";
	}
	padTo(live_in_string, 36);





	//TODO: add live_in and live_out later!!!



	return instr_string + use_set_string + def_set_string + successors_string + live_in_prev_string + live_out_prev_string + live_in_string + live_out_string;
}
