#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::unique;
using std::vector;
using std::string;

int main() {
	vector<string> words;
	string word;
	while (cin >> word)
		words.push_back(word);
	cout << "original words:" << endl;
	for (auto &s : words)
		cout << s << " ";
	cout << endl;
	sort(words.begin(), words.end());
	cout << "sorted words:" << endl;
	for(auto &s : words)
		cout << s << " ";
	cout << endl;
	auto end_unique = unique(words.begin(), words.end());
	cout << "words after the call to unique:" << endl;
	for (auto &s : words)
		cout << s << " ";
	cout << endl;
	words.erase(end_unique, words.end());
	cout << "words after the call to erase:" << endl;
	for (auto s : words)
		cout << s << " ";
	cout << endl;
	return 0;
}
