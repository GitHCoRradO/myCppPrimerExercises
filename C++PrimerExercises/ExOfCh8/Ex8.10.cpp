#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::vector;
using std::ifstream;
using std::string;
using std::istringstream;
int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	string str;
	vector<string> vec_s;
	while (std::getline(ifst,str)) {
		vec_s.push_back(str);
	}
	for (const auto &line : vec_s) {
		istringstream strm(line);
		string str;
		while(strm >> str)
			std::cout << str << std::endl;
		}
	return 0;
}
