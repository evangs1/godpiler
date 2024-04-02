//
// Created by Evan Shaw on 4/27/23.
//

#include "InterferenceNode.h"

//void InterferenceNode::add_edge(InterferenceEdge edge) {
//	//could be more efficient to add in sorted order
//	for (auto &e : edge_list) {
//		if (e == edge) {
//			return;
//		}
//	}
//
//	edge_list.push_back(edge);
//}

bool InterferenceNode::operator==(const InterferenceNode &other_node) const {
	return this->node_operand == other_node.node_operand;
}

bool InterferenceNode::operator<(const InterferenceNode &other_node) const {
	return this->node_operand < other_node.node_operand;
}

InterferenceNode::InterferenceNode(Operand operand, bool is_hidden) : node_operand(operand), is_hidden(is_hidden) {

}

void InterferenceNode::add_edge(InterferenceEdge *edge) {
	for (auto &e : edge_list) {
		if (*e == *edge) {
			return;
		}
	}

	edge_list.push_back(edge);
}

int InterferenceNode::get_current_degree() {
	int degree = 0;
	for (auto edge : edge_list) {
		if (!edge->is_hidden) {
			degree++;
		}
	}
	return degree;
}


