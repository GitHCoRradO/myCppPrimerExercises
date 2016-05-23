#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stable_sort;
using std::sort;
using std::unique;
bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	stable_sort(words.begin(), words.end(), isShorter);
}

int main() {
	vector<string> vec;
	string str;
	while (cin >> str)
		vec.push_back(str);
	elimDups(vec);
	for (const auto & s : vec)
		cout << s << " ";
	cout << endl;
	return 0;
}
