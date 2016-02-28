#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main() {
	vector<int> ivec{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	auto size_ivec = ivec.size();
	int arr[size_ivec] = {};
	for (unsigned i = 0; i != size_ivec; ++i)
		arr[i] = ivec[i];
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
	return 0;
}
