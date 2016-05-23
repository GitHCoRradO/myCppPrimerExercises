#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::partition;
bool mor_th_fiv(const string &s) {
	return s.size() >= 5 ? 1 : 0;
}
int main() {
	vector<string> vec;
	string str;
	while (cin >> str)
		vec.push_back(str);
	auto it = partition(vec.begin(), vec.end(), mor_th_fiv);	//return const_iteraror or iterator? I guess it is iterator.
	for (auto iter = vec.cbegin(); iter != it; ++iter)		//even if it is iterator,comparing const_iterator with iterator still works out fine.
		cout << *iter << " ";
	cout << endl;
	for (const auto &s : vec)
		cout << s << " ";
	cout << endl;
	return 0;
}
