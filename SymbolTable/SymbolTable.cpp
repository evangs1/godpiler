//
// Created by Evan Shaw on 4/24/23.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable() = default;


void SymbolTable::add_static_var_to_symbol_table(VariableSymbolTableEntry *var_entry) {
    static_variables.push_back(var_entry);
}

void SymbolTable::add_function_to_symbol_table(FunctionSymbolTableEntry * function_entry) {
    functions.push_back(function_entry);
}

FunctionSymbolTableEntry *SymbolTable::find_symtab_entry_by_string(const std::string& match_string) {
    for (auto f : functions) {
        if (f->get_function_id() == match_string) {
            return f;
        }
    }
    return nullptr;
}


std::string SymbolTable::string_literals_to_string() {
    std::string final_table_string;
    for (const auto& p : string_literal_table) {
        final_table_string += p->first + ":\n .asciz \"" + p->second + "\"\n";
    }
    return final_table_string;
}

std::pair<std::string, std::string> * SymbolTable::add_string_literal_to_string(const std::string& id, const std::string& literal) {
    auto str_lit_table_entry = new std::pair<std::string, std::string>(id, literal);
    string_literal_table.push_back(str_lit_table_entry);
    return str_lit_table_entry;
}
