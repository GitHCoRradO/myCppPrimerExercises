#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int i1 = 0, i2 = 0;
	cin >> i1 >> i2;
	cout << static_cast<double>(i1)/i2 << endl;
	return 0;
}
