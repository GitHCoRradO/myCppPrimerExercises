#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	if (str1 == str2) {
		cout << str1 << " and " << str2 << " are equal." << endl;
	}
	else if (str1 > str2) {
		cout << str1 << " is larger." << endl;
	}
	else {
	cout << str2 << " is larger." << endl;
	}
	return 0;
}
