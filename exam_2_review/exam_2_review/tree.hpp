#pragma once

#include "tree_node.hpp"

template <class data>
class tree // BST
{
private:

	tree_node<data>* m_root_node_pointer;

	void tree_destructor_helper(tree_node<data>* current_pointer);

	tree_node<data>* make_node(data new_data);

	bool insert_data_helper(tree_node<data>*& current_pointer, tree_node<data>* new_node_pointer);

	void in_order_print_helper(tree_node<data>* current_node_pointer);

	void pre_order_print_helper(tree_node<data>* current_node_pointer);

	void post_order_print_helper(tree_node<data>* current_node_pointer);

public:

	tree();

	~tree();

	bool insert_data(data new_data);

	tree_node<data>* get_root_node_pointer(void);

	void in_order_print(void);

	void pre_order_print(void);

	void post_order_print(void);
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
tree<data>::tree()
{
	this->m_root_node_pointer = nullptr;
}

template <class data>
tree<data>::~tree()
{
	tree_destructor_helper(this->m_root_node_pointer);
	this->m_root_node_pointer = nullptr;
}

template <class data>
void tree<data>::tree_destructor_helper(tree_node<data>* current_pointer)
{
	if (current_pointer != nullptr)
	{
		tree_destructor_helper(current_pointer->get_left_pointer());
		tree_destructor_helper(current_pointer->get_right_pointer());
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
tree_node<data>* tree<data>::make_node(data new_data)
{
	tree_node<data>* new_node_pointer = nullptr;

	new_node_pointer = (tree_node<data>*) new tree_node<data>;

	if (new_node_pointer != nullptr)
	{
		new_node_pointer->set_data(new_data);
	}

	return new_node_pointer;
}

template <class data>
bool tree<data>::insert_data_helper(tree_node<data>*& current_pointer, tree_node<data>* new_node_pointer)
{
	if (current_pointer == nullptr) // TIME TO INSERT
	{
		current_pointer = new_node_pointer;
		return true;
	}
	else
	{
		if (current_pointer->get_data() == new_node_pointer->get_data())
		{
			return false; // deplicates, do not insert
		}
		else if (new_node_pointer->get_data() > current_pointer->get_data()) // go right
		{
			return insert_data_helper(current_pointer->get_right_pointer_reference(), new_node_pointer);
		}
		else // new_node_pointer->get_data() < current_pointer->get_data() // go left
		{
			return insert_data_helper(current_pointer->get_left_pointer_reference(), new_node_pointer);
		}
	}
}

template <class data>
tree_node<data>* tree<data>::get_root_node_pointer(void)
{
	return this->m_root_node_pointer;
}

template <class data>
bool tree<data>::insert_data(data new_data)
{
	tree_node<data>* new_node_pointer = make_node(new_data);

	if (new_node_pointer == nullptr)
	{
		return false;
	}
	else
	{
		return insert_data_helper(this->m_root_node_pointer, new_node_pointer);
	}
}

template <class data>
void tree<data>::in_order_print_helper(tree_node<data>* current_node_pointer)
{
	if (current_node_pointer != nullptr)
	{
		// REMEMBER     LEFT --> PRINT --> RIGHT    } for in order print

		in_order_print_helper(current_node_pointer->get_left_pointer());
		cout << *current_node_pointer;
		in_order_print_helper(current_node_pointer->get_right_pointer());
	}
}

template <class data>
void tree<data>::in_order_print(void)
{
	in_order_print_helper(this->m_root_node_pointer);
}

template <class data>
void tree<data>::pre_order_print_helper(tree_node<data>* current_node_pointer)
{
	if (current_node_pointer != nullptr)
	{
		// PRINT --> LEFT --> RIGHT for pre order print

		cout << *current_node_pointer;
		pre_order_print_helper(current_node_pointer->get_left_pointer());
		pre_order_print_helper(current_node_pointer->get_right_pointer());
	}
}

template <class data>
void tree<data>::pre_order_print(void)
{
	pre_order_print_helper(this->m_root_node_pointer);
}

template <class data>
void tree<data>::post_order_print_helper(tree_node<data>* current_node_pointer)
{
	if (current_node_pointer != nullptr)
	{
		// LEFT --> RIGHT --> PRINT for post order print

		pre_order_print_helper(current_node_pointer->get_left_pointer());
		pre_order_print_helper(current_node_pointer->get_right_pointer());
		cout << *current_node_pointer;
	}
}

template <class data>
void tree<data>::post_order_print(void)
{
	post_order_print_helper(this->m_root_node_pointer);
}
