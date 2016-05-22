#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::fill_n;
int main() {
	vector<int> vec{1, 2, 3, 4, 5, 6};
	fill_n(vec.begin(), vec.size(), 7);
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
	return 0;
}
