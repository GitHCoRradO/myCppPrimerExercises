#include "./Ex16.6.h"
#include <iostream>
#include <string>
using std::string;
int main() {
	auto p1 = begarr("arrayofnone/");
	auto p2 = endarr("arrayofnone/");
	std::cout << *p1 << std::endl;
	string sarr[] = {"array", "list", "vector"};
	std::cout << *(begarr(sarr) + 1) << std::endl;
	return 0;
}
