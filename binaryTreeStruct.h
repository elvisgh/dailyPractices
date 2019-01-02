#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>

namespace binaryTree
{
template <class T>
class BinaryTreeNode
{
private:
	T m_data;
	BinaryTreeNode<T> *m_leftChild;
	BinaryTreeNode<T> *m_rightChild;

public:
	BinaryTreeNode():m_leftChild(NULL),m_rightChild(NULL){};
	BinaryTreeNode(const T& data,  BinaryTreeNode<T>* leftChild, BinaryTreeNode<T>* rightChild)
	{
		m_data = data;
		m_leftChild = leftChild;
		m_rightChild = rightChild;
	}

	BinaryTreeNode<T>* getLeftChild()
	{
		return m_leftChild;
	}

	BinaryTreeNode<T>* getRightChild()
	{
		return m_rightChild;
	}

	void setLeftChild(BinaryTreeNode<T> *leftChild)
	{
		m_leftChild = leftChild;
	}

	void setRightChild(BinaryTreeNode<T> *rightChild)
	{
		m_rightChild = rightChild;
	}

	T getData() const
	{
		return m_data;
	}

	void setData(const T& data)
	{
		m_data = data;
	}

};

template <class T>
BinaryTreeNode<T> *createBinaryTree(BinaryTreeNode<T> *p)
{
	T ch;
	std::cin >> ch;
	if(ch == '#')
	{
		p = NULL;
	}
	else
	{
		p = new BinaryTreeNode<T>();
		p->setData(ch);
		createBinaryTree(p-getLeftChild());
		createBinaryTree(p-getRightChild());
	}

	return p;
};
}

#endif
