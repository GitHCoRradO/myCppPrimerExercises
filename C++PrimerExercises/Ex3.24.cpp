#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
int main() {
	vector<int> ivec;
	cout << "Input a set of integers,separated by space,hit Ctrl+D when you finish:" << endl;
	int n = 0;
	while (cin >> n)
		ivec.push_back(n);
	cout << endl;
	if (ivec.size() > 0) {
		cout << "The sum of each pair of adjacent elements are:" << endl;
		if (ivec.size() % 2 == 1) {
			for (auto beg = ivec.begin(),end = ivec.end() - 1; beg != end; beg += 2) {
				int sum = 0;
				sum = *beg + *(beg + 1);
				cout << sum << " ";
			cout << *beg << endl;
			}
		}
		else {
		for (auto beg = ivec.begin(),end = ivec.end(); beg != end; beg += 2) {
			int sum = 0;
			sum = *beg + *(beg + 1);
			cout << sum << " ";
		}
		cout << endl;
		}
	cout << "The sum of the first and last elements,followed by the sum of the second and second-to-last,and so on,are:" << endl;
	if (ivec.size() % 2 == 0) {
		for (auto beg = ivec.begin(), end = ivec.end(); beg != end; ++beg, --end) {
			int sum = 0;
			sum = *beg + *(end - 1);
			cout << sum << " ";
		}
		cout << endl;
	}
	else {
	for (auto beg = ivec.begin(), end = ivec.end() - 1; beg != end; ++beg, --end) {
		int sum = 0;
		sum = *beg + *end;
		cout << sum << " ";
	}
	cout << *beg << endl;
	}
	}
	else {
		cerr << "No integer?!" << endl;
		return -1;
	}
	return 0;
}
