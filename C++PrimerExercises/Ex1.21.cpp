#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1,item2;
	std::cin>>item1>>item2;
	if(item1.isbn()==item2.isbn())
	{
		std::cout<<item1+item2<<std::endl;
		return 0;
	}else{
		std::cerr<<"Data must refer to the same ISBN.\n";
		return -1;
		}	
}
//here is one problem:I enter two transactions with different ISBNs,
//whereas the item1+item2 result still is printed as if they have the same ISBN,
//which is the first ISBN.
