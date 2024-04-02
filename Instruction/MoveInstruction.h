//
// Created by Evan Shaw on 4/24/23.
//

#ifndef CPP_TEST_MOVEINSTRUCTION_H
#define CPP_TEST_MOVEINSTRUCTION_H


#include "Instruction.h"

class MoveInstruction: public Instruction {

private:
	Operand destination;
	Operand source;


public:
	MoveInstruction(Operand destination, Operand source);

	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;
	Operand get_destination_operand();
	Operand get_source_operand();

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_MOVEINSTRUCTION_H
