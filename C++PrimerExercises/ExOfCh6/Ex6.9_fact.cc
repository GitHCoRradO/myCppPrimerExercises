#include <iostream>
#include "Chapter6.h"
using std::cin;
using std::cout;
using std::endl;
void fact() {
	int ret = 1, val = 0;
	cout << "pls enter an integer:" << endl;
	cin >> val;
	int i = val;
	while (val > 1)
		ret *= val--;
	cout << i << "! = " << ret << endl;
	return;
}
unsigned abs(int val) {
	return val >= 0 ? val : -val;
}
