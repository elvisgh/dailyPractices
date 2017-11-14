#include <iostream>

#include "linkstack.h"
#include "linestack.h"
#include "singlecyclelink.h"

void josCicle()
{
	SingleCycleLink<int> cycle;
	
	for (int i = 0; i < 15; ++i)
	{
		cycle.addTail(i);
	}

	std::cout << "cycle count = " << cycle.getCount() << std::endl;

	cycle.moveNext();
	std::cout << "begin from " << cycle.getCurrent()->m_data << " again!" << std::endl;
	while (cycle.getCount() != 1)
	{
		for (int i = 0; i < 4; ++i)
		{
			cycle.moveNext();
		}
		cycle.removeCurrent();
		std::cout << cycle.getCount() << " elements left." << std::endl;
	}

	std::cout << cycle.getCurrent()->m_data << " left!!!" << std::endl;
}

void testLinkStack()
{
	LinkStack<int> t;

	std::cout << "size : " << t.size() << std::endl;

	for (int i = 0; i < 11; ++i)
	{
		t.push(i);
	}

	std::cout << "size : " << t.size() << std::endl;

	t.pop();

	std::cout << "size : " << t.size() << std::endl;

	int add = 11;
	t.push(add);

	std::cout << "size : " << t.size() << std::endl;
}

void testLineStack()
{
	LineStack<int> t(10);

	std::cout << "size : " << t.size() << std::endl;
	std::cout << "capacity : " << t.capacity() << std::endl;

	for (int i = 0; i < 11; ++i)
	{
		t.push(i);
	}

	std::cout << "size : " << t.size() << std::endl;
	std::cout << "capacity : " << t.capacity() << std::endl;

	t.pop();

	std::cout << "size : " << t.size() << std::endl;
	std::cout << "capacity : " << t.capacity() << std::endl;

	int add = 11;
	t.push(add);

	std::cout << "size : " << t.size() << std::endl;
	std::cout << "capacity : " << t.capacity() << std::endl;
}

int main()
{
	//testLinkStack();
	//testLineStack();

	josCicle();

	system("pause");
	return 0;
}