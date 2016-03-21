#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string curr_str, pre_str;
	bool no_twice = true;	
	while (cin >> curr_str) {
		if (curr_str == pre_str && isupper(curr_str[0])) {
			cout << curr_str << " appears twice in succession." << endl;
			no_twice = false;
			break;
		}
		pre_str = curr_str;
	}
	if (no_twice)
		cout << "no word with its first letter being upper-case was repeated." << endl;
	return 0;
}
