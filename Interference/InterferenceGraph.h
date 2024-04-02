//
// Created by Evan Shaw on 4/26/23.
//

#ifndef CPP_TEST_INTERFERENCEGRAPH_H
#define CPP_TEST_INTERFERENCEGRAPH_H


#include <list>
#include "../Liveness/LivenessTable.h"
#include "InterferenceNode.h"

class InterferenceGraph {

private:

public:
	std::vector<InterferenceNode *> interference_node_table;
	explicit InterferenceGraph(LivenessTable * lv_table_pointer);
	LivenessTable * lv_table_pointer;

	//returns a 1 if it created a new node, 0 if no new node was created
	void add_node(Operand op);

	std::string to_string();

	void hide_node(InterferenceNode * interference_node);
	//int get_node_current_degree(InterferenceNode * interference_node);
	int get_number_of_non_hidden_nodes();
	InterferenceNode * get_lowest_degree_node();
	void unhide_node(InterferenceNode *interference_node);
};


#endif //CPP_TEST_INTERFERENCEGRAPH_H
