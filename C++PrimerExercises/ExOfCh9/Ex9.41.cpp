#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;

int main() {
	vector<char> vecchar{'W', 'o', 'r', 'l', 'd'};
	string str(vecchar.begin(), vecchar.end());
	cout << str;
	return 0;
}
