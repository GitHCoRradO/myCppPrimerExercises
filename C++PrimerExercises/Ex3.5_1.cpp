#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string str, tempstr;
	while (cin >> tempstr) {
		str += tempstr;
	}
	cout << endl;
	cout << str << endl;
	return 0;
}
