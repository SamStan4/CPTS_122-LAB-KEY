#pragma once

#include "linked_list_node.hpp"

template <class data>
class linked_list
{
private:

	linked_list_node<data>* m_head_pointer;

	void linked_list_destructor_helper(linked_list_node<data>* current_pointer);

	void linked_list_deep_copy_helper(linked_list_node<data>* current_source_pointer);

	linked_list_node<data>* make_node(data new_data);

	void print_list_reverse_helper(linked_list_node<data>* current_node_pointer);

public:

	// starter code

	linked_list();

	~linked_list();

	void destroy_list(void)
	{
		linked_list_destructor_helper(this->m_head_pointer);
		this->m_head_pointer = nullptr;
	}


	void insert_front(data new_data);

	linked_list_node<data>* get_head_pointer(void);

	friend ostream& operator<<(ostream& left, linked_list& right)
	{
		linked_list_node<data>* current_node_ptr = right.get_head_pointer();

		while (current_node_ptr != nullptr)
		{
			left << *current_node_ptr; // this operator is overloaded
			current_node_ptr = current_node_ptr->get_next_pointer();
		}

		return left;
	}

	// new code

	void bad_equal_operator(linked_list<data>& source_list);

	void print_list_reverse(void);
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
linked_list<data>::linked_list()
{
	this->m_head_pointer = nullptr;
}

template <class data>
void linked_list<data>::linked_list_destructor_helper(linked_list_node<data>* current_pointer)
{
	if (current_pointer != nullptr)
	{
		linked_list_destructor_helper(current_pointer->get_next_pointer());
		delete current_pointer;
	}
}

template <class data>
linked_list<data>::~linked_list()
{
	linked_list_destructor_helper(this->m_head_pointer);
	this->m_head_pointer = nullptr;
}

template <class data>
linked_list_node<data>* linked_list<data>::make_node(data new_data)
{
	linked_list_node<data>* new_node = nullptr;

	new_node = (linked_list_node<data>*) new linked_list_node<data>;
	
	if (new_node != nullptr) // make sure that new worked
	{
		new_node->set_data(new_data);
	}

	return new_node;
}

template <class data>
void linked_list<data>::insert_front(data new_data)
{
	linked_list_node<data>* new_node = nullptr;

	new_node = make_node(new_data);

	new_node->set_link(this->m_head_pointer);

	this->m_head_pointer = new_node;
}

template <class data>
linked_list_node<data>* linked_list<data>::get_head_pointer(void)
{
	return this->m_head_pointer;
}

//   /$$   /$$ /$$$$$$$$ /$$      /$$        /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$    
//  | $$$ | $$| $$_____/| $$  /$ | $$       /$$__  $$ /$$__  $$| $$__  $$| $$_____/    
//  | $$$$| $$| $$      | $$ /$$$| $$      | $$  \__/| $$  \ $$| $$  \ $$| $$       /$$
//  | $$ $$ $$| $$$$$   | $$/$$ $$ $$      | $$      | $$  | $$| $$  | $$| $$$$$   |__/
//  | $$  $$$$| $$__/   | $$$$_  $$$$      | $$      | $$  | $$| $$  | $$| $$__/       
//  | $$\  $$$| $$      | $$$/ \  $$$      | $$    $$| $$  | $$| $$  | $$| $$       /$$
//  | $$ \  $$| $$$$$$$$| $$/   \  $$      |  $$$$$$/|  $$$$$$/| $$$$$$$/| $$$$$$$$|__/
//  |__/  \__/|________/|__/     \__/       \______/  \______/ |_______/ |________/    

// code requested by lab

template <class data>
void linked_list<data>::print_list_reverse_helper(linked_list_node<data>* current_node_pointer)
{
	if (current_node_pointer != nullptr)
	{
		print_list_reverse_helper(current_node_pointer->get_next_pointer());
		cout << *current_node_pointer;
	}
}

template <class data>
void linked_list<data>::print_list_reverse(void)
{
	print_list_reverse_helper(this->m_head_pointer);
}

template <class data>
void linked_list<data>::linked_list_deep_copy_helper(linked_list_node<data>* current_source_pointer)
{
	linked_list_node<data>* new_node_ptr = nullptr;

	if (current_source_pointer != nullptr)
	{
		linked_list_deep_copy_helper(current_source_pointer->get_next_pointer());

		new_node_ptr = make_node(current_source_pointer->get_data()); // this will allocate a linked list node with some data inside of it

		new_node_ptr->set_link(this->m_head_pointer); // insert front

		this->m_head_pointer = new_node_ptr;
	}
}

template <class data>
void linked_list<data>::bad_equal_operator(linked_list<data>& source_list)
{
	this->destroy_list(); // calling the destroy list function will deallocate all of the memory inside the existing list

	this->linked_list_deep_copy_helper(source_list.get_head_pointer());
}

