#ifndef _LINKNODE_H_
#define _LINKNODE_H_

template <class T>
class LinkNode
{
public:
	LinkNode():m_link(NULL){}

	~LinkNode()
	{
		delete m_link;
		m_link = NULL;
	}

	void setLink(LinkNode<T>* node)
	{
		m_link = node;
	}

	void setData(T data)
	{
		m_data = data;
	}

private:
	T m_data;
	LinkNode<T>* m_link;
};

#endif