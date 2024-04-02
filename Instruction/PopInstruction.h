//
// Created by Evan Shaw on 4/28/23.
//

#ifndef CPP_TEST_POPINSTRUCTION_H
#define CPP_TEST_POPINSTRUCTION_H


#include <vector>
#include <set>
#include "Operand.h"
#include "Instruction.h"

class PopInstruction : public Instruction {
private:
	std::vector<Operand> register_list;
public:
	explicit PopInstruction(std::vector<Operand> register_list);
	std::string to_string() override;

	std::set<Operand> get_use_set() override;

	std::set<Operand> get_def_set() override;

	void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //CPP_TEST_POPINSTRUCTION_H
