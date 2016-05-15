#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> v1{1, 2, 3, 4, 5};
	vector<int> v2{3, 2, 3, 4, 5};
	cout << (v1 == v2) << endl;
	return 0;
}
