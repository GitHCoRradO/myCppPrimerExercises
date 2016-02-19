#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	if (str1.size() == str2.size()) {
		cout << str1 << " and " << str2 << " are of the same length." << endl;
	}
	else if ( str1.size() > str2.size()) {
		cout << str1 << " is longer in length." << endl;
	}
	else {
		cout << str2 << " is longer in length." << endl;
	}
	return 0;
}
