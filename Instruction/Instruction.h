//
// Created by Evan Shaw on 4/21/23.
//

#ifndef CPP_TEST_INSTRUCTION_H
#define CPP_TEST_INSTRUCTION_H


#include <string>
#include <unordered_set>
#include <set>
#include "Operand.h"
//#include "../Liveness/LivenessTableEntry.h"



/*
 * a = b + c
 * a = b - c
 * a = b * c
 * a = b / c
 *
 * a = b
 *
 * a = b & c
 * a = b | c
 *
 * a = b < c
 * a = b <= c
 * a = b == c
 * a = b > c
 * a = b >= c
 *
 * if a < b goto _label
 * if a <= b goto _label
 * if a == b goto _label
 * if a > b goto _label
 * if a >= b goto _label
 *
 * goto _label
 *
 * call _label
 *
 * ex:
 * %a1 = 0
 *
 *
 */

/*
 * Abstract class representing and instruction. Should behave more like an interface
 *
 * should later have interface methods for getting the livein and liveout of this instruction
 *
 */

class LivenessTableEntry;

class Instruction {

protected:
	int naive_add_operand_to_set(std::set<Operand> &set, Operand op);

	//Pointer to the liveness table entry that contains this instruction. This
	//is for determining the successors of each instruction in liveness analysis.
	LivenessTableEntry *parent_liveness_table_entry{nullptr};

public:

	LivenessTableEntry *get_parent_liveness_table_entry();

	void set_parent_liveness_table_entry(LivenessTableEntry *entry);

	virtual std::string to_string() = 0;

	virtual std::set<Operand> get_use_set() = 0;

	virtual std::set<Operand> get_def_set() = 0;

	virtual void replace_operands(Operand to_replace, Operand replacer) = 0;

};


#endif //CPP_TEST_INSTRUCTION_H
