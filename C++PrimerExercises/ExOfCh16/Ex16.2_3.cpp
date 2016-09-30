#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "../ExOfCh14/Ex14.2_Sales_data.h"

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main() {
	string s1("fuck"), s2("dirty");
	cout << compare(s1, s2) << endl;
	int i1 = 0, i2 = 2;
	cout << compare(i1, i2) << endl;
	Sales_data sd1(s1, 10, 5.5), sd2(s2, 10, 5.5);
	cout << compare(sd1, sd2) << endl;
	return 0;
}
