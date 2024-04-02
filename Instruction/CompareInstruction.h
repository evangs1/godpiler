//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_COMPAREINSTRUCTION_H
#define CPP_TEST_COMPAREINSTRUCTION_H


#include "Instruction.h"

class CompareInstruction : public Instruction {

	Operand cmp_left_operand;
	Operand cmp_right_operand;

public:
	CompareInstruction(Operand cmp_left_operand, Operand cmp_right_operand);
	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_COMPAREINSTRUCTION_H
