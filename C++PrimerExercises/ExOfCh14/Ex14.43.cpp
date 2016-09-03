#include <iostream>
using std::cin;
using std::endl;
using std::cout;
#include <algorithm>
using std::find_if_not;
#include <functional>
using std::modulus;
using std::placeholders::_1;
#include <vector>
using std::vector;
using std::bind;
int main() {
	int n = 0;
	cin >> n;
	vector<int> veci{3, 5, 7, 11, 17};
	auto iter = find_if_not(veci.cbegin(), veci.cend(), bind(modulus<int>(), n, _1));
	for (auto i : veci)
		cout << i << " ";
	cout << endl;
	if (iter != veci.end())
		cout << n << " can at least be divided by " << *iter << endl;
	else
		cout << n << " cannot be divided by any number in veci." << endl;
	return 0;
}
