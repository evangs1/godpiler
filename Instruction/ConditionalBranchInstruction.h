//
// Created by Evan Shaw on 4/25/23.
//

#ifndef CPP_TEST_CONDITIONALBRANCHINSTRUCTION_H
#define CPP_TEST_CONDITIONALBRANCHINSTRUCTION_H


#include "BranchInstruction.h"
#include "../BooleanOperationTypeEnum.h"

class ConditionalBranchInstruction : public BranchInstruction {

private:
	enum BooleanOperationType boolean_operation_type;

public:
	ConditionalBranchInstruction(BooleanOperationType boolean_operation_type, const Operand &destination_label,
	                             LabelInstruction *branch_target_label_pointer);


	std::string to_string() override;

	std::set<Operand> get_use_set() override;

	std::set<Operand> get_def_set() override;
};


#endif //CPP_TEST_CONDITIONALBRANCHINSTRUCTION_H
