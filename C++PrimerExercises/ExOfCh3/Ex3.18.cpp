//illegal.ivec is empty.subscripting an empty vector is undefined.
//CHANGE THE CODE INTO THIS WOULD WORK:
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec(1);
	cout << ivec[0] << endl;
	ivec[0] = 42;
	cout << ivec[0] << endl;
	return 0;
}
