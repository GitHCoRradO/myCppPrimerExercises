#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "./Ex16.16.h"
#include <string>
using std::string;

int main() {
	Vec<int> vi{0, 1, 2, 3, 4, 5};
	for (auto i : vi)
		cout << i << " ";
	cout << endl;
	Vec<string> vs;
	for (size_t i = 0;i != 5; ++i) {
		string s;
		cin >> s;
		vs.push_back(s);
	}
	for (auto &s : vs)
		cout << s << " ";
	cout << endl;
	return 0;
}	
