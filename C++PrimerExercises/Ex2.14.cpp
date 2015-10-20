//the value of sum will be printed as 45.
//I do not know what value of i will be printed.
#include<iostream>
int main()
{
	int i = 100 ,sum = 0;
	for (int i = 0; i != 10; ++i) sum+=i;
	std::cout << i << " " << sum << std::endl;
	return 0;
}
//after running the program,I know i will be printed as 100.
//variables defined in an inner scope cannot be used in an outer scope.
