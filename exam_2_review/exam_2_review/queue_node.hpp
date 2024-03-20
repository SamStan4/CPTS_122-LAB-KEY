#pragma once

#include "imports.hpp"

template <class data>
class queue_node
{
private:
	data m_data;                              // the m means "member" cause it is a data member
	queue_node<data>* m_next_pointer;

public:

	queue_node();

	~queue_node();

	void set_link(queue_node<data>* new_pointer);

	void set_data(data new_data);

	queue_node<data>* get_next_pointer(void);

	data get_data(void);



	friend ostream& operator<<(ostream& left, queue_node<data>& right)
	{
		left
			<< MAGENTA << "-------------[queue node]-------------" << endl
			<< CYAN << "current address --> 0x" << &right << endl
			<< "contents ---------> " << right.get_data() << endl
			<< "next address -----> 0x" << right.get_next_pointer() << endl
			<< MAGENTA << "--------------------------------------" << RESET << endl;

		return left; // DO NOT FORGET TO DO THIS
	}

};

template <class data>
queue_node<data>::queue_node()
{
	this->m_next_pointer = nullptr;
	// I am not doing anything with the m_data because this is a template
	this->m_data;
}
template <class data>
queue_node<data>::~queue_node()
{
	// do nothing, the stack class will take care of all dynamically allocated objects
}

template <class data>
void queue_node<data>::set_link(queue_node<data>* new_pointer)
{
	this->m_next_pointer = new_pointer;
}

template <class data>
void queue_node<data>::set_data(data new_data)
{
	this->m_data = new_data;
}

template <class data>
queue_node<data>* queue_node<data>::get_next_pointer(void)
{
	return this->m_next_pointer;
}

template <class data>
data queue_node<data>::get_data(void)
{
	return this->m_data;
}