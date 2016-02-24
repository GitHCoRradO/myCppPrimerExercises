#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main() {
	vector<int> ivec;
	for (decltype(ivec.size()) i = 0; i <= 9; ++i)
		ivec.push_back(i);
	vector<int> ivec1(ivec);               //vector<int> ivec1;
	for (auto i : ivec1)		       //ivec1 = ivec;           this kind of assignment is also okay.
		cout << i << " ";
	cout << endl;
	return 0;
}
