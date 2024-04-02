//
// Created by Evan Shaw on 5/1/23.
//

#include "VariableReferenceTmpASTNode.h"

#include <utility>

VariableReferenceTmpASTNode::VariableReferenceTmpASTNode(std::string variable_id) : var_id(std::move(variable_id)) {

}

VariableReferenceTmpASTNode::VariableReferenceTmpASTNode() = default;
