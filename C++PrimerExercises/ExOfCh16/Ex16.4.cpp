#include "./Ex16.4.h"
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> vec{0, 1, 2, 3, 6, 10, -10, -20};
	int i = 0;
	cin >> i;
	auto iter = find_iter(vec.cbegin(), vec.cend(), i);
	if (iter != vec.cend())
		cout << i << " found in vec." << endl;
	if (iter == vec.cend())
		cout << i << " not found in vec." << endl;
	list<string> lstr{"Ron", "Harry", "Shakespear", "Hamlet", "Gick"};
	string s;
	cin >> s;
	auto iter1 = find_iter(lstr.cbegin(), lstr.cend(), s);
	if(iter1 != lstr.cend())
		cout << s << " found in lstr!" << endl;
	if(iter1 == lstr.cend())
		cout << s << " not found in lstr!" << endl;
	return 0;
}
