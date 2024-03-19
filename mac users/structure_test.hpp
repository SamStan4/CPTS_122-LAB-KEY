#pragma once

#include "linked_list.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "tree.hpp"

void linked_list_test(void)
{
	linked_list<string> linked_list_test;

	linked_list_test.insert_front("one");
	linked_list_test.insert_front("two");
	linked_list_test.insert_front("three");
	linked_list_test.insert_front("four");
	linked_list_test.insert_front("five");
	linked_list_test.insert_front("six");
	linked_list_test.insert_front("seven");
	linked_list_test.insert_front("eight");
	linked_list_test.insert_front("nine");
	linked_list_test.insert_front("ten");

	cout << linked_list_test;
}

void stack_test(void)
{
	stack<string> stack_test;
}

void queue_test(void)
{
	queue<string> queue_test;
}

void tree_test(void)
{
	tree<string> tree_test;
}

void data_structure_tests(void)
{
	linked_list_test();
	stack_test();
	queue_test();
	tree_test();
}