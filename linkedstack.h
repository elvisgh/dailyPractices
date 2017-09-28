#ifndef _LINKEDSTACK_H_
#define _LINKEDSTACH_H_

#include <iostream>

template<class T>
struct LinkNode
{
	int value;
	LinkNode<T>* link;
	LinkNode(T& value) : value(value), link(NULL){}
	~LinkNode(){std::cout << value << " deleted" << std::endl;}
};

template<class T>
class LinkedStack
{
public:
	LinkedStack();
	~LinkedStack();
	void push(T& value);
	void pop();
	T& getTop() const;
	bool isEmpty() const;
	unsigned int length() const;

private:
	LinkNode<T>* top;
	unsigned int size;
};

template<class T>
LinkedStack<T>::LinkedStack() : size(0), top(NULL)
{
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
	while (top != NULL)
	{
		LinkNode<T>* oldTop = top;
		top = top->link;
		delete oldTop;
		--size;
	}
}

template<class T>
void LinkedStack<T>::push(T& value)
{
	LinkNode<T>* valuePtr = new LinkNode<T>(value);

	valuePtr->link = top;
	top = valuePtr;
	++size;
}

template<class T>
void LinkedStack<T>::pop()
{
	LinkNode<T>* oldTop = top;
	top = top->link;
	delete oldTop;
	--size;
}

template<class T>
T& LinkedStack<T>::getTop() const
{
	assert (NULL != size);
	return top->value;
}

template<class T>
bool LinkedStack<T>::isEmpty() const
{
	return NULL == size;
}

template<class T>
unsigned int LinkedStack<T>::length() const
{
	return size;
}

#endif