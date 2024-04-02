//
// Created by Evan Shaw on 4/26/23.
//

#include <iostream>
#include "InterferenceGraph.h"
#include "../Instruction/MoveInstruction.h"
#include "../Instruction/NormalOperationInstruction.h"

InterferenceGraph::InterferenceGraph(LivenessTable *lv_table_pointer) : lv_table_pointer(lv_table_pointer) {

    //loop through table, determine if there is more than one operand in an entry
    //if there is, take each operand in the entry and conflict them with each other

    //for each table entry
    for (auto table_entry: lv_table_pointer->table) {
        //add defs to nodes
        for (Operand def_operand: table_entry->def_set) {
            InterferenceNode *node_associated_with_def_operand;
            bool node_associated_with_def_operand_found = false;
            for (auto &n: interference_node_table) {
                if (n->node_operand == def_operand) {
                    node_associated_with_def_operand = n;
                    node_associated_with_def_operand_found = true;
                    break;
                }
            }
            //if we did not find the node associated with def_operand, create it
            if (!node_associated_with_def_operand_found) {
                add_node(def_operand);
            }
        }


        //and i guess add uses too because what if the program is using r1 for arg, but it doesn't get deffed, and doesn't register from the LVin and LVout sets because it doesn't interfere with any other node???
        for (Operand use_operand: table_entry->use_set) {
            InterferenceNode *node_associated_with_use_operand;
            bool node_associated_with_use_operand_found = false;
            for (auto &n: interference_node_table) {
                if (n->node_operand == use_operand) {
                    node_associated_with_use_operand = n;
                    node_associated_with_use_operand_found = true;
                    break;
                }
            }
            //if we did not find the node associated with def_operand, create it
            if (!node_associated_with_use_operand_found) {
                add_node(use_operand);
            }
        }



        //check live in and live out sets
        if (table_entry->live_in.size() > 1) {
            for (Operand o1: table_entry->live_in) {
                for (Operand o2: table_entry->live_in) {
                    if (!(o1 == o2)) {
                        //find the InterferenceNode associated with o1
                        InterferenceNode *node_associated_with_o1;
                        bool node_associated_with_o1_found = false;
                        for (auto &n: interference_node_table) {
                            if (n->node_operand == o1) {
                                node_associated_with_o1 = n;
                                node_associated_with_o1_found = true;
                                break;
                            }
                        }
                        //if we did not find the node associated with o1, create it
                        if (!node_associated_with_o1_found) {
                            add_node(o1);
                            //then find it (should be at back of vector)
                            if (interference_node_table.back()->node_operand == o1) {
                                node_associated_with_o1 = interference_node_table.back();
                            } else {
                                std::cout << "CRITICAL ERROR IN NODE INSERTION 1" << std::endl;
                                exit(1);
                            }
                        }

                        //find the InterferenceNode associated with o1
                        InterferenceNode *node_associated_with_o2;
                        bool node_associated_with_o2_found = false;
                        for (auto &n: interference_node_table) {
                            if (n->node_operand == o2) {
                                node_associated_with_o2 = n;
                                node_associated_with_o2_found = true;
                                break;
                            }
                        }
                        //if we did not find the node associated with o1, create it
                        if (!node_associated_with_o2_found) {
                            add_node(o2);
                            //then find it (should be at back of vector)
                            if (interference_node_table.back()->node_operand == o2) {
                                node_associated_with_o2 = interference_node_table.back();
                            } else {
                                std::cout << "CRITICAL ERROR IN NODE INSERTION 2" << std::endl;
                                exit(1);
                            }
                        }

                        //add InterferenceEdge that references o2 to InterferenceNode that is o1
                        InterferenceEdge *e2 = new InterferenceEdge(node_associated_with_o2, false, false);
                        node_associated_with_o1->add_edge(e2);

                        //add InterferenceEdge that references o2 to InterferenceNode that is o1
                        InterferenceEdge *e1 = new InterferenceEdge(node_associated_with_o1, false, false);
                        node_associated_with_o2->add_edge(e1);


                    }
                }
            }
        }

        if (table_entry->live_out.size() > 1) {
            for (Operand o1: table_entry->live_out) {
                for (Operand o2: table_entry->live_out) {
                    if (!(o1 == o2)) {
                        //find the InterferenceNode associated with o1
                        InterferenceNode *node_associated_with_o1;
                        bool node_associated_with_o1_found = false;
                        for (auto &n: interference_node_table) {
                            if (n->node_operand == o1) {
                                node_associated_with_o1 = n;
                                node_associated_with_o1_found = true;
                                break;
                            }
                        }
                        //if we did not find the node associated with o1, create it
                        if (!node_associated_with_o1_found) {
                            add_node(o1);
                            //then find it (should be at back of vector)
                            if (interference_node_table.back()->node_operand == o1) {
                                node_associated_with_o1 = interference_node_table.back();
                            } else {
                                std::cout << "CRITICAL ERROR IN NODE INSERTION 1" << std::endl;
                                exit(1);
                            }
                        }

                        //find the InterferenceNode associated with o1
                        InterferenceNode *node_associated_with_o2;
                        bool node_associated_with_o2_found = false;
                        for (auto &n: interference_node_table) {
                            if (n->node_operand == o2) {
                                node_associated_with_o2 = n;
                                node_associated_with_o2_found = true;
                                break;
                            }
                        }
                        //if we did not find the node associated with o1, create it
                        if (!node_associated_with_o2_found) {
                            add_node(o2);
                            //then find it (should be at back of vector)
                            if (interference_node_table.back()->node_operand == o2) {
                                node_associated_with_o2 = interference_node_table.back();
                            } else {
                                std::cout << "CRITICAL ERROR IN NODE INSERTION 2" << std::endl;
                                exit(1);
                            }
                        }

                        //add InterferenceEdge that references o2 to InterferenceNode that is o1
                        InterferenceEdge *e2 = new InterferenceEdge(node_associated_with_o2, false, false);
                        node_associated_with_o1->add_edge(e2);

                        //add InterferenceEdge that references o2 to InterferenceNode that is o1
                        InterferenceEdge *e1 = new InterferenceEdge(node_associated_with_o1, false, false);
                        node_associated_with_o2->add_edge(e1);


                    }
                }
            }
        }

    }

    //loop through instructions, find mul instructions, make interference edges between (mul $tx, $ty, $tz)  $tx and $ty because destination cannot be the same as first source for some reason
    for (auto table_entry: lv_table_pointer->table) {
        auto multiply_instr = dynamic_cast<NormalOperationInstruction *>(table_entry->instruction);
        if (multiply_instr != nullptr) {
            if (multiply_instr->get_operation_type() == NORMAL_OPERATION_INSTRUCTION_TYPE_MULTIPLICATION) {
                //now find node corresponding to the destination operand of this multiplication instruction
                for (auto node: interference_node_table) {
                    if (node->node_operand == multiply_instr->get_destination_operand()) {
                        bool interfering_edge_exists = false;
                        for (auto edge: node->edge_list) {
                            //if that node does not contain an interference edge between it and the node corresponding,
                            if (edge->node_pointer->node_operand == multiply_instr->get_source_1_operand()) {
                                interfering_edge_exists = true;
                                break;
                            }
                        }
                        if (!interfering_edge_exists) {
                            //first get the node that we are going to point to first
                            InterferenceNode *source_node = nullptr;
                            for (auto source_node_tmp: interference_node_table) {
                                if (source_node_tmp->node_operand == multiply_instr->get_source_1_operand()) {
                                    source_node = source_node_tmp;
                                    break;
                                }
                            }
                            if (source_node == nullptr) {
                                std::cout << "CRITICAL ERROR IN MULTIPLY INTERFERE" << std::endl;
                                exit(1);
                            }
                            auto *e1 = new InterferenceEdge(source_node, false, false);
                            node->add_edge(e1);
                            auto *e2 = new InterferenceEdge(node, false, false);
                            source_node->add_edge(e2);

                        }
                    }
                }
            }
        }

    }

    //loop through instructions, find instructions in the format (mov a, b), if a and b do not interfere, then add a new
    //edge to the graph that is a 'dotted line' indicating copy register assignment preference
    for (auto table_entry: lv_table_pointer->table) {
        auto *copy_instr = dynamic_cast<MoveInstruction *>(table_entry->instruction);
        if (copy_instr != nullptr) {
            if ((copy_instr->get_source_operand().getOperandType() == OPERAND_TYPE_REGISTER) ||
                (copy_instr->get_source_operand().getOperandType() == OPERAND_TYPE_SYMBOLIC_REGISTER) ||
                (copy_instr->get_source_operand().getOperandType() == OPERAND_TYPE_VARIABLE_REFERENCE)) {

                //need to find node corresponding to copy_instr->destination

                for (auto node: interference_node_table) {
                    if (node->node_operand == copy_instr->get_destination_operand()) {
                        bool interfering_edge_exists = false;
                        for (auto edge: node->edge_list) {
                            //if that node does not contain a real interference edge between it and the node corresponding,
                            //(we don't actually need to check if it is a copy edge or not because we do nothing all the same)
                            if (edge->node_pointer->node_operand == copy_instr->get_source_operand()) {
                                interfering_edge_exists = true;
                                break;
                            }
                        }
                        if (!interfering_edge_exists) {
                            //to copy_instr->source, make a new node that is a 'dotted line' between the nodes

                            //first get the node that we are going to point to first
                            InterferenceNode *source_node = nullptr;
                            for (auto source_node_tmp: interference_node_table) {
                                if (source_node_tmp->node_operand == copy_instr->get_source_operand()) {
                                    source_node = source_node_tmp;
                                    break;
                                }
                            }
                            if (source_node == nullptr) {
                                std::cout << "CRITICAL ERROR IN COPY REGISTER ASSIGNMENT PREFERENCE" << std::endl;
                                exit(1);
                            }
                            InterferenceEdge *e1 = new InterferenceEdge(source_node, true, false);
                            node->add_edge(e1);
                            InterferenceEdge *e2 = new InterferenceEdge(node, true, false);
                            source_node->add_edge(e2);

                        }


                    }
                }
            }
        }
    }

}

void InterferenceGraph::add_node(Operand op) {
    InterferenceNode *n = new InterferenceNode(op, false);
    interference_node_table.push_back(n);
}

std::string InterferenceGraph::to_string() {
    std::string ret_str = std::string();
    ret_str += "(parentheses) indicate a hidden node or edge\n";
    ret_str += "{braces} indicate a copy assignment preference\n";

    for (auto n: interference_node_table) {

        bool node_is_hidden = n->is_hidden;
        if (node_is_hidden) {
            ret_str += "( ";
        }
        ret_str += n->node_operand.to_string() + ": ";
        for (auto edge: n->edge_list) {
            bool edge_is_hidden = edge->is_hidden;
            bool edge_is_copy_preference = edge->is_copy_edge;
            if (edge_is_hidden) {
                ret_str += "(";
            }
            if (edge_is_copy_preference) {
                ret_str += "{";
            }
            ret_str += edge->node_pointer->node_operand.to_string();
            if (edge_is_copy_preference) {
                ret_str += "}";
            }
            if (edge_is_hidden) {
                ret_str += ")";
            }
            ret_str += " ";
            //TODO: add something to indicate if edge is dotted line
        }

        ret_str += "                      assn reg: " + std::to_string(n->assigned_register) + " ";


        if (node_is_hidden) {
            ret_str += " )";
        }
        ret_str += "\n";
    }

    return ret_str;
}

void InterferenceGraph::hide_node(InterferenceNode *interference_node) {
    //mark node as hidden
    interference_node->is_hidden = true;

    //loop through its edge list and mark each edge hidden,
    for (auto edge: interference_node->edge_list) {
        edge->is_hidden = true;
        for (auto edge_from_node: edge->node_pointer->edge_list) {
            if (edge_from_node->node_pointer == interference_node) {
                edge_from_node->is_hidden = true;
            }
        }
    }
    // then visit each node that edge points to, find the edge that points back, mark that edge as hidden
}

void InterferenceGraph::unhide_node(InterferenceNode *interference_node) {
    //mark node as not hidden
    interference_node->is_hidden = false;

    //loop through its edge list and mark each edge not hidden,
    for (auto edge: interference_node->edge_list) {
        //if edge points to a node that is not hidden, then
        if (!edge->node_pointer->is_hidden) {
            edge->is_hidden = false;
            //loop through edges of that node to find the one that points back here
            for (auto edge_from_node: edge->node_pointer->edge_list) {
                if (edge_from_node->node_pointer == interference_node) {
                    edge_from_node->is_hidden = false;
                }
            }
        }

    }
    // then visit each node that edge points to, find the edge that points back, mark that edge as not hidden
}

//can be optimized to simply store a value and update when hiding or unhiding nodes
int InterferenceGraph::get_number_of_non_hidden_nodes() {
    int n_non_hidden_nodes = 0;
    for (auto node: interference_node_table) {
        if (!node->is_hidden) {
            n_non_hidden_nodes++;
        }
    }
    return n_non_hidden_nodes;
}

//DO NOT COUNT NODES THAT ARE ALREADY HARDWARE REGISTERS
InterferenceNode *InterferenceGraph::get_lowest_degree_node() {

    if (!interference_node_table.empty()) {
        InterferenceNode *lowest_degree_node = nullptr;
        int lowest_degree = INT32_MAX;
        for (auto node: interference_node_table) {
            int current_degree = node->get_current_degree();
            if ((!node->is_hidden) && (node->node_operand.getOperandType() != OPERAND_TYPE_REGISTER) &&
                (current_degree < lowest_degree)) {
                lowest_degree = current_degree;
                lowest_degree_node = node;
            }
        }
        return lowest_degree_node;
    } else {
        return nullptr;
    }
}
