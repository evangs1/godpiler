//
// Created by Evan Shaw on 4/27/23.
//

#ifndef CPP_TEST_INTERFERENCENODE_H
#define CPP_TEST_INTERFERENCENODE_H


#include <list>
#include "InterferenceEdge.h"
#include "../Instruction/Operand.h"

class InterferenceNode {

private:


public:
	InterferenceNode(Operand operand, bool is_hidden);

	Operand node_operand;
	std::list<InterferenceEdge *> edge_list;
	bool is_hidden;
	int assigned_register{-1};

	int get_current_degree();
	void add_edge(InterferenceEdge *edge);

	bool operator==(const InterferenceNode& other_node) const;
	bool operator<(const InterferenceNode& other_node) const;

};


#endif //CPP_TEST_INTERFERENCENODE_H
