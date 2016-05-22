#include <iostream>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;
using std::accumulate;
using std::vector;

int main() {
	vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << sum << endl;
	return 0;
}
