#pragma once

#include "queue_node.hpp"

template <class data>
class queue
{
private:

	queue_node<data>* m_head_pointer;
	queue_node<data>* m_tail_pointer;

	void queue_destructor_helper(queue_node<data>* current_pointer);

public:

	// starter code

	queue();

	~queue();

	// new code
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
queue<data>::queue()
{
	this->m_head_pointer = nullptr;
	this->m_tail_pointer = nullptr;
}

template <class data>
queue<data>::~queue()
{
	queue_destructor_helper(this->m_head_pointer);
	this->m_head_pointer = nullptr;
	this->m_tail_pointer = nullptr;
}

template <class data>
void queue<data>::queue_destructor_helper(queue_node<data>* current_pointer)
{
	if (current_pointer != nullptr)
	{
		queue_destructor_helper(current_pointer->get_next_pointer());
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

