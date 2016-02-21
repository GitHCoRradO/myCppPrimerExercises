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
	while (cin >> n) {
		ivec.push_back(n);
	}
	cout << endl;
	if (ivec.size() > 0) {
	cout << "The sum of each pair of adjacent elements are:" << endl;
	decltype(ivec.size()) index = 0;
	if (ivec.size()%2 == 1) {
	for (; index < ivec.size() - 1; index += 2) {
		int sum = 0;
		sum = ivec[index] + ivec[index + 1];
		cout << sum << " ";
	}
	cout << ivec[index] << endl;
	}
	else {
	for (;index < ivec.size(); index += 2) {
		int sum = 0;
		sum = ivec[index] + ivec[index + 1];
		cout << sum << " ";
	}
	cout << endl;
	}
	index = 0;
	cout << "The sum of the first and last elments,followed by the sum of the second and second-to-last,and so on,are:" << endl;
	auto large_index = ivec.size();
	if (ivec.size()%2 == 0) {
		for (;index < large_index; ++index, --large_index) {
			int sum = 0;
			sum = ivec[index] +ivec[large_index - 1];
			cout << sum << " ";
		}
		cout << endl;
	}
	else {
	for (;index < large_index - 1; ++index, --large_index) {
		int sum = 0;
		sum = ivec[index] + ivec[large_index - 1];
		cout << sum << " ";
	}
	cout << ivec[index] << endl;
	}
	}
	else {
		cerr << "No integer?!" << endl;
		return -1;
	}
	return 0;
}
