#include <iostream>
using std::cin;
using std::cout;
using std::endl;
unsigned absolute(int i) {
	unsigned val = 0;
	if (i >= 0)
		val = i;
	else
		val = -i;
	return val;
}
int main() {
	int i = 0;
	cin >> i;
	cout << absolute(i) << endl;
	return 0;
}
