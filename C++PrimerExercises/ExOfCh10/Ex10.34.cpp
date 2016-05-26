#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main() {
	vector<int> vec{1, 2, 3, 4, 5, 6, 7};
	for (auto it = vec.crbegin(); it != vec.crend(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
