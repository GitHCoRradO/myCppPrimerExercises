#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item sum;
	if(std::cin>>sum)
	{
		Sales_item item;  //here,when I put item outside if together
                                  //with sum,the running result always goes wrong. why?
		while(std::cin>>item)
		{
			if(sum.isbn()==item.isbn())sum+=item;
			else{
			std::cout<<sum<<std::endl;
			sum=item;
			}
		}
	std::cout<<sum<<std::endl;
	}
	else{
	std::cerr<<"No data? :P"<<std::endl;
	return -1;
	}
	return 0;
}
