#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string str, tempstr;
	while (cin >> tempstr) {
		tempstr += ' ';
		str += tempstr;
	}                         // here is a problem:the final str has a space ' ' at its end.I don't know how to solve it for now.
	cout << endl;
	cout << str << endl;
	return 0;
}
