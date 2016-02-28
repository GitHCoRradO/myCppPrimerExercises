//the code prints:
//10 10
//
#include<iostream>
int main()
{
	int i, &ri = i;
	i = 5; ri = 10;
	std::cout << i << " " << ri << std::endl;
	return 0;
}
