#ifndef _LINKSTACH_H_
#define _LINKSTACH_H_

#include "linknode.h"

template<class T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void push(T& value);
	void pop();
	T& getTop() const;
	bool isEmpty() const;
	unsigned int size() const;

private:
	LinkNode<T>* m_top;
	unsigned int m_size;
};

template<class T>
LinkStack<T>::LinkStack() : m_size(0), m_top(NULL)
{
}

template<class T>
LinkStack<T>::~LinkStack()
{
	while (m_top != NULL)
	{
		LinkNode<T>* oldTop = m_top;
		m_top = m_top->m_link;
		delete oldTop;
		--m_size;
	}
}

template<class T>
void LinkStack<T>::push(T& value)
{
	LinkNode<T>* valuePtr = new LinkNode<T>(value);

	valuePtr->m_link = m_top;
	m_top = valuePtr;
	++m_size;
}

template<class T>
void LinkStack<T>::pop()
{
	LinkNode<T>* oldm_top = m_top;
	m_top = m_top->m_link;
	delete oldm_top;
	--m_size;
}

template<class T>
T& LinkStack<T>::getTop() const
{
	assert (NULL != m_size);
	return m_top->m_data;
}

template<class T>
bool LinkStack<T>::isEmpty() const
{
	return NULL == m_size;
}

template<class T>
unsigned int LinkStack<T>::size() const
{
	return m_size;
}

#endif