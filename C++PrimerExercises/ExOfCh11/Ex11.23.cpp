#include <iostream>
#include <map>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::multimap;
using std::endl;
int main() {
	multimap<string, string> families;
	string last_name, first_name;
	while (cin >> first_name >> last_name)
		families.insert({last_name, first_name});
	for (const auto &names : families)
		cout << names.second << " " << names.first << endl;
	return 0;
}
