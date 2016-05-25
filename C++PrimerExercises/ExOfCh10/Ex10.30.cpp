#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::vector;
using std::copy;
int main() {
	istream_iterator<int> is_iter(cin), eof;
	ostream_iterator<int> os_iter(cout, " ");
	vector<int> ivec(is_iter, eof);
	sort(ivec.begin(), ivec.end());
	//this is how copy is used:
	copy(ivec.begin(), ivec.end(), os_iter);
	cout << endl;
//	for (auto i : ivec)
//		*os_iter++ = i;
//	cout << endl;
	return 0;
}
