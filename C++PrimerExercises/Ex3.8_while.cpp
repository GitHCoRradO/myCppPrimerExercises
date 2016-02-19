#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string str;
	cin >> str;
	decltype(str.size()) index = 0;
	while (index < str.size()) {
		str[index] = 'X';
		++index;
	}
	cout << str << endl;
	return 0;
}	 
