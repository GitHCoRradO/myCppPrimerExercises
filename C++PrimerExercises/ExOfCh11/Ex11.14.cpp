#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
using std::vector;
using std::map;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
int main() {
	map<string, vector<pair<string, string>>> families;
	string first_name, last_name, birthday;
	cout << "enter a child's full name and birthday:" << endl;
	while (cin >> first_name >> last_name >> birthday)
		families[last_name].push_back({first_name, birthday});
	for (const auto &child : families)
		for (const auto &fn : child.second)
			cout << fn.first << " " << child.first << " " << fn.second << endl;
	return 0;
}
