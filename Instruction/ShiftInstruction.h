//
// Created by evan on 5/3/23.
//

#ifndef GODPILER_SHIFTINSTRUCTION_H
#define GODPILER_SHIFTINSTRUCTION_H

#include "Instruction.h"

enum ShiftInstructionType {
    SHIFT_INSTRUCTION_TYPE_LEFT,
    SHIFT_INSTRUCTION_TYPE_RIGHT
};


class ShiftInstruction : public Instruction  {

private:
    enum ShiftInstructionType operation_type;
    Operand destination;
    Operand source;
    Operand shift_value;
    //TODO: registers can only be r0-r7, should make some way to interfere with r8+

public:
    ShiftInstruction(enum ShiftInstructionType operation_type, Operand destination, Operand source, Operand shift_value);

    std::string to_string() override;

    std::set<Operand> get_use_set() override;

    std::set<Operand> get_def_set() override;

    void replace_operands(Operand to_replace, Operand replacer) override;
};


#endif //GODPILER_SHIFTINSTRUCTION_H
