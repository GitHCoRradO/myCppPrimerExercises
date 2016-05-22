#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::count;
using std::list;
using std::string;
int main() {
	list<string> str_lst;
	string str;
	while (cin >> str)
		str_lst.push_back(str);
	string tgt_str("an");
	unsigned cnt = count(str_lst.cbegin(), str_lst.cend(), tgt_str);
	cout << tgt_str << " apprears " << cnt << " times in str_lst." <<endl;
	return 0;
}
