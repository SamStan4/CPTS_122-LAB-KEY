#pragma once

#include "linked_list_node.hpp"
#include "stack_node.hpp"
#include "queue_node.hpp"
#include "tree_node.hpp"

void node_tests(void)
{
	linked_list_node<string> linked_list_node_test;
	stack_node<string> stack_node_test;
	queue_node<string> queue_node_test;
	tree_node<string> tree_node_test;

	linked_list_node_test.set_data("Hello world");
	stack_node_test.set_data("Hello world");
	queue_node_test.set_data("Hello world");
	tree_node_test.set_data("Hello world");

	cout << linked_list_node_test << endl;

	cout << stack_node_test << endl;

	cout << queue_node_test << endl;

	cout << tree_node_test << endl;

}