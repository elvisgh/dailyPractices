#include <iostream>
using namespace std;

int main()
{
	int i = 5;
	auto f = [&](int x){return x++;}(i);
	cout << [](int x, int y){return x + y;}(3,4) << endl;
	
	cout << "f=" << f << endl;
	auto ff =[&]{i++;};
	ff();
	cout << "i=" << i << endl;
	return 0;
}
