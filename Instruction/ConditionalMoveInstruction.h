//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_CONDITIONALMOVEINSTRUCTION_H
#define CPP_TEST_CONDITIONALMOVEINSTRUCTION_H


#include "Instruction.h"
#include "../BooleanOperationTypeEnum.h"

class ConditionalMoveInstruction : public Instruction {

private:
	enum BooleanOperationType boolean_operation_type;
	Operand destination;
	Operand source;

public:
	ConditionalMoveInstruction(enum BooleanOperationType boolean_operation_type, Operand destination, Operand source);

	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_CONDITIONALMOVEINSTRUCTION_H
