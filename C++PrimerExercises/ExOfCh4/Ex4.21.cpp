#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main() {
	vector<int> ivec = {1,2,3,4,5,6,7,8,9,10};
	for (auto &i : ivec) {
		if (i % 2 == 1)		//actually,for the first time,I did not use conditional operator.
			i *= 2;		// i = (i % 2 == 1) ? (i * 2) : i;
	}				//more simple version: i = (i % 2) ? (i * 2) : i;
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;
	return 0;
}
