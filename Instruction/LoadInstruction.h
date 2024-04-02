//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_LOADINSTRUCTION_H
#define CPP_TEST_LOADINSTRUCTION_H

#include "Instruction.h"

enum LoadInstructionType {
    LOAD_INSTRUCTION_TYPE_LOAD_LITERAL,
	LOAD_INSTRUCTION_TYPE_LABEL,
	LOAD_INSTRUCTION_TYPE_LOAD_FROM_ADDRESS_WITH_OFFSET
};

class LoadInstruction : public Instruction{

private:
	enum LoadInstructionType operation_type;
	Operand destination;
	Operand source_1;
	Operand source_2;

public:
	LoadInstruction(enum LoadInstructionType operation_type, Operand destination, Operand source_1, Operand source_2);
	LoadInstruction(enum LoadInstructionType operation_type, Operand destination, Operand source_1);

	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;

};


#endif //CPP_TEST_LOADINSTRUCTION_H
