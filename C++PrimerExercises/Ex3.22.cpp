#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main() {
	vector<string> text;
	string line;
	while (getline(cin, line))
		text.push_back(line);
	for (auto it = text.begin(); it !=text.end() && !it->empty(); ++it) {
		for(auto &c : *it)
			c = toupper(c);
	}
	for (auto it = text.begin(); it !=text.end() && !it->empty(); ++it)
		cout << *it << endl;
	return 0;
}
