#include <iostream>
#include <string>
#include <deque>
using std::string;
using std::deque;
using std::cin;
using std::cout;
using std::endl;

int main() {
	deque<string> deque_str;
	string word;
	while (cin >> word)
		deque_str.push_back(word);
	for(auto iter = deque_str.cbegin(); iter != deque_str.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}
