#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void fact() {
	int ret = 1, val = 0;
	cout << "Pls enter an integer:" << endl;
	cin >> val;
	int i = val;
	while (val > 1)
		ret *= val--;
	cout << i << "! = " << ret << endl;
	return;
}
int main() {
	fact();
	return 0;
}
