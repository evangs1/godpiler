//
// Created by Evan Shaw on 4/27/23.
//

#ifndef CPP_TEST_CHAITINBRIGGSCOLORER_H
#define CPP_TEST_CHAITINBRIGGSCOLORER_H

#define USED_REGISTERS_ARRAY_SIZE 10

#include "../Interference/InterferenceGraph.h"

class ChaitinBriggsColorer {

private:
//	LivenessTable liveness_table = LivenessTable(__1::vector());
//	InterferenceGraph interference_graph = InterferenceGraph(nullptr);
	bool is_leaf_node;
	std::vector<Instruction *> instructions;
	std::vector<std::pair<Operand, int>> operand_assignment_table;
	std::set<int> registers_used_in_program;
	int calculated_sp_offset{0};


	int check_used_caller_saved_registers(InterferenceNode * operating_node, bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]);
	int check_unused_caller_saved_registers(InterferenceNode *operating_node, bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]);
	int check_used_callee_saved_registers(InterferenceNode *operating_node, bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]);
	int check_unused_callee_saved_registers(InterferenceNode *operating_node, bool (&used_registers_array)[USED_REGISTERS_ARRAY_SIZE]);

public:
	explicit ChaitinBriggsColorer(std::vector<Instruction *> instruction_vector, bool is_leaf_node);

	int get_calculated_sp_offset();
	std::vector<Instruction *> gen_3AC();
	std::set<int> get_registers_used_in_program();
	bool perform_coloring(InterferenceGraph *interference_graph);
	bool check_register_can_be_assigned(InterferenceNode *operating_node, int prospective_register);

};


#endif //CPP_TEST_CHAITINBRIGGSCOLORER_H
