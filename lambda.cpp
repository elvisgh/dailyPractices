#include <iostream>

#include <algorithm> //for_each
#include <vector>

int main()
{
	/*lambda expression : [capture list] (params list) mutable exception-> return type { function body }*/
	
	auto tmp = 123;
	auto f = [tmp]{std::cout << "tmp = " << tmp << std::endl;};
	f();

	auto result = [=](int para){return para;}(tmp);//(params list must be clear variable type, can not be AUTO)
	std::cout << "pass-by-value result = " << result << std::endl;

	result = [&](int para){para = 321; return para;}(tmp);
	std::cout << "pass-by-reference result = " << result << std::endl; 



	std::vector<int> intV;
	intV.push_back(1);
	intV.push_back(2);

	for_each(intV.begin(), intV.end(), [](int para){std::cout << para << std::endl;});

	system("pause");
	return 0;
}