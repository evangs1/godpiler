//
// Created by Evan Shaw on 4/21/23.
//

#ifndef CPP_TEST_OPERAND_H
#define CPP_TEST_OPERAND_H

#include "../SymbolTable/VariableSymbolTableEntry.h"

enum OperandType {
	OPERAND_TYPE_UNDEFINED,
	OPERAND_TYPE_REGISTER,
	OPERAND_TYPE_SYMBOLIC_REGISTER,
	OPERAND_TYPE_LITERAL,
	OPERAND_TYPE_VARIABLE_REFERENCE,
	OPERAND_TYPE_LABEL //not to be confused with a label instruction ?? maybe
};



class Operand {

private:
	enum OperandType operand_type;
	int operand_value;
	VariableSymbolTableEntry *var_reference_to_symtab{};
	bool print_ldr_specific_literal{false};

public:
	std::string label_string;
	Operand();
	Operand(enum OperandType type, int value);
	Operand(enum OperandType type, int value, VariableSymbolTableEntry * var_reference_to_symtab);
	Operand(enum OperandType type, int value, std::string label_string);

	void set_print_ldr_specific_literal(bool print_ldr_specific_lit);
	bool operator==(const Operand& other_operand) const;
	enum OperandType getOperandType();
	int getOperandValue() const;
	std::string to_string();

	bool operator<(const Operand& other_operand) const;

//	struct hash {
//		size_t operator()(const Operand& operand) const
//		{
//			size_t type_hash = std::hash<int>()(operand.operand_value);
//			size_t value_hash = std::hash<int>()(operand.operand_type) << 1;
//			size_t func_symtab_ptr_hash = std::hash<VariableSymbolTableEntry*>()(operand.var_reference_to_symtab);
//			return type_hash ^ value_hash ^ func_symtab_ptr_hash;
//		}
//	};

};


#endif //CPP_TEST_OPERAND_H
