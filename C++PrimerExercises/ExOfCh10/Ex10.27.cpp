#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::unique_copy;
using std::back_inserter;
using std::inserter;
using std::for_each;
using std::sort;
int main() {
	vector<int> ivec{0, 1, 2, 3, 5, 6, 9, 1, 3, 6, 7, 8, 8, 0};
	list<int> lst1, lst2;
	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.begin(), ivec.end(), back_inserter(lst1));
	unique_copy(ivec.begin(), ivec.end(), inserter(lst2, lst2.begin()));
	for_each(lst1.begin(), lst1.end(), [](int i){ cout << i << " "; });
	cout << endl;
	for_each(lst2.begin(), lst2.end(), [](int i){ cout << i << " "; });
	cout << endl;
	return 0;
}
