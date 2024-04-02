//
// Created by Evan Shaw on 4/24/23.
//

#ifndef CPP_TEST_SYMBOLTABLEENTRY_H
#define CPP_TEST_SYMBOLTABLEENTRY_H


#include <string>
#include "../VariableTypeEnum.h"

class SymbolTableEntry {



public:
	virtual std::string to_string() = 0;

};


#endif //CPP_TEST_SYMBOLTABLEENTRY_H
