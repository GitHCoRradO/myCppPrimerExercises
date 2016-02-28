#include <iostream>
using std::cout;
using std::endl;
int main() {
	int ia[10] = {0,1,2,3,4,5,6,7,8,9};
	for (auto i : ia)
		cout << i << " ";
	cout << endl;
	return 0;
}
