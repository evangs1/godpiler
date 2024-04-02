//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_SAVECALLEESAVEDREGISTERSPLACEHOLDERINSTRUCTION_H
#define CPP_TEST_SAVECALLEESAVEDREGISTERSPLACEHOLDERINSTRUCTION_H


#include "Instruction.h"

class SaveCalleeSavedRegistersPlaceholderInstruction : public Instruction {


public:
	SaveCalleeSavedRegistersPlaceholderInstruction();
	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_SAVECALLEESAVEDREGISTERSPLACEHOLDERINSTRUCTION_H
