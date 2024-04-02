//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_BRANCHINSTRUCTION_H
#define CPP_TEST_BRANCHINSTRUCTION_H


#include "Operand.h"
#include "LabelInstruction.h"

class BranchInstruction : public Instruction {

protected:
	Operand destination_label;
	LabelInstruction *branch_target_label_pointer;

public:
	void replace_operands(Operand to_replace, Operand replacer) override;

	BranchInstruction(Operand destination_label, LabelInstruction *branch_target_label_pointer);

	std::string to_string() override;

	std::set<Operand> get_use_set() override;

	std::set<Operand> get_def_set() override;

	LabelInstruction * get_branch_target_label_pointer();
};


#endif //CPP_TEST_BRANCHINSTRUCTION_H
