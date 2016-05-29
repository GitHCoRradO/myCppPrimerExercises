#include <iostream>
#include <string>
#include <vector>
#include <utility>
using std::cin;
using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;
int main() {
	vector<pair<string, int>> vec;
	string str;
	int i;
	while (cin >> str >> i)
		vec.push_back(make_pair(str, i));
	for (const auto & v : vec)
		cout << v.first << " " << v.second << endl;
	return 0;
}
