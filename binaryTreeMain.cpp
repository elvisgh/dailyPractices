#include <iostream>

#include "binaryTreeStruct.h"

int main()
{
	BinaryTreeNode<char> *p = new BinaryTreeNode<char>();
	createBinaryTree(p);
	preTravel(p);

	return 0;
}
