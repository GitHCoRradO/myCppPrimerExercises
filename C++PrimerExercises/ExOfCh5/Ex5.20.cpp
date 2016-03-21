#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string curr_str, pre_str;
	bool no_twice = true;	//great idea.
	while (cin >> curr_str) {
		if (curr_str == pre_str) {
			cout << curr_str << " appears twice in succession." << endl;	// I do not know how to test whether cin has hitted the end-of-file.
			no_twice = false;	//great!
			break;
		}
		pre_str = curr_str;
	}
	if (no_twice)
		cout << "no word was repeated." << endl;
	return 0;
}
