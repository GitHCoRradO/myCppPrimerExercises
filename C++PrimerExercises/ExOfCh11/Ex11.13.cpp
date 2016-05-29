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
	vector<pair<string, int>> vec1, vec2, vec3;
	string str;
	int i;
//	//#1
//	while (cin >> str >> i)
//		vec1.push_back(make_pair(str, i));
//	for (const auto &v : vec1)
//		cout << v.first << " " << v.second << endl;
//	//#2
//	while (cin >> str >> i)
//		vec2.push_back(pair<string, int>(str, i));
//	for (const auto &v : vec2)
//		cout << v.first << " " << v.second << endl;
	//#3
	while (cin >> str >> i)
		vec3.push_back({str, i});
	for (const auto &v : vec3)
		cout << v.first << " " << v.second << endl;
	return 0;
}
