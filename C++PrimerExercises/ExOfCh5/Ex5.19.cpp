#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main() {
	do {
		string str1, str2;
		if (cin >> str1 >> str2) {
			if (str1.size() < str2.size())
				cout << str1 << " is less than " << str2 << endl;
			else if (str1.size() > str2.size())
				cout << str2 << " is less than " << str1 << endl;
			else
				cout << str1 << " and " << str2 << " are equal" << endl;
		}
	} while (cin);
	return 0;
}
			
