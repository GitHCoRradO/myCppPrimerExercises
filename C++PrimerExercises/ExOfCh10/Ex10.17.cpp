#include "../ExOfCh7/Ex7.21.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;

int main() {
	vector<Sales_data> vec;
	for (unsigned i = 0; i != 5; ++i) {
		Sales_data trans(cin);
		vec.push_back(trans);
	}
	sort(vec.begin(), vec.end(), [](const Sales_data &item1, const Sales_data &item2) { return item1.isbn() < item2.isbn(); });
	for (const auto &item : vec)
		print(cout, item) << endl;
	return 0;
}
