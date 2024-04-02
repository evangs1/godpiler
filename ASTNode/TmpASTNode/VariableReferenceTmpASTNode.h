//
// Created by Evan Shaw on 5/1/23.
//

#ifndef CPP_TEST_VARIABLEREFERENCETMPASTNODE_H
#define CPP_TEST_VARIABLEREFERENCETMPASTNODE_H


#include "../VariableReferenceASTNode.h"
#include "../ExpASTNode/ExpASTNode.h"

class VariableReferenceTmpASTNode : public VariableReferenceASTNode {
public:

	std::string var_id;
	int number_of_arrays{0};
	std::vector<ExpASTNode *> index_exp_list;
	explicit VariableReferenceTmpASTNode(std::string variable_id);
	VariableReferenceTmpASTNode();
};


#endif //CPP_TEST_VARIABLEREFERENCETMPASTNODE_H
