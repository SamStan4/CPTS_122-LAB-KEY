#pragma once

#include "includes.hpp"

template <class T>
class queueNode
{
private: 
	T data; // in the lab this is the string
	queueNode* link;

public:

	queueNode();

	queueNode(T newData);

	~queueNode();

	T getData(void) const;

	queueNode* getLink() const;

	void setData(T newData);

	void setLink(queueNode* newLink);
};

template <class T>
queueNode<T>::queueNode(T newData)
{
	this->link = nullptr;
	this->data = newData;
}

template <class T>
queueNode<T>::queueNode()
{
	this->link = nullptr;
}

template <class T>
queueNode<T>::~queueNode()
{
	// do nothing i think
}

template <class T>
T queueNode<T>::getData() const
{
	return this->data;
}

template <class T>
queueNode<T>* queueNode<T>::getLink() const
{
	return this->link;
}

template <class T>
void queueNode<T>::setData(T newData)
{
	this->data = newData;
}
template <class T>
void queueNode<T>::setLink(queueNode* newLink)
{
	this->link = newLink;
}
