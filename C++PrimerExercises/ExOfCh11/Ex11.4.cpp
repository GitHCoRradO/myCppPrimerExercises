#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using std::remove_if;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;
int main() {
	map<string, size_t> word_count;
	set<string> exclude = {"the", "but", "and", "or", "an", "a"}; 
	string s;
//assuming that each word is entered with a space separating each other. punctuations can be adjacent to the words. this line of word is entered following this assumption.
	while (cin >> s) {
//		if ((s.find('.') != string::npos) || (s.find(',') != string::npos))
//			s.erase(s.size() - 1, 1);
		for (auto &c : s)
			c = tolower(c);
		s.erase(remove_if(s.begin(), s.end(), ispunct), s.end());
		if (exclude.find(s) == exclude.end())
			++word_count[s];
	}
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
	return 0;
}
