#pragma once

// I made this after the lab ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "queue.hpp"

#define TEST_CASE "am i here?" // for testing inserts and deletes

bool test_isEmpty(void)
{
	queue<string> test;
	bool result = true;

	if (test.isEmpty() == false)
	{
		cout << "is empty on empty queue test FAILED" << endl;
		result = false;
	}

	test.enqueue("test");

	if (test.isEmpty() == true) // returns true if the queue is empty
	{
		cout << "is empty on not empty queue FALIED" << endl;
		result = false;
	}

	return result;

}

bool test_enqueue(void)
{
	queue<string> test;
	bool result = true;
	string test_case;

	test.enqueue(TEST_CASE);

	if (test.isEmpty() == true)
	{
		cout << "enqueue test FALIED" << endl;
		result = false;
	}

	test_case = test.dequeue();

	if (test_case != TEST_CASE)
	{
		cout << "enqueue test FALIED" << endl;
		result = false;
	}

	return result;
}

bool test_dequeue(void)
{
	queue<string> test;
	string test_case;
	bool result = true;

	test.enqueue(TEST_CASE);

	test_case = test.dequeue();

	if (test_case != TEST_CASE)
	{
		cout << "dequeue test FALED" << endl;
		result = false;
	}

	return result;
}

void run_all_tests(void)
{
	queue<string> test_case;
	bool result = true;

	result = test_isEmpty(); // test #1

	if (result == true)
	{
		cout << "isEmpty test PASSED" << endl;
	}

	result = test_enqueue(); // test #2

	if (result == true)
	{
		cout << "enqueue test PASSED" << endl;
	}

	result = test_dequeue(); // test #3

	if (result == true)
	{
		cout << "dequeue test PASSED" << endl;
	}
}

