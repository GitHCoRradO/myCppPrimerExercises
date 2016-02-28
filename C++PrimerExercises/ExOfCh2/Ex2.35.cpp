/*	j is int.
	k is a reference to const int.
	p is a pointer to const int.
	initializations of j2 and k2 are illegal.in 'j2 = i',type deduced from i is int.in '&k2 = i',type deduced from i is cosnt int.  */
#include<iostream>
int main()
{
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;
	std::cout << j << " " << j + 2 << " " << i << std::endl;
	std::cout << k << " "
//		  << ++k
		  << std::endl;
	std::cout << *p << " "
//		  << ++*p
		  << std::endl;
	std::cout << j2 << " " << k2 << " "
//		  << ++j2 << " " << ++k2 
		  << std::endl;
	return 0;
}
