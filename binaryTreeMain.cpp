#include <iostream>

#include "binaryTreeStruct.h"

int main()
{
	BinaryTreeNode<int> *p;
	createBinaryTree(p);
	preTravel(p);

	return 0;
}
