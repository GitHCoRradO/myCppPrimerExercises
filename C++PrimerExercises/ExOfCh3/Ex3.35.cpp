#include <iostream>
#include <iterator>
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main() {
	int ia[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int *beg = begin(ia), *last = end(ia);
	while (beg != last) {
		*beg = 0;
		++beg;
	}
	beg = begin(ia);
	while (beg != last) {
		cout << *beg << " ";
		++beg;
	}
	cout << endl;
	return 0;
}
