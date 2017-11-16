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
	size_t getCount() const;
	LinkNode<T>* getCurrent() const;
	void moveNext();
	void removeCurrent();
	void removeAll();

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
	m_tail->m_link = m_head;
	m_current = m_head;
}

template<class T>
SingleCycleLink<T>::~SingleCycleLink()
{
	removeAll();

	if (m_head != nullptr)
	{
		delete m_head;
		m_head = nullptr;
	}
}

template<class T>
void SingleCycleLink<T>::addTail(const T& value)
{
	LinkNode<T>* add = new LinkNode<T>();
	add->m_data = value;
	
	m_tail->m_link = add;
	m_tail = add;
	m_tail->m_link = m_head;
}

template<class T>
size_t SingleCycleLink<T>::getCount() const
{
	LinkNode<T>* ptr = m_head->m_link;
	size_t count = 0;
	while (ptr != m_head)
	{
		++count;
		ptr = ptr->m_link;
	}

	return count;
}

template<class T>
LinkNode<T>* SingleCycleLink<T>::getCurrent() const
{
	return m_current;
}

template<class T>
void SingleCycleLink<T>::moveNext()
{
	m_current = m_current->m_link;
	while (m_current == m_head)
	{
		m_current = m_current->m_link;
	}
	std::cout << "current move to " << m_current->m_data << std::endl;
}

template<class T>
void SingleCycleLink<T>::removeCurrent()
{
	LinkNode<T>* preCurrent = m_head;
	LinkNode<T>* nodeCurrentDel = m_current;

	while (preCurrent->m_link != m_current)
	{
		preCurrent = preCurrent->m_link;
	}

	preCurrent->m_link = m_current->m_link;

	m_current = preCurrent->m_link;
	while (m_current == m_head)
	{
		m_current = m_current->m_link;
	}
	
	std::cout << nodeCurrentDel->m_data << " out!!!" << std::endl;
	delete nodeCurrentDel;
	nodeCurrentDel = nullptr;

	std::cout << "begin from " << m_current->m_data << " again!" << std::endl;
}

template<class T>
void SingleCycleLink<T>::removeAll()
{
	m_current = m_head->m_link;
	int length = getCount();

	for (int i = 0; i < length; ++i)
	{
		removeCurrent();
	}
	m_current = m_head;
}

#endif