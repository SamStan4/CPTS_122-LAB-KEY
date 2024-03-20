#pragma once

template <class data>
class tree_node
{
private:

	data m_data;
	tree_node<data>* m_left_pointer;
	tree_node<data>* m_right_pointer;

public:

	tree_node();

	~tree_node();

	void set_data(data new_data);

	void set_left_pointer(tree_node<data>* new_pointer);

	void set_right_pointer(tree_node<data>* new_pointer);

	data get_data(void);

	tree_node<data>* get_left_pointer(void);

	tree_node<data>* get_right_pointer(void);

	tree_node<data>*& get_left_pointer_reference(void);

	tree_node<data>*& get_right_pointer_reference(void);

	friend ostream& operator<<(ostream& left, tree_node<data>& right)
	{
		left
			<< MAGENTA << "--------------[tree node]-------------" << endl
			<< CYAN << "current address --> 0x" << &right << endl
			<< "contents ---------> " << right.get_data() << endl
			<< "left pointer -----> 0x" << right.get_left_pointer() << endl
			<< "right pointer ----> 0x" << right.get_right_pointer() << endl
			<< MAGENTA << "--------------------------------------" << RESET << endl;

		return left; // DO NOT FORGET TO DO THIS
	}

};

template <class data>
tree_node<data>::tree_node()
{
	this->m_data;
	this->m_left_pointer = nullptr;
	this->m_right_pointer = nullptr;
}

template <class data>
tree_node<data>::~tree_node()
{
	// do nothing
}

template <class data>
void tree_node<data>::set_data(data new_data)
{
	this->m_data = new_data;
}

template <class data>
void tree_node<data>::set_left_pointer(tree_node<data>* new_pointer)
{
	this->m_left_pointer = new_pointer;
}

template <class data>
void tree_node<data>::set_right_pointer(tree_node<data>* new_pointer)
{
	this->m_right_pointer = new_pointer;
}

template <class data>
data tree_node<data>::get_data(void)
{
	return this->m_data;
}

template <class data>
tree_node<data>* tree_node<data>::get_left_pointer(void)
{
	return this->m_left_pointer;
}

template <class data>
tree_node<data>* tree_node<data>::get_right_pointer(void)
{
	return this->m_right_pointer;
}

template <class data>
tree_node<data>*& tree_node<data>::get_left_pointer_reference(void)
{
	return this->m_left_pointer;
}

template <class data>
tree_node<data>*& tree_node<data>::get_right_pointer_reference(void)
{
	return this->m_right_pointer;
}