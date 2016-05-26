#include <iostream>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;
int main() {
	vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> lst(ivec.crbegin() + 2, ivec.crbegin() + 7);
	for (auto i : lst)
		cout << i << " ";
	cout << endl;
	return 0;
}
