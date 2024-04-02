//
// Created by Evan Shaw on 4/24/23.
//

#ifndef CPP_TEST_FUNCTIONSYMBOLTABLEENTRY_H
#define CPP_TEST_FUNCTIONSYMBOLTABLEENTRY_H


#include <vector>
#include "SymbolTableEntry.h"
#include "VariableSymbolTableEntry.h"

class FunctionSymbolTableEntry : public SymbolTableEntry {

private:
	enum VariableType ret_type;
	std::string function_id;
	int ret_number_of_arrays;

	//if it is not main, it is a static function:
	bool is_main;
    //this is true if is main function and args[someIndex] is referenced at some point
    bool function_needs_program_args{false};
	int number_of_arguments;
	bool is_extern{false};

	std::vector<VariableSymbolTableEntry *> table;


public:
	FunctionSymbolTableEntry(enum VariableType ret_type, std::string function_id, int ret_number_of_arrays,
	                         bool is_main, int num_args, bool is_extern);

	//TODO: might need a method to return all the function arguments of this function, and also their number????

	void add_entry(VariableSymbolTableEntry *var_entry);

	enum VariableType get_ret_type();
	std::string get_function_id();
	enum VariableType get_return_type();
	int get_number_of_arguments();
    bool get_function_needs_program_args();
	std::vector<VariableSymbolTableEntry *> get_argument_variables_symtab_entries();

    VariableSymbolTableEntry * find_var_symtab_entry_by_string(const std::string& var_id);

	std::string to_string() override;

    void set_return_type(enum VariableType vt);
    void set_number_of_arguments(int n);
    void set_ret_number_of_arrays(int n);
    void set_is_main(bool is_main_func);
    void set_is_extern(bool is_extern_func);
    void set_function_needs_program_args(bool func_needs_program_args);

};


#endif //CPP_TEST_FUNCTIONSYMBOLTABLEENTRY_H
