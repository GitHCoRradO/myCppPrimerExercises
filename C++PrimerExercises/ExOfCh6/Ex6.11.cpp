#include <iostream>
using std::cout;
using std::endl;
void reset(int &i) {
	i = 0;
	return;
}
int main() {
	int i = 42;
	reset(i);
	cout << i << endl;
	return 0;
}
