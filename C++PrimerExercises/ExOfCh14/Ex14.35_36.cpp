#include "./Ex14.35.h"
#include <vector>
using std::vector;

int main() {
	ReadLine rl;
	vector<string> vecl;
	while (std::cin)
		vecl.push_back(rl(std::cin));
	for (const auto &l : vecl)
		std::cout << l << std::endl;
	std::cout << vecl.size() << std::endl;
	return 0;
}
