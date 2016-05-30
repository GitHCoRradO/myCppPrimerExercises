#include <iostream>
#include <string>
#include <map>
#include <set>
using std::string;
using std::map;
using std::set;
using std::cin;
using std::cout;
using std::endl;
int main() {
	map<string, size_t> word_cnt;
	string word;
	while (cin >> word) {
		auto ret = word_cnt.insert({word, 1});
		if(!ret.second)
			++ret.first->second;
	}
	for (const auto &w : word_cnt)
		cout << w.first << " " << w.second << endl;
	return 0;
}
/*
I think the version using subscript operator is easier to write and read.
even though it is a bit hard to understand that when you subscript the map with
a new key,the element is created as soon as the subscripting operation is done,
this version is much easier to understand than having to unwind the ret.first->
second.
*/
