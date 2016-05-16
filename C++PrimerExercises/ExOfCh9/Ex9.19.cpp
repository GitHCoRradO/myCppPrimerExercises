#include <iostream>
#include <string>
#include <list>			
using std::string;
using std::list;		
using std::cin;
using std::cout;
using std::endl;

int main() {
	list<string> list_str;
	string word;
	while (cin >> word)
		list_str.push_back(word);
	for(auto iter = list_str.cbegin(); iter != list_str.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}
