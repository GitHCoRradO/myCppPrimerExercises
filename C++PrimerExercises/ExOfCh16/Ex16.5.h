#ifndef EX_16_5_H
#define EX_16_5_H
#include <iostream>

template <unsigned N, typename T>
void print(T (&p)[N]) {
	for (auto &elem : p)
		std::cout << elem << " ";
	std::cout << std::endl;
}
#endif	
