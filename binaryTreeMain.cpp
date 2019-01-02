#include <iostream>

#include "binaryTreeStruct.h"

namespace binaryTree
{
template <class T>
void preTravel(BinaryTreeNode<T> *p)
{
	if (p)
	{
		std::cout << p->getData() << " ";
		preTravel(p->getLeftChild());
		preTravel(p->getRightChild());
	}
}

template <class T>
int main()
{
	BinaryTreeNode *p = new BinaryTreeNode<T>();
	createBinaryTree(p);
	preTravel(p);

	return 0;
}
}
