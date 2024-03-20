#pragma once

#include "queue_node.hpp"

template <class data>
class queue
{
private:

	queue_node<data>* m_head_pointer;
	queue_node<data>* m_tail_pointer;

	void queue_destructor_helper(queue_node<data>* current_pointer);

	queue_node<data>* make_node(data new_data);

public:

	// starter code

	queue();

	~queue();

	// new code

	queue_node<data>* get_head_pointer(void);

	bool enqueue(data new_data);

	bool dequeue(data& dequeued_data);

	friend ostream& operator<<(ostream& right, queue<data>& queue)
	{
		queue_node<data>* current_pointer = queue.get_head_pointer();

		while (current_pointer != nullptr)
		{
			right << *current_pointer;
			current_pointer = current_pointer->get_next_pointer();
		}

		return right;
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

template <class data>
queue_node<data>* queue<data>::make_node(data new_data)
{
	queue_node<data>* new_node_pointer = nullptr;

	new_node_pointer = (queue_node<data>*) new queue_node<data>;

	if (new_node_pointer != nullptr)
	{
		new_node_pointer->set_data(new_data);
	}

	return new_node_pointer;
}

template <class data>
queue_node<data>* queue<data>::get_head_pointer(void)
{
	return this->m_head_pointer;
}

template <class data>
bool queue<data>::enqueue(data new_data)
{
	queue_node<data>* new_node_pointer = make_node(new_data);

	if (new_node_pointer == nullptr)
	{
		return false;
	}
	else
	{
		if (this->m_head_pointer == nullptr) // see if the queue is empty
		{
			this->m_head_pointer = new_node_pointer;
		}
		else
		{
			this->m_tail_pointer->set_link(new_node_pointer);
		}

		this->m_tail_pointer = new_node_pointer;

		return true;
	}
}

template <class data>
bool queue<data>::dequeue(data& dequeued_data)
{
	queue_node<data>* temp = nullptr;

	if (this->m_head_pointer == nullptr)
	{
		return false;
	}
	else
	{
		temp = this->m_head_pointer;
		dequeued_data = this->m_head_pointer->get_data();

		if (this->m_head_pointer == this->m_tail_pointer) // check if there is only one node in the list
		{
			this->m_tail_pointer = nullptr;
		}

		this->m_head_pointer = this->m_head_pointer->get_next_pointer();

		delete temp;

		return true;
	}
}