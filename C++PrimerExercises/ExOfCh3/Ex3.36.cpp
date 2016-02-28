#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
// The definition of two vectors or strings being equal are defined by the standard library,whereas the equality or relationship of
//arrays should be defined specificly,similiar to those of vectors and strings.
int main() {
	vector<int> ivec{1,2,3}, ivec1{1,2,3,4};
	if (ivec == ivec1)
		cout << "ivec and ivec1 are equal." << endl;
	else 
		cout << "ivec and ivec1 are unequal." << endl;
//the following would be more sophisticated.
	int ia[] = {1, 2, 3, 4}, ib[] = {1, 2, 3};
	int *ia_beg = begin(ia), *ia_end = end(ia), *ib_beg = begin(ib), *ib_end = end(ib);
	auto ia_size = ia_end - ia_beg, ib_size = ib_end - ib_beg;
	if (ia_size == ib_size) {
		while (*ia_beg == *ib_beg && ia_beg != ia_end) {
			++ia_beg;
			++ib_beg;
		}
		if (ia_beg == ia_end)
			cout << "ia and ib are equal." << endl;
		else
			cout << "ia and ib are unequal." << endl;
	}
	else		
		cout << "ia and ib are unequal." << endl;
	return 0;
}	
