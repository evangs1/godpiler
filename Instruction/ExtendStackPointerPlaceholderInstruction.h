//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_EXTENDSTACKPOINTERPLACEHOLDERINSTRUCTION_H
#define CPP_TEST_EXTENDSTACKPOINTERPLACEHOLDERINSTRUCTION_H


#include "Instruction.h"

class ExtendStackPointerPlaceholderInstruction : public Instruction {

private:
	int change_sp_amount{0};

public:
	ExtendStackPointerPlaceholderInstruction();

	int get_change_sp_amount();
	void set_change_sp_amount(int change_sp_amount);
	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_EXTENDSTACKPOINTERPLACEHOLDERINSTRUCTION_H
