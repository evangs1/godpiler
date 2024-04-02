//
// Created by Evan Shaw on 4/28/23.
//

#ifndef CPP_TEST_PUSHINSTRUCTION_H
#define CPP_TEST_PUSHINSTRUCTION_H


#include "Instruction.h"

class PushInstruction : public Instruction {

private:
	std::vector<Operand> register_list;
public:
	PushInstruction(std::vector<Operand> register_list);
	std::string to_string() override;

	std::set<Operand> get_use_set() override;

	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_PUSHINSTRUCTION_H
