//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_LABELINSTRUCTION_H
#define CPP_TEST_LABELINSTRUCTION_H


#include <string>
#include "Instruction.h"

class LabelInstruction : public Instruction{

protected:
	std::string label_string;

public:
	LabelInstruction(std::string label_string);

	std::string get_raw_label();
	std::string to_string() override;
	std::set<Operand> get_use_set() override;
	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;

};


#endif //CPP_TEST_LABELINSTRUCTION_H
