#include <iostream>
#include <stdexcept>
using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
int main() {
	int i1 = 0, i2 = 0;
	while (cin >> i1 >> i2) {
		try {
		if (i2 == 0)
		throw runtime_error("i2 must be nonzero!");
		cout << static_cast<double>(i1)/i2 << endl;
		} catch (runtime_error err) {
			cout << err.what() << "\nPls enter new numbers:\n" ;
			}
	}
	return 0;
}
