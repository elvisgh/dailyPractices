#include <iostream>

#include "binaryTreeStruct.h"

int main()
{
	BinaryTreeNode<char> *p;
	createBinaryTree(&p);
	preTravel(p);

	return 0;
}
