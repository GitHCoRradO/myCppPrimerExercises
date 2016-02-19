#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string str;
	cin >> str;
	for (auto c : str)
		if (!ispunct(c)) cout << c;
	cout << endl;
	return 0;
}
