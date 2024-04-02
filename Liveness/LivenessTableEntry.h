//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_LIVENESSTABLEENTRY_H
#define CPP_TEST_LIVENESSTABLEENTRY_H


#include <vector>
#include <unordered_set>
#include "../Instruction/Instruction.h"
#include "../StaticHelperFunctions.h"


class LivenessTableEntry {

private:


public:
	explicit LivenessTableEntry(Instruction * instruction);

	//bool next_instruction_is_successor;
	Instruction * instruction;
	std::vector<LivenessTableEntry *> successors; //does this contain the next instruction??? -> yes
	std::set<Operand> use_set;
	std::set<Operand> def_set;
	std::set<Operand> live_in;
	std::set<Operand> live_out;
	std::set<Operand> live_in_prev_iteration;
	std::set<Operand> live_out_prev_iteration;

	int index_in_table{0};

	std::string to_string();
	//void compute_use_set();
};


#endif //CPP_TEST_LIVENESSTABLEENTRY_H
