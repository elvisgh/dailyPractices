#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <iostream>
using namespace std;

#include "linknode.h"

template <class T>
class Iterator
{
public:
	Iterator():m_current(nullptr){}
	Iterator(LinkNode<T>* pointer):m_current(pointer){}

	void operator= (LinkNode<T>* pointer);
	LinkNode<T>*& getCurrent();

	Iterator<T>& operator++();         //before
	Iterator<T> operator++ (int);   //behind
	bool operator==(LinkNode<T>* pointer);
	bool operator!=(LinkNode<T>* pointer);
	
	friend ostream& operator<<(ostream& out, const Iterator<T>& it);

private:
	LinkNode<T>* m_current;
};

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
	m_current = m_current->m_link;
	return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator++ (int)
{
	const Iterator<T> temp = *this;
	m_current = m_current->m_link;
	return temp;
}

template<class T>
bool Iterator<T>::operator==(LinkNode<T>* pointer)
{
	return m_current == pointer;
}

template<class T>
bool Iterator<T>::operator!=(LinkNode<T>* pointer)
{
	return m_current != pointer;
}

template<class T>
ostream& operator<<(ostream& out, const Iterator<T>& it)
{
	out << it.getCurrent()->m_data;
	return out;
}

template<class T>
void Iterator<T>::operator=(LinkNode<T>* pointer)
{
	m_current = pointer;
}

template<class T>
LinkNode<T>*& Iterator<T>::getCurrent()
{
	return m_current;
}

#endif