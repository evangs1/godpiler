//
// Created by Evan Shaw on 4/28/23.
//

#ifndef CPP_TEST_RETRACTSTACKPOINTERPLACEHOLDERINSTRUCTION_H
#define CPP_TEST_RETRACTSTACKPOINTERPLACEHOLDERINSTRUCTION_H


#include <string>
#include "Operand.h"
#include "Instruction.h"

class RetractStackPointerPlaceholderInstruction : public Instruction {

private:
	int change_sp_amount{0};

public:
	RetractStackPointerPlaceholderInstruction();

	int get_change_sp_amount();
	void set_change_sp_amount(int change_sp_amount);
	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_RETRACTSTACKPOINTERPLACEHOLDERINSTRUCTION_H
