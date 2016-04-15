#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
void print_elem(vector<int>::const_iterator beg, vector<int>::const_iterator end) {
	if (beg != end) {
		cout << *beg << endl;
		print_elem(++beg, end);
	}
}
int main() {
	vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_elem(ivec.cbegin(), ivec.cend());
	return 0;
}
	
