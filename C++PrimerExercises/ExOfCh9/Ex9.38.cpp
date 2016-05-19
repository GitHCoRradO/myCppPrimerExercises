#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec;
	cout << ivec.size() << " " << ivec.capacity() << endl;
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	cout << ivec.size() << " " << ivec.capacity() << endl;
	ivec.reserve(50);
	cout << ivec.size() << " " << ivec.capacity() << endl;
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << ivec.size() << " " << ivec.capacity() << endl;
	ivec.push_back(42);
	cout << ivec.size() << " " << ivec.capacity() << endl;
	ivec.shrink_to_fit();
	cout << ivec.size() << " " << ivec.capacity() << endl;
	return 0;
}
