#include "./Ex13.31.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <algorithm>
using std::sort;

int main() {
	vector<HasPtr> vec;
	string s;
	int n = 0;
	while (cin >> s >> n)
		vec.push_back(HasPtr(s,n));
	for(auto elem : vec) {
		print_data(elem);
		cout << endl;
	}
	sort(vec.begin(), vec.end());
	for(auto elem : vec) {
		print_data(elem);
		cout << endl;
	}
	return 0;
}
