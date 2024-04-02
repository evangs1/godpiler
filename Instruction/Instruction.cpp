//
// Created by Evan Shaw on 4/25/23.
//

#include <iostream>
#include "Instruction.h"

int Instruction::naive_add_operand_to_set(std::set<Operand> &set, Operand op) {
	if (op.getOperandType() != OPERAND_TYPE_LITERAL) {
		if (op.getOperandType() == OPERAND_TYPE_UNDEFINED || op.getOperandType() == OPERAND_TYPE_LABEL) {
			std::cout << "OPERAND IS UNDEF OR LABEL - NOT SUPPOSED TO HAPPEN - INSIDE naive_add_operand_to_set"
			          << std::endl;
			return 0;
		} else {
			if (set.find(op) == set.end()) {
				set.insert(op);
				return 2;
			} else {
				//else duplicate
				return 1;
			}
		}
	} else {
		return 0;
	}
	//return ret;
}

LivenessTableEntry *Instruction::get_parent_liveness_table_entry() {
	return parent_liveness_table_entry;
}

void Instruction::set_parent_liveness_table_entry(LivenessTableEntry *entry) {
	parent_liveness_table_entry = entry;
}

