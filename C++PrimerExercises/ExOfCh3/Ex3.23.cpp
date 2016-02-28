#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() {
	vector<int> ivec(10);
	cout << "Input 10 integers:" << endl;
	for (auto it = ivec.begin(); it != ivec.end(); ++it) {
		int n = 0;
		cin >> n;
		*it = n;
	}
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		*it *= *it;
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
