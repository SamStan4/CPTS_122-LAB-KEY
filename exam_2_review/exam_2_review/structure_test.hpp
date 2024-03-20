#pragma once

#include "linked_list.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "tree.hpp"

void linked_list_test(void)
{
	linked_list<string> linked_list_test;
	linked_list<string> linked_list_test_;

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

	system("pause");

	system("cls");


	linked_list_test_.bad_equal_operator(linked_list_test);

	cout << linked_list_test_;
	
	cout << "=================================================================" << endl;

	cout << linked_list_test;

	cout << "=================================================================" << endl;

	linked_list_test.print_list_reverse();


}

void stack_test(void)
{
	stack<string> stack_test;
	string test_data;

	stack_test.stack_push("1");
	stack_test.stack_push("2");
	stack_test.stack_push("3");
	stack_test.stack_push("4");
	stack_test.stack_push("5");
	stack_test.stack_push("6");
	stack_test.stack_push("7");
	stack_test.stack_push("8");
	stack_test.stack_push("9");
	stack_test.stack_push("10");

	cout << stack_test;

	stack_test.stack_pop(test_data);

	cout << "here is the the data popped: " << test_data << endl;

	cout << stack_test;
}

void queue_test(void)
{
	queue<string> queue_test;
	string test_data;

	queue_test.enqueue("1");     // comment and uncomment stuff to test on empty
	queue_test.enqueue("2");
	queue_test.enqueue("3");
	queue_test.enqueue("4");
	queue_test.enqueue("5");
	queue_test.enqueue("6");
	queue_test.enqueue("7");
	queue_test.enqueue("8");
	queue_test.enqueue("9");
	queue_test.enqueue("10");

	cout << queue_test;

	system("pause");

	queue_test.dequeue(test_data);

	cout << "dequeued data: " << test_data << endl;

	cout << queue_test;


}

void tree_test(void)
{
	tree<int> tree_test;

	tree_test.insert_data(6);
	tree_test.insert_data(10);
	tree_test.insert_data(2);
	tree_test.insert_data(3);
	tree_test.insert_data(4);
	tree_test.insert_data(5);
	tree_test.insert_data(7);
	tree_test.insert_data(8);
	tree_test.insert_data(1);
	tree_test.insert_data(9);



	//tree_test.in_order_print();

	//tree_test.pre_order_print();

	tree_test.post_order_print();
}

void data_structure_tests(void)
{
	// comment and uncomment
	linked_list_test();
	//stack_test();
	//queue_test();
	//tree_test();
}