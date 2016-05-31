#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::sort;
using std::multimap;
using std::string;
using std::vector;
using std::cout;
using std::endl;
int main() {
        multimap<string, string> authors{{"Barth,John", "Sot-WeedFactor"}, {"Barth,John", "LostintheFunhouse"}, {"Shakespear", "AsYouLikeIt"}, {"CharlesDikens", "TwinTowers"}, {"Shakespear", "Hamlet"}, {"Shakespear", "Othelo"}, {"MartinRRGeorge", "ASongofIceandFire"}, {"SiMaqian", "ShiJi"}};
	for (const auto &author : authors)
		cout << author.first << "\t" << author.second << endl;
	cout << "---------------------------------------------------" << endl;
	for (auto aut = authors.cbegin(); aut != authors.cend(); ) {
		cout << "Works of " << aut->first << ":";
		auto iter = authors.equal_range(aut->first);
		vector<string> vec;
		while (iter.first != iter.second) {
				vec.push_back(iter.first->second);
				++aut;
				++iter.first;
		}
		sort(vec.begin(), vec.end());
		for (auto &b : vec)
			cout << "\t" << b;
		cout << endl;
	}
	return 0;
}
