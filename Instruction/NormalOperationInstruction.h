//
// Created by Evan Shaw on 4/23/23.
//

#ifndef CPP_TEST_NORMALOPERATIONINSTRUCTION_H
#define CPP_TEST_NORMALOPERATIONINSTRUCTION_H


#include "Instruction.h"

enum OperationType {
	NORMAL_OPERATION_INSTRUCTION_TYPE_ADDITION,
	NORMAL_OPERATION_INSTRUCTION_TYPE_SUBTRACTION,
	NORMAL_OPERATION_INSTRUCTION_TYPE_MULTIPLICATION,
	NORMAL_OPERATION_INSTRUCTION_TYPE_DIVISION,
	NORMAL_OPERATION_INSTRUCTION_TYPE_AND,
	NORMAL_OPERATION_INSTRUCTION_TYPE_OR
};

class NormalOperationInstruction : public Instruction {

private:
	enum OperationType operation_type;
	Operand destination;
	Operand source_1;
	Operand source_2;


public:
	NormalOperationInstruction(enum OperationType operation_type, Operand destination, Operand source_1,
	                           Operand source_2);

	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

    enum OperationType get_operation_type();
    Operand get_destination_operand();
    Operand get_source_1_operand();

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_NORMALOPERATIONINSTRUCTION_H
