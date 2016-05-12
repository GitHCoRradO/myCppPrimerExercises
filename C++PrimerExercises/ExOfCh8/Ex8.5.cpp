#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::ifstream;

void readFile(ifstream &ifst, vector<string> &vec_s) {
	while(ifst) {
		string s;
		ifst >> s;
		vec_s.push_back(s);
	}
}

int main() {
	ifstream ifst("./testfile");
	vector<string> vec_s;
	readFile(ifst,vec_s);
	for(auto &s : vec_s)
		std::cout << s << "\n";
	std::cout << std::endl;
	return 0;
}
