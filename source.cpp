#include <iostream>

#include "linkedstack.h"
#include "linestack.h"

int main()
{
	//LinkedStack<char> t;
	LineStack<char> t;

	std::cout << t.length() << std::endl;

	char a = 'a', b = 'b';
	t.push(a);
	t.push(b);
	
	std::cout << t.length() << std::endl;

	t.pop();

	std::cout << t.length() << std::endl;

	system("pause");
	return 0;
}