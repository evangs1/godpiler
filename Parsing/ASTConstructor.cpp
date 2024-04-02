//
// Created by evan on 5/2/23.
//

#ifndef GODPILER_ASTCONSTRUCTOR_CPP
#define GODPILER_ASTCONSTRUCTOR_CPP



#include <iostream>
#include "../ASTNode/FunctionASTNode.h"
#include "../SymbolTable/SymbolTable.h"
#include "../ASTNode/StatementASTNode/PrintLineStatementASTNode.h"
#include "../ASTNode/ExpASTNode/VariableReferenceExpASTNode.h"
#include "../ASTNode/ExpASTNode/NormalOperationExpASTNode.h"
#include "../ASTNode/ExpASTNode/BooleanOperationExpASTNode.h"
#include "../ASTNode/ExpASTNode/IntegerLiteralExpASTNode.h"

#include "../ASTNode/StatementASTNode/AssignmentStatementASTNode.h"
#include "../ASTNode/StatementASTNode/IfElseStatementASTNode.h"
#include "../ASTNode/StatementASTNode/WhileStatementASTNode.h"

#include "../ASTNode/ExpASTNode/MethodCallExpASTNode.h"
#include "../ASTNode/StatementASTNode/MethodCallStatementASTNode.h"
#include "../ASTNode/StatementASTNode/ReturnStatementASTNode.h"
#include "../ASTNode/ExpASTNode/ArgStringReferenceASTNode.h"
#include "../ASTNode/ExpASTNode/IntegerParseIntExpASTNode.h"
#include "../ASTNode/ExpASTNode/StringLiteralExpNode.h"
#include "../ASTNode/ExpASTNode/LogicalInverseExpASTNode.h"

extern "C" {
#include "node.h"
#include <stdlib.h>
#include <assert.h>
}

class ASTConstructor {

public:
    std::vector<FunctionASTNode *> function_list;
    SymbolTable * symtab;
    int string_literal_label_number = 0;

private:

//void parse_program(struct ASTNode *program);
//void parse_main_class(struct ASTNode *mainClass);
//FunctionASTNode * parse_main_method(struct ASTNode *main_method);
//void parse_static_var_decl_list(struct ASTNode *static_var_decl_list);
//void parse_static_var_decl(struct ASTNode *static_var_decl);
//void parse_more_static_var_decl(struct ASTNode *static_var_decl_more, enum DataType type, struct ASTNode *type_node);
//FunctionASTNode * parse_static_method_decl_list(struct ASTNode *static_method_decl_list);
//FunctionASTNode *parse_static_method_decl(ASTNode *static_method_decl, SymbolTable *pTable);
//StatementsASTNode * parse_statements(struct ASTNode *statements, FunctionSymbolTableEntry *);
//StatementASTNode * parse_statement(struct ASTNode *statement, FunctionSymbolTableEntry * f_symtab_entry_ptr);


//std::vector<MethodCallTmpExpASTNode *> tmp_exp_method_calls;
//std::vector<MethodCallStatementTmpASTNode *> tmp_statement_method_calls;

std::vector<FunctionSymbolTableEntry *> function_prototypes;

void parse_program(struct ASTNode *program, SymbolTable * symtab_pointer) {
    assert(program->node_type == NODETYPE_PROGRAM);
    parse_main_class(program->children[program->num_children - 1], symtab_pointer);
}

void parse_main_class(struct ASTNode *mainClass, SymbolTable * symtab_pointer) {
    assert(mainClass->node_type == NODETYPE_MAINCLASS);
    char *nameOfClass = mainClass->data.value.string_value;

//    if (mainClass->children[0] != NULL) {
//        parse_static_var_decl_list(mainClass->children[0]);
//    }

    if (mainClass->children[1] != NULL) {
        auto f = parse_static_method_decl_list(mainClass->children[1], symtab_pointer);
        for (auto function : f) {
            function_list.push_back(function);
        }
    }

    if (mainClass->children[2] != NULL) {
        auto f = parse_main_method(mainClass->children[2], symtab_pointer);
        function_list.push_back(f);
    }

}

FunctionASTNode * parse_main_method(struct ASTNode *main_method, SymbolTable * symtab_pointer) {
    assert(main_method->node_type == NODETYPE_MAINMETHOD);
    auto function_symtab_entry = new FunctionSymbolTableEntry(VARIABLE_TYPE_VOID, std::string("main"), 0, true, 1, false);
    auto statements = parse_statements(main_method->children[0], function_symtab_entry);
    auto function = new FunctionASTNode(statements, function_symtab_entry, true);
    return function;
}

//void parse_static_var_decl_list(struct ASTNode *static_var_decl_list, struct ScopeNode *scope) {
//    if (static_var_decl_list->children[0] != NULL) {
//        parse_static_var_decl_list(static_var_decl_list->children[0], scope);
//    }
//    //children[1] should never be null
//    parse_static_var_decl(static_var_decl_list->children[1]);
//
//}

//void parse_static_var_decl(struct ASTNode *static_var_decl) {
//    assert(static_var_decl->node_type == NODETYPE_STATIC_VARDECL);
//
//    //if OptionalExp, run through exp to check for references
//    if (static_var_decl->children[1] != NULL) {
//        parse_exp(static_var_decl->children[1]);
//    }
//
//    char *id = static_var_decl->data.value.string_value;
//
//
//    //parse more_static_vardecl
//    if (static_var_decl->children[2] != NULL) {
//        if (static_var_decl->children[2]->node_type == NODETYPE_MORE_STATIC_VARDECL) {
//            check_more_static_var_decl(static_var_decl
//                                               ->children[2], scope, table_entry.declaration.data_type,
//                                       static_var_decl->children[0]);
//        }
//    }
//
//}

//void parse_more_static_var_decl(struct ASTNode *static_var_decl_more, enum DataType type,
//                                struct ASTNode *type_node) {
//    assert(static_var_decl_more->node_type == NODETYPE_MORE_STATIC_VARDECL);
//    if (static_var_decl_more->children[0] != NULL) {
//        check_more_static_var_decl(static_var_decl_more->children[0], scope, type, type_node);
//    }
//
//    char *id = static_var_decl_more->data.value.string_value;
//
//    //process OptionalExp
//    if (static_var_decl_more->children[1] != NULL) {
//        check_exp(static_var_decl_more->children[1]);
//    }
//}

//done
std::vector<FunctionASTNode *> parse_static_method_decl_list(struct ASTNode *static_method_decl_list, SymbolTable * symtab_pointer) {
    assert(static_method_decl_list->node_type == NODETYPE_STATIC_METHOD_DECL_LIST);

    auto f_ast_node_list = std::vector<FunctionASTNode * >();

    if (static_method_decl_list->children[0] != NULL) {
        auto f_list = parse_static_method_decl_list(static_method_decl_list->children[0], symtab_pointer);
        for (auto f : f_list) {
            f_ast_node_list.push_back(f);
        }
    }
    if (static_method_decl_list->children[1] != NULL) {
        auto f = parse_static_method_decl(static_method_decl_list->children[1], symtab_pointer);
        f_ast_node_list.push_back(f);
    }

    return f_ast_node_list;
}

FunctionASTNode *parse_static_method_decl(ASTNode *static_method_decl, SymbolTable *pTable) {
    assert(static_method_decl->node_type == NODETYPE_STATIC_METHOD_DECL);

    char *id = static_method_decl->data.value.string_value;

    auto real_type = parse_real_type(static_method_decl->children[0]);
    enum VariableType vt;
    switch (real_type.base_data_type) {

        case DATATYPE_UNDEFINED:
            vt = VARIABLE_TYPE_VOID;
            break;
        case DATATYPE_STR:
            vt = VARIABLE_TYPE_STRING;
            break;
        case DATATYPE_INT:
            vt = VARIABLE_TYPE_INT;
            break;
        case DATATYPE_BOOLEAN:
            vt = VARIABLE_TYPE_BOOLEAN;
            break;

    }

    auto method_arg_ids = std::vector<std::string>();
    //now loop through FormalList
    struct ASTNode *current_formal_list_node = static_method_decl->children[1];
    int num_args = 0;
    while (current_formal_list_node != NULL) {
        //TODO: count number of arguments, maybe this works???
        std::cout << current_formal_list_node->data.value.string_value << std::endl;
        method_arg_ids.emplace_back(current_formal_list_node->data.value.string_value);
        current_formal_list_node = current_formal_list_node->children[1];
        num_args++;
    }
    std::cout << "THIS FUNCTION APPARENTLY HAS NUM_ARS: " << num_args << std::endl;


    FunctionSymbolTableEntry * f_symtab_entry = nullptr;

    //first try to find function symtab entry in prototypes list
    int index = 0;
    for (auto f : function_prototypes) {
        if (f->get_function_id() == std::string(id)) {
            f_symtab_entry = f;
            function_prototypes.erase(function_prototypes.begin() + index);
            symtab->add_function_to_symbol_table(f_symtab_entry);
            break;
        }
        index++;
    }
    if (f_symtab_entry == nullptr) {
        f_symtab_entry = symtab->find_symtab_entry_by_string(std::string(id));
    }

    if (f_symtab_entry == nullptr) {
        f_symtab_entry = new FunctionSymbolTableEntry(vt, std::string(id), real_type.number_of_arrays, false, num_args,
                                                      false);
        symtab->add_function_to_symbol_table(f_symtab_entry);
    } else {
        f_symtab_entry->set_is_extern(false);
        f_symtab_entry->set_number_of_arguments(num_args);
        std::cout << "SETTING NUMBER OF ARGS FOR NOW-DEFINED PROTOTYPE:" << num_args << std::endl;
        f_symtab_entry->set_return_type(vt);
        f_symtab_entry->set_ret_number_of_arrays(real_type.number_of_arrays);
    }

    for (const auto& s : method_arg_ids) {
        f_symtab_entry->add_entry(new VariableSymbolTableEntry(VARIABLE_TYPE_INT, s, 0, false, true));
    }

    StatementsASTNode * statements = NULL;
    if (static_method_decl->children[2] != NULL) {
        statements = parse_statements(static_method_decl->children[2], f_symtab_entry);
    }

    return new FunctionASTNode(statements, f_symtab_entry, false);
}

StatementsASTNode * parse_statements(struct ASTNode *statements, FunctionSymbolTableEntry * f_symtab_entry_ptr) {
    assert(statements->node_type == NODETYPE_STATEMENTS);

    auto * statements_object = new StatementsASTNode();

    if (statements->children[0] != NULL) {
        auto more_statements_object = parse_statements(statements->children[0], f_symtab_entry_ptr);
        for (auto s : more_statements_object->statements_table) {
            statements_object->add_statement(s);
        }
        delete more_statements_object;
    }
    if (statements->children[1] != NULL) {
        auto new_statement_object = parse_statement(statements->children[1], f_symtab_entry_ptr);
        statements_object->add_statement(new_statement_object);
    }
    return statements_object;
}

//done?
StatementsASTNode * parse_statement_block(struct ASTNode *statement_block, FunctionSymbolTableEntry * f_symtab_entry_ptr) {
    assert(statement_block->node_type == NODETYPE_STATEMENT_BLOCK);

    auto * statements_object = new StatementsASTNode();

    if (statement_block->num_children > 0 && statement_block->children[0] != NULL) {
        //TODO: are recursive StatementsASTNode OK???
        if (statement_block->children[0]->node_type == NODETYPE_STATEMENTS) {
            auto s = parse_statements(statement_block->children[0], f_symtab_entry_ptr);
            statements_object->add_statement(s);
        } else if (statement_block->children[0]->node_type == NODETYPE_STATEMENT) {
            printf("WHAT HAPPENED HERE 1???\n");
        } else {
            printf("WHAT HAPPENED HERE 2???\n");
        }
    }
    return statements_object;
}

StatementASTNode * parse_statement(struct ASTNode *statement, FunctionSymbolTableEntry * f_symtab_entry_ptr) {
    enum NodeType statementType = statement->node_type;
    if (statementType == NODETYPE_PRINT) {
        if (statement->children[0] != NULL) {
            auto exp_node = parse_exp(statement->children[0], f_symtab_entry_ptr);
            auto str_arg = dynamic_cast<ArgStringReferenceASTNode *>(exp_node);
            bool int_format = true;
            bool print_newline = false;
            if (str_arg != nullptr) {
                int_format = false;
            }
            auto print_line_node = new PrintLineStatementASTNode(exp_node, f_symtab_entry_ptr, print_newline, int_format);
            return print_line_node;
        } else {
            std::cout << "PRINT HAS NO EXP NODE!!!" << std::endl;
        }

    } else if (statementType == NODETYPE_PRINTLN) {
        if (statement->children[0] != NULL) {
            auto exp_node = parse_exp(statement->children[0], f_symtab_entry_ptr);
            auto str_arg = dynamic_cast<ArgStringReferenceASTNode *>(exp_node);
            bool int_format = true;
            bool print_newline = true;
            if (str_arg != nullptr) {
                int_format = false;
            }
            auto print_line_node = new PrintLineStatementASTNode(exp_node, f_symtab_entry_ptr, print_newline, int_format);
            return print_line_node;
        } else {
            std::cout << "PRINT HAS NO EXP NODE!!!" << std::endl;
        }

    } else if (statementType == NODETYPE_VARDECL) {
        //really just doing assignment right here
        char *id = statement->data.value.string_value;

        ExpASTNode * exp_node;
        if (statement->children[1] != NULL) {
            exp_node = parse_exp(statement->children[1], f_symtab_entry_ptr);
        } else {
            std::cout << "NO EXP ON ASSIGNMENT???" << std::endl;
        }

        //try to get var symtab entry, if it does not exist, create it
        VariableSymbolTableEntry * var_symtab_entry = f_symtab_entry_ptr->find_var_symtab_entry_by_string(std::string(id));
        if (var_symtab_entry == nullptr) {
            //TODO: don't really know if we need to determine whether or not it is a function arg right here
            var_symtab_entry = new VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string(id), 0, false, false);
            f_symtab_entry_ptr->add_entry(var_symtab_entry);
        }
        auto assn = new AssignmentStatementASTNode(var_symtab_entry, exp_node);


        if (statement->children[2] != NULL) {
            //return a StatementsASTNode
            auto ret_statements = new StatementsASTNode();
            ret_statements->add_statement(assn);
            auto assn2 = parse_more_var_decl(statement->children[2], f_symtab_entry_ptr, statement->children[0]->children[0]->data.type,
                                statement->children[0]);
            return ret_statements;
        } else {
            //return a AssignmentStatementASTNode
            return assn;
        }


    } else if (statementType == NODETYPE_STATEMENT_BLOCK) {
        //TODO: make some check before returning this???
        return parse_statement_block(statement, f_symtab_entry_ptr);
    } else if (statementType == NODETYPE_IF_ELSE) {
        auto exp_node = parse_exp(statement->children[0], f_symtab_entry_ptr);
        StatementASTNode * true_statements = nullptr;
        if (statement->children[1] != NULL) {
            true_statements = parse_statement(statement->children[1], f_symtab_entry_ptr);
        }

        StatementASTNode * false_statements = nullptr;
        if (statement->children[1] != NULL) {
            false_statements = parse_statement(statement->children[2], f_symtab_entry_ptr);
        }

        return new IfElseStatementASTNode(exp_node, true_statements, false_statements);


    } else if (statementType == NODETYPE_WHILE) {
        auto exp_node = parse_exp(statement->children[0], f_symtab_entry_ptr);
        StatementASTNode * while_statements = nullptr;
        if (statement->children[1] != NULL) {
            while_statements = parse_statement(statement->children[1], f_symtab_entry_ptr);
        }

        auto while_node = new WhileStatementASTNode(exp_node, while_statements);
        return while_node;

    } else if (statementType == NODETYPE_ASSIGNMENT) {
        if (statement->children[0] != NULL) {
            assert(statement->children[0]->node_type == NODETYPE_LEFTVALUE);
            //if this is asserted false, then there is some array shenanigans
            assert(statement->children[0]->num_children == 0);

            char *id = statement->children[0]->data.value.string_value;

            ExpASTNode * exp_node = nullptr;
            if (statement->children[1] != NULL) {
                exp_node = parse_exp(statement->children[1], f_symtab_entry_ptr);
            } else {
                std::cout << "WTF THIS SHOULD NEVER HAPPEN" << std::endl;
            }

            //try to get var symtab entry, if does not exist, create it
            VariableSymbolTableEntry * var_symtab_entry = f_symtab_entry_ptr->find_var_symtab_entry_by_string(std::string(id));
            if (var_symtab_entry == nullptr) {
                //TODO: don't really know if we need to determine whether or not it is a function arg right here
                var_symtab_entry = new VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string(id), 0, false, false);
                f_symtab_entry_ptr->add_entry(var_symtab_entry);
            }
            auto assn = new AssignmentStatementASTNode(var_symtab_entry, exp_node);

            return assn;

        } else {
            std::cout << "OK WHAT THE ACTUAL F" << std::endl;
            return nullptr;
        }

    } else if (statementType == NODETYPE_RETURN) {
        ExpASTNode * exp_node = nullptr;
        if (statement->children[0] != NULL) {
            exp_node = parse_exp(statement->children[0], f_symtab_entry_ptr);
        }
        return new ReturnStatementASTNode(f_symtab_entry_ptr, exp_node);

    } else if (statementType == NODETYPE_METHOD_CALL) {
        return parse_statement_method_call(statement, f_symtab_entry_ptr);
    }
    return nullptr;
}


StatementASTNode * parse_statement_method_call(struct ASTNode *method_call_node, FunctionSymbolTableEntry * f_symtab_entry_ptr) {
    assert(method_call_node->node_type == NODETYPE_METHOD_CALL);

    std::vector<ExpASTNode *> exp_list;
    if (method_call_node->children[0] != NULL) {
        exp_list = parse_exp_list(method_call_node->children[0], f_symtab_entry_ptr);
    }

    std::string function_id = std::string(method_call_node->data.value.string_value);

    FunctionSymbolTableEntry * potential_method_def = symtab->find_symtab_entry_by_string(function_id);
    if (potential_method_def == nullptr) {
        for (auto f : function_prototypes) {
            if (f->get_function_id() == function_id) {
                potential_method_def = f;
                break;
            }
        }
        if (potential_method_def == nullptr) {
            potential_method_def = new FunctionSymbolTableEntry(VARIABLE_TYPE_VOID, function_id, 0, false, exp_list.size(), false);
            function_prototypes.push_back(potential_method_def);
        }
    }
    auto method_call = new MethodCallStatementASTNode(potential_method_def, exp_list);
    return method_call;

    //ADD CHECK PARSE INT
    //ADD CHECK PARSE INT
    //ADD CHECK PARSE INT
    //ADD CHECK PARSE INT
    //ADD CHECK PARSE INT

}

ExpASTNode * parse_exp(struct ASTNode *exp, FunctionSymbolTableEntry * f_symtab_entry_ptr) {

    if (exp->node_type == NODETYPE_LEFTVALUE) {
        if (exp->num_children == 0) {
            //try to get var symtab entry, if does not exist, create it
            VariableSymbolTableEntry * var_symtab_entry = f_symtab_entry_ptr->find_var_symtab_entry_by_string(std::string(exp->data.value.string_value));
            if (var_symtab_entry == nullptr) {
                //TODO: don't really know if we need to determine whether or not it is a function arg right here
                var_symtab_entry = new VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string(exp->data.value.string_value), 0, false, false);
                f_symtab_entry_ptr->add_entry(var_symtab_entry);
            }
            auto exp_node = new VariableReferenceExpASTNode(var_symtab_entry);
            return exp_node;

        } else {
            //TODO: here we need to determine if this (presumably) indexed nod is args[index]

            //TODO: CHECK IF MAIN VALUE??????????????
            //assert(is main)
            if (exp->children[0] != NULL) {
                if (exp->children[0]->node_type == NODETYPE_LEFTVALUE && exp->children[0]->data.type == DATATYPE_STR) {
                    auto var_id = std::string(exp->children[0]->data.value.string_value);
                    if (var_id == "args") {
                        f_symtab_entry_ptr->set_function_needs_program_args(true);
                        VariableSymbolTableEntry * string_args_symtab_var_reference = f_symtab_entry_ptr->find_var_symtab_entry_by_string(std::string("args"));
                        if (string_args_symtab_var_reference == nullptr) {
                            string_args_symtab_var_reference = new VariableSymbolTableEntry(VARIABLE_TYPE_STRING,
                                                                                            std::string("args"), 1,
                                                                                            false, true);
                            f_symtab_entry_ptr->add_entry(string_args_symtab_var_reference);
                        }

                        if (exp->children[1] != NULL) {
                            ArgStringReferenceASTNode * string_arg_ast_node = nullptr;
                            if (exp->children[1]->node_type == NODETYPE_INTEGER_LITERAL) {
                                string_arg_ast_node = new ArgStringReferenceASTNode(string_args_symtab_var_reference, exp->children[1]->data.value.int_value);
                            } else {
                                string_arg_ast_node = new ArgStringReferenceASTNode(string_args_symtab_var_reference, parse_exp(exp->children[1], f_symtab_entry_ptr));
                            }
                            return string_arg_ast_node;
                        } else {
                            std::cout << "STRING ARGS WITH NO EXP???" << std::endl;
                        }
                    }

                }
            }
        }
    } else if (exp->node_type == NODETYPE_STRING_LITERAL) {
        auto str_table_ref = symtab->add_string_literal_to_string(std::string("str_lit_label") + std::to_string(string_literal_label_number++), exp->data.value.string_value);
        auto str_literal_exp = new StringLiteralExpNode(str_table_ref);
        return str_literal_exp;
    } else if (exp->node_type == NODETYPE_EXP_2_BOOL) {
        //now determine whether AND or OR
        auto exp1 = parse_exp(exp->children[0], f_symtab_entry_ptr);
        auto exp2 = parse_exp(exp->children[1], f_symtab_entry_ptr);
        assert(exp1 != nullptr);
        assert(exp2 != nullptr);

        if (exp->exp_node_type == NODETYPE_EXP_OR) {
            return new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_OR, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_EXP_AND) {
            return new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_AND, exp1, exp2);
        } else {
            std::cout << "PARSE ERROR - AND OR" << std::endl;
        }

    } else if (exp->node_type == NODETYPE_EXP_2_INT_OR_STRING_OR_BOOL) {

        auto exp1 = parse_exp(exp->children[0], f_symtab_entry_ptr);
        auto exp2 = parse_exp(exp->children[1], f_symtab_entry_ptr);
        assert(exp1 != nullptr);
        assert(exp2 != nullptr);

        if (exp->exp_node_type == NODETYPE_COMPARISON_EQUALS) {
            return new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_EQUAL_TO, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_NOT_EQUALS) {
            return new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_NOT_EQUAL, exp1, exp2);
        } else {
            std::cout << "PARSE ERROR - EQUALS NOT EQUALS" << std::endl;
        }

    } else if (exp->node_type == NODETYPE_EXP_2_INT) {
        auto exp1 = parse_exp(exp->children[0], f_symtab_entry_ptr);
        auto exp2 = parse_exp(exp->children[1], f_symtab_entry_ptr);
        assert(exp1 != nullptr);
        assert(exp2 != nullptr);

        if (exp->exp_node_type == NODETYPE_GREATER_THAN_EQUALS) {
            return new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_GREATER_THAN_OR_EQUAL_TO, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_GREATER_THAN) {
            return new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_GREATER_THAN, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_LESS_THAN_EQUALS) {
            return new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_LESS_THAN_OR_EQUAL_TO, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_LESS_THAN) {
            return new BooleanOperationExpASTNode(BOOLEAN_OPERATION_TYPE_LESS_THAN, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_MINUS) {
            return new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_SUBTRACTION, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_MULTIPLY) {
            return new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_MULTIPLICATION, exp1, exp2);
        } else if (exp->exp_node_type == NODETYPE_DIVIDE) {
            return new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_DIVISION, exp1, exp2);
        } else {
            std::cout << "PARSE ERROR - 2 INTS" << std::endl;
        }
    } else if (exp->node_type == NODETYPE_EXP_2_INT_OR_STRING) {

        auto exp1 = parse_exp(exp->children[0], f_symtab_entry_ptr);
        auto exp2 = parse_exp(exp->children[1], f_symtab_entry_ptr);
        assert(exp1 != nullptr);
        assert(exp2 != nullptr);

        if (exp->exp_node_type == NODETYPE_PLUS) {
            return new NormalOperationExpASTNode(NORMAL_OPERATION_ASTNODE_TYPE_ADDITION, exp1, exp2);
        } else {
            std::cout << "PARSE ERROR - ADDITION" << std::endl;
        }

    } else if (exp->node_type == NODETYPE_EXP_1_BOOL) {
        if (exp->children[0] != NULL) {
            return new LogicalInverseExpASTNode(parse_exp(exp->children[0], f_symtab_entry_ptr));
        } else {
            std::cout << "PARSE ERROR - NOT HAS NO CHILD :(" << std::endl;
        }
    } else if (exp->node_type == NODETYPE_EXP_1_INT_OR_STRING) {
        std::cout << "PARSE ERROR - 1 FACTOR - dont even know wtf this is" << std::endl;

    } else if (exp->node_type == NODETYPE_EXP_1_INT) {
        std::cout << "PARSE ERROR - negative numbers not implemented" << std::endl;


    } else if (exp->node_type == NODETYPE_INTEGER_LITERAL) {
        return new IntegerLiteralExpASTNode(exp->data.value.int_value);

    } else if (exp->node_type == NODETYPE_BOOL_LITERAL) {
        return new IntegerLiteralExpASTNode(exp->data.value.boolean_value);

    } else if (exp->node_type == NODETYPE_METHOD_CALL) {

        if (exp->exp_node_type == NODETYPE_METHOD_CALL_PARSEINT) {
            //TODO: INTEGER.PARSEINT SHOULD BE PROCESSED RIGHT HERE

            ExpASTNode * exp_list = nullptr;
            if (exp->children[0] != NULL) {
                exp_list = parse_exp(exp->children[0], f_symtab_entry_ptr);
                auto parseint_call = new IntegerParseIntExpASTNode(exp_list);
                return parseint_call;
            } else {
                std::cout << "SOMETHING WENT WRONG WITH PARSEINT" << std::endl;
            }

        } else {
            std::vector<ExpASTNode *> exp_list;
            if (exp->children[0] != NULL) {
                exp_list = parse_exp_list(exp->children[0], f_symtab_entry_ptr);
            }

            std::string function_id = std::string(exp->data.value.string_value);

            FunctionSymbolTableEntry * potential_method_def = symtab->find_symtab_entry_by_string(function_id);
            if (potential_method_def == nullptr) {
                for (auto f : function_prototypes) {
                    if (f->get_function_id() == function_id) {
                        potential_method_def = f;
                        break;
                    }
                }
                if (potential_method_def == nullptr) {
                    potential_method_def = new FunctionSymbolTableEntry(VARIABLE_TYPE_VOID, function_id, 0, false, exp_list.size(), false);
                    function_prototypes.push_back(potential_method_def);
                }
            }
            auto method_call = new MethodCallExpASTNode(potential_method_def, exp_list);
            return method_call;
        }

    } else {
        std::cout << "UNRECOGNIZED EXPRESSION NODE - MAYBE YOU CALLED parse_exp() ON THE WRONG NODE ?" << std::endl;
        return nullptr;
    }
    std::cout << "GOT TO THE END OF EXP" << std::endl;
    return nullptr;
}

//done?
std::vector<ExpASTNode *> parse_exp_list(struct ASTNode *exp_list, FunctionSymbolTableEntry * f_symtab_entry_ptr) {
    assert(exp_list->node_type == NODETYPE_EXPLIST);

    auto exp_list_vector = std::vector<ExpASTNode *>();

    //this usually shouldn't be NULL, but...
    if (exp_list->children[0] != NULL) {
        auto e = parse_exp(exp_list->children[0], f_symtab_entry_ptr);
        if (e != nullptr) {
            exp_list_vector.push_back(e);
        }
    }

    if (exp_list->children[1] != NULL) {
        auto list = parse_exp_list(exp_list->children[1], f_symtab_entry_ptr);
        for (auto e : list) {
            exp_list_vector.push_back(e);
        }
    }

    return exp_list_vector;

}

//done?
StatementASTNode * parse_more_var_decl(struct ASTNode *more_var_decl, FunctionSymbolTableEntry * f_symtab_entry_ptr, enum DataType type,
                         struct ASTNode *type_node) {
    char *id = more_var_decl->data.value.string_value;

    //try to get var symtab entry, if does not exist, create it
    VariableSymbolTableEntry * var_symtab_entry = f_symtab_entry_ptr->find_var_symtab_entry_by_string(std::string(id));
    if (var_symtab_entry == nullptr) {
        //TODO: don't really know if we need to determine whether or not it is a function arg right here
        var_symtab_entry = new VariableSymbolTableEntry(VARIABLE_TYPE_INT, std::string(id), 0, false, false);
        f_symtab_entry_ptr->add_entry(var_symtab_entry);
    }

    int n_statements_to_return = 0;

    //might need to go first in this function because of postorder traversal or whatever
    StatementASTNode * more_var_decl_result = nullptr;
    if (more_var_decl->children[0] != NULL) {
        more_var_decl_result = parse_more_var_decl(more_var_decl->children[2], f_symtab_entry_ptr, type, type_node);
        n_statements_to_return++;
    }

    //same with this one
    ExpASTNode * exp_node = nullptr;
    AssignmentStatementASTNode * assn = nullptr;
    if (more_var_decl->children[1] != NULL) {
        exp_node = parse_exp(more_var_decl->children[1], f_symtab_entry_ptr);
        assn = new AssignmentStatementASTNode(var_symtab_entry, exp_node);
        n_statements_to_return++;
    } else {
        std::cout << "NO EXP ON ASSIGNMENT???" << std::endl;
    }

    if (n_statements_to_return == 0) {
        return nullptr;
    } else if (n_statements_to_return == 1) {
        if (more_var_decl_result != nullptr) {
            return more_var_decl_result;
        } else {
            return assn;
        }
    } else {
        auto ret_statements = new StatementsASTNode();
        //null check just in case
        if (assn != nullptr) {
            ret_statements->add_statement(assn);
        }
        if (more_var_decl_result != nullptr) {
            ret_statements->add_statement(assn);
        }
        return ret_statements;
    }
}

public:
    explicit ASTConstructor(ASTNode *root_node) {
        symtab = new SymbolTable();

        symtab->add_string_literal_to_string("str_fmt_d", "%d");
        symtab->add_string_literal_to_string("str_fmt_dn", "%d\\n");
        symtab->add_string_literal_to_string("str_fmt_s", "%s");
        symtab->add_string_literal_to_string("str_fmt_sn", "%s\\n");

        function_list = std::vector<FunctionASTNode *>{};
        parse_program(root_node, symtab);

        //TODO: go over all lists of TMP objects and replace them with valid objects referencing the correct symbol table entry
    }


};




#endif //GODPILER_ASTCONSTRUCTOR_CPP
