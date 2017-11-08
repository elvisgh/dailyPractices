#ifndef _SINGLECYCLELINK_H_
#define _SINGLECYCLELINK_H_

#include "linknode.h"

template<class T>
class SingleCycleLink
{
public:
	SingleCycleLink();
	~SingleCycleLink();

	void addTail(const T& value);
	void removeCurrent();
	size_t getCount() const;
	LinkNode<T>* getCurrent() const;
	bool isEmpty() const;

private:
	LinkNode<T>* m_head;
	LinkNode<T>* m_tail;
	LinkNode<T>* m_current;
};

template<class T>
SingleCycleLink<T>::SingleCycleLink()
{
	m_head = new LinkNode<T>();
	m_tail = m_head;
	m_current = m_head;
	m_tail->setLink(m_head);
}

template<class T>
SingleCycleLink<T>::~SingleCycleLink()
{
	delete m_head;
	m_head = nullptr;
		
	delete m_tail;
	m_tail = nullptr;

	delete m_current;
	m_current = nullptr;
}

template<class T>
void SingleCycleLink<T>::addTail(const T& value)
{
	LinkNode<T>* newNode = new LinkNode<T>();
	newNode->setData(value);
	
	m_tail->
}

#endif