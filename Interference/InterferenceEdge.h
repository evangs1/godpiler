//
// Created by Evan Shaw on 4/26/23.
//

#ifndef CPP_TEST_INTERFERENCEEDGE_H
#define CPP_TEST_INTERFERENCEEDGE_H


class InterferenceNode;

class InterferenceEdge {

public:
	InterferenceEdge(InterferenceNode * node_pointer, bool is_copy_edge, bool is_hidden);

	InterferenceNode * node_pointer;
	bool is_copy_edge;
	bool is_hidden;

	bool operator==(const InterferenceEdge &other_interference_edge) const;

};


#endif //CPP_TEST_INTERFERENCEEDGE_H
