#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::unordered_set;
using std::string;
int main() {
	unordered_map<string, size_t> word_count;
	unordered_set<string> exclude = {"the", "but", "and", "or", "an", "a"}; 
	string word;
	while (cin >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
	return 0;
}
