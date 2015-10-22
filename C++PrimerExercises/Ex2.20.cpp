//the program evaluates the expression '*p1 * *p1'.'*p1 * *p1'is equal to 'i * i'.the result is 42*42(1764).and then the program assigns 1764 to i.
#include<iostream>
int main()
{
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;
	std::cout << *p1 << " "  << i <<std::endl;
	return 0;
}
