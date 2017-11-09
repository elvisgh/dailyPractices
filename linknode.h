#ifndef _LINKNODE_H_
#define _LINKNODE_H_

template <class T>
struct LinkNode
{
	LinkNode():m_link(NULL){}
	LinkNode(T data):m_link(NULL), m_data(data){}
	~LinkNode(){}

	T m_data;
	LinkNode<T>* m_link;
};

#endif