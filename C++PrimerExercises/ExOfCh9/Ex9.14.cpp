#include <iostream>
#include <list>
#include <string>
#include <vector>
using std::list;
using std::vector;
using std::string;

int main() {
	list<const char*> li_str{"to", "be", "or", "not", "to", "be?"};
	vector<string> hamlet_lines;
	hamlet_lines.assign(li_str.begin(), li_str.end());
	for(const auto &s : hamlet_lines)
		std::cout << s << " ";
	std::cout << std::endl;
	hamlet_lines.assign("that", "is", "the", "question.");
	for(const auto &s : hamlet_lines)
		std::cout<< s << " ";
	std::cout << std::endl;
	return 0;
}
