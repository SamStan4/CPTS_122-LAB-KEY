#pragma once

#include "queue_node.hpp"

template <class T>
class queue
{
private:

	queueNode<T>
		* headPtr,
		* tailPtr;

	void printQueueRecursiveHelper(queueNode<T>* curPtr) const;

	void destructorHelper(queueNode<T>* curPtr);

public:

	queue();

	~queue();

	queueNode<T>* makeNode(T newData);

	bool isEmpty(void) const;

	bool enqueue(T newData);

	T dequeue(void);

	void printQueueRecursive(void) const;

	void printQueueIterative(void) const;
};

template <class T>
queue<T>::queue()
{
	this->headPtr = nullptr;
	this->tailPtr = nullptr;
}

template <class T>
queue<T>::~queue()
{
	destructorHelper(this->headPtr);
	this->headPtr = nullptr;
	this->tailPtr = nullptr;
}

template <class T>
void queue<T>::destructorHelper(queueNode<T>* curPtr)
{
	if (curPtr != nullptr)
	{
		try
		{
			destructorHelper(curPtr->getLink());
			delete curPtr;
		}
		catch (...)
		{
			cout << "error in the destructor" << endl;
		}
	}
}


template <class T>
queueNode<T>* queue<T>::makeNode(T newData)
{
	queueNode<T>* newNode = (queueNode<T>*) new queueNode<T>;

	newNode->setData(newData);

	return newNode;
}

template <class T>
bool queue<T>::isEmpty(void) const
{
	if (this->headPtr == nullptr) // if the head pointer is nullptr, then the list is empty
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool queue<T>::enqueue(T newData)
{
	queueNode<T>* newNode = makeNode(newData);

	if (newNode == nullptr)
	{
		return false;
	}
	else
	{
		// queue the item

		if (this->headPtr == nullptr) // queue is empty
		{
			this->headPtr = newNode;
			this->tailPtr = newNode;
		}
		else // queue is not empty
		{
			this->tailPtr->setLink(newNode);
			this->tailPtr = newNode;
		}

		return true;
	}
}

template <class T>
T queue<T>::dequeue(void)
{
	try 
	{ // code goes here
		if (this->headPtr != nullptr)
		{
			queueNode<T>* pTarget = this->headPtr; // node to be deleted

			T tempData = pTarget->getData(); // data to be returned

			if (this->tailPtr == this->headPtr) 
			{
				this->tailPtr == nullptr;
			}

			this->headPtr = pTarget->getLink();

			delete pTarget;

			return tempData; 
		}
	}
	catch (...) // catches all types of exceptions (...)
	{
		cout << "there was an exception inside the dequeue function" << endl;
	}
}

template <class T>
void queue<T>::printQueueRecursive(void) const
{
	printQueueRecursiveHelper(this->headPtr);
}

template <class T>
void queue<T>::printQueueRecursiveHelper(queueNode<T>* curPtr) const
{
	if (curPtr != nullptr) // stop when the current pointer is nullptr, this is the end condition
	{
		cout << curPtr->getData() << endl;
		printQueueRecursiveHelper(curPtr->getLink());
	}
}

template <class T>
void queue<T>::printQueueIterative(void) const
{
	queueNode<T> *cur = this->headPtr;

	while (cur != nullptr)
	{
		cout << cur->getData() << endl;
		cur = cur->getLink();
	}
}

