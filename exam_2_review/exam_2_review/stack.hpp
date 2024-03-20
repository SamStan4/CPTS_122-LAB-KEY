#pragma once

#include "stack_node.hpp"

template <class data>
class stack
{
private:

	stack_node<data>* m_top_pointer;

	void stack_destructor_helper(stack_node<data>* current_pointer);

	stack_node<data>* make_node(data new_data);

public:

	// starter code

	stack();

	~stack();

	// new code

	bool stack_push(data new_data);

	bool stack_pop(data& popped_data);

	bool is_empty(void);

	bool stack_peek(data& top_stack);

	stack_node<data>* get_top_pointer(void);

	friend ostream& operator<<(ostream& left, stack<data>& right)
	{
		stack_node<data>* current_pointer = right.get_top_pointer();

		while (current_pointer)
		{
			left << *current_pointer;
			current_pointer = current_pointer->get_next_pointer();
		}

		return left;
	}
};

//    /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$         /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$    
//   /$$__  $$|__  $$__//$$__  $$| $$__  $$|__  $$__/| $$_____/| $$__  $$       /$$__  $$ /$$__  $$| $$__  $$| $$_____/    
//  | $$  \__/   | $$  | $$  \ $$| $$  \ $$   | $$   | $$      | $$  \ $$      | $$  \__/| $$  \ $$| $$  \ $$| $$       /$$
//  |  $$$$$$    | $$  | $$$$$$$$| $$$$$$$/   | $$   | $$$$$   | $$$$$$$/      | $$      | $$  | $$| $$  | $$| $$$$$   |__/
//   \____  $$   | $$  | $$__  $$| $$__  $$   | $$   | $$__/   | $$__  $$      | $$      | $$  | $$| $$  | $$| $$__/       
//   /$$  \ $$   | $$  | $$  | $$| $$  \ $$   | $$   | $$      | $$  \ $$      | $$    $$| $$  | $$| $$  | $$| $$       /$$
//  |  $$$$$$/   | $$  | $$  | $$| $$  | $$   | $$   | $$$$$$$$| $$  | $$      |  $$$$$$/|  $$$$$$/| $$$$$$$/| $$$$$$$$|__/
//   \______/    |__/  |__/  |__/|__/  |__/   |__/   |________/|__/  |__/       \______/  \______/ |_______/ |________/    

template <class data>
stack<data>::stack()
{
	this->m_top_pointer = nullptr;
}

template <class data>
stack<data>::~stack()
{
	stack_destructor_helper(this->m_top_pointer);
	this->m_top_pointer = nullptr;
}

template <class data>
void stack<data>::stack_destructor_helper(stack_node<data>* current_pointer)
{
	if (current_pointer != nullptr)
	{
		stack_destructor_helper(current_pointer->get_next_pointer());
		delete current_pointer;
	}
}

//   /$$   /$$ /$$$$$$$$ /$$      /$$        /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$    
//  | $$$ | $$| $$_____/| $$  /$ | $$       /$$__  $$ /$$__  $$| $$__  $$| $$_____/    
//  | $$$$| $$| $$      | $$ /$$$| $$      | $$  \__/| $$  \ $$| $$  \ $$| $$       /$$
//  | $$ $$ $$| $$$$$   | $$/$$ $$ $$      | $$      | $$  | $$| $$  | $$| $$$$$   |__/
//  | $$  $$$$| $$__/   | $$$$_  $$$$      | $$      | $$  | $$| $$  | $$| $$__/       
//  | $$\  $$$| $$      | $$$/ \  $$$      | $$    $$| $$  | $$| $$  | $$| $$       /$$
//  | $$ \  $$| $$$$$$$$| $$/   \  $$      |  $$$$$$/|  $$$$$$/| $$$$$$$/| $$$$$$$$|__/
//  |__/  \__/|________/|__/     \__/       \______/  \______/ |_______/ |________/    

template <class data>
stack_node<data>* stack<data>::make_node(data new_data)
{
	stack_node<data>* new_node_pointer = nullptr;

	new_node_pointer = (stack_node<data>*) new stack_node<data>;

	if (new_node_pointer != nullptr)
	{
		new_node_pointer->set_data(new_data);
	}

	return new_node_pointer;
}

template <class data>
bool stack<data>::stack_push(data new_data)
{
	stack_node<data>* new_node_pointer = make_node(new_data);

	if (new_node_pointer != nullptr)
	{
		new_node_pointer->set_link(this->m_top_pointer);

		this->m_top_pointer = new_node_pointer;

		return true;
	}
	else
	{
		return false;
	}
}

template <class data>
bool stack<data>::stack_pop(data& popped_data)
{
	stack_node<data>* temp = nullptr;

	if (this->m_top_pointer == nullptr)
	{
		return false; // the stack is empty, return false
	}
	else
	{
		temp = this->m_top_pointer;
		popped_data = this->m_top_pointer->get_data();                   // cpoy the data at the top of the stack
		this->m_top_pointer = this->m_top_pointer->get_next_pointer();   // update the top pointer
		delete temp;
		return true;
	}
}

template <class data>
bool stack<data>::is_empty(void)
{
	return false;
}

template <class data>
bool stack<data>::stack_peek(data& top_stack)
{
	return false;
}

template <class data>
stack_node<data>* stack<data>::get_top_pointer(void)
{
	return this->m_top_pointer;
}
