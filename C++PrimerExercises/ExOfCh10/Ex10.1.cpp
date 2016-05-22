#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::count;
using std::vector;
int main() {
	vector<int> ivec;
	int i = 0;
	while (cin >> i)
		ivec.push_back(i);
	int val = 7;
	unsigned cnt = count(ivec.cbegin(), ivec.cend(), val);
	cout << val << " apprears " << cnt << " times in ivec." <<endl;
	return 0;
}
