#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item,SUM;
	std::cout<<"pls enter the transactions:\n";
	for(;std::cin>>item;)SUM+=item;
	std::cout<<"SUM=\n"<<SUM<<std::endl;
	return 0;
}
