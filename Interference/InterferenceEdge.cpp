//
// Created by Evan Shaw on 4/26/23.
//

#include "InterferenceEdge.h"

bool InterferenceEdge::operator==(const InterferenceEdge &other_interference_edge) const {
	return (this->node_pointer == other_interference_edge.node_pointer) &&
	       (this->is_copy_edge == other_interference_edge.is_copy_edge);
}

InterferenceEdge::InterferenceEdge(InterferenceNode *node_pointer, bool is_copy_edge, bool is_hidden) : node_pointer(node_pointer), is_copy_edge(is_copy_edge), is_hidden(is_hidden) {

}