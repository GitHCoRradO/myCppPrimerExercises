#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
int main() {
	map<string, vector<string>> families;
	families["Churchill"].push_back("Winsten");
	families["Churchill"].push_back("Will");
	families["Roosewilt"].push_back("George");
	families["Starlin"].push_back("Eric");
	for (const auto &name : families)
		for (const auto &first_name : name.second)
			cout << first_name << " " << name.first << endl;
	return 0;
}
