//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_LIVENESSTABLE_H
#define CPP_TEST_LIVENESSTABLE_H


#include "LivenessTableEntry.h"

class LivenessTable {

private:


public:
	LivenessTable(std::vector<Instruction *> table_input);

	std::vector<LivenessTableEntry *> table;
	//maybe make this a to_string function later
	void print_table();

};


#endif //CPP_TEST_LIVENESSTABLE_H
