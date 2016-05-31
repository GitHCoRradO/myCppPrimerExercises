#include <map>
#include <iostream>
#include <string>
using std::multimap;
using std::string;
using std::cout;
using std::endl;
using std::cin;
int main() {
	multimap<string, string> authors{{"Barth,John", "Sot-WeedFactor"}, {"Barth,John", "LostintheFunhouse"}, {"Shakespear", "AsYouLikeIt"}, {"CharlesDikens", "TwinTowers"}, {"Shakespear", "Hamlet"}, {"Shakespear", "Othelo"}, {"MartinRRGeorge", "ASongofIceandFire"}, {"SiMaqian", "ShiJi"}};
	cout << "enter author and the book name:" << endl;
	string name, book;
	while (cin >> name >> book) {
		auto iter = authors.find(name);
		bool deleted = false;
		if (iter == authors.end())
			cout << "no such authors here." << endl;
		else {
			auto iter_end = authors.upper_bound(name);
			for (;iter != iter_end; ++iter) {
				if(iter->second == book) {
					authors.erase(iter);
					deleted = true;
				}
				if (deleted == true)
					break;
			}
			if (deleted == false)
				cout << "no such book of this author." << endl;
			else 
				cout << "successfully deleted." << endl;
		}
	}
	return 0;
}
