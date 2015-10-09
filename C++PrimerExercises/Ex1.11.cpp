#include <iostream>
int main()
{
	int a=0,b=0;
	std::cout<<"Enter two integers:"<<std::endl;
	std::cin>>a>>b;
	while(a>b)
	{
		int temp=0;
		temp=a;
		a=b;
		b=temp;
	}
	while(a<b-1)
	{
		std::cout<<++a<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
