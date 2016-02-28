#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::vector;
using std::string;
int main() {
	vector<string> vec_str;
	string str;
	while (cin >> str) {	
		vec_str.push_back(str);
	}
	return 0;
}
