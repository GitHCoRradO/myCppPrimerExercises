#include <iostream>
#include "./Ex8.1.h"

int main() {
	std::istream &is = func(std::cin);
	std::cout << is.good() << std::endl;
	return 0;
}
