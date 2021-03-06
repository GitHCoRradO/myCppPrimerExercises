#include <iostream>
using std::cout;
using std::endl;
int main() {
	int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	cout << "Range for version:" << endl;
	for (const auto &ia_row : ia) {	
		for (auto ia_col : ia_row) {
			cout << ia_col << ' ';
		}
		cout << endl;
	}
	cout << "ordinary for loop using subscripts version:" << endl;
	for (size_t row = 0; row != 3; ++row) {
		for (size_t col = 0; col != 4; ++col) {
			cout << ia[row][col] << ' ';
		}
		cout << endl;
	}
	cout << "ordinary for loop using pointers version:" << endl;
	for (auto p = ia; p != ia + 3; ++p) {	
		for (auto q = *p; q != *p + 4; ++q) {	
			cout << *q << ' ';
		}
		cout << endl;
	}
	return 0;
}
