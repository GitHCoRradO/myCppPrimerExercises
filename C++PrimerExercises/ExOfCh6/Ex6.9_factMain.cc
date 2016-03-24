#include <iostream>
#include "Chapter6.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
	int i = 0;
	cout << "Input an integer:" << endl;
	cin >> i;
	cout << "Its abs is " << abs(i) << endl;
	fact();
	return 0;
}
