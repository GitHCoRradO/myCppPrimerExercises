#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main() {
	vector<string> v_str;
	string temp_str;
	while (cin >> temp_str) {
		v_str.push_back(temp_str);
	}
	for (auto &str : v_str) {
		for(auto &c : str)
			c = toupper(c);
	}
	decltype(v_str.size()) index = 0;
	for (;index < v_str.size(); ++index) {
		if (index%8 != 0)
			cout << v_str[index] << " ";
		else {
		cout << endl;
		cout << v_str[index] << " ";
		}
	}
	cout << endl;
	return 0;
}	
