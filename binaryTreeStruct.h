#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>

template <class T>
class BinaryTreeNode
{
private:
	T m_data;
	BinaryTreeNode<T> *m_leftChild;
	BinaryTreeNode<T> *m_rightChild;

public:
	BinaryTreeNode(){};
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

template <typename T>
void createBinaryTree(BinaryTreeNode<T> *p)
{
	char ch;
	std::cin >> ch;
	if(ch == '#')
	{
		p = NULL;
	}
	else
	{
		p->setData(ch);
		BinaryTreeNode<T> *left = new BinaryTreeNode<T>();
		BinaryTreeNode<T> *right = new BinaryTreeNode<T>();
        
		p->setLeftChild(left);
		p->setRightChild(right);
		createBinaryTree(left);
		createBinaryTree(right);
	}
}

template <typename T>
void preTravel(BinaryTreeNode<T> *p)
{
	if (NULL != p)
	{
		std::cout << p->getData() << " ";
		preTravel(p->getLeftChild());
		preTravel(p->getRightChild());
	}
}


#endif
