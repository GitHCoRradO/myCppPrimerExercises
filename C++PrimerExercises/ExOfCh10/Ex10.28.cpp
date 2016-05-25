#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::copy;
using std::for_each;
using std::vector;
using std::back_inserter;
using std::inserter;
using std::front_inserter;
int main() {
	vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> lst1, lst2, lst3;
	copy(ivec.begin(), ivec.end(), front_inserter(lst1));
	copy(ivec.begin(), ivec.end(), back_inserter(lst2));
	copy(ivec.begin(), ivec.end(), inserter(lst3, lst3.begin()));
	for_each(lst1.begin(), lst1.end(), [](int i) { cout << i << " "; });
	cout << endl;
	for_each(lst2.begin(), lst2.end(), [](int i) { cout << i << " "; });
	cout << endl;
	for_each(lst3.begin(), lst3.end(), [](int i) { cout << i << " "; });
	cout << endl;
	return 0;
}
