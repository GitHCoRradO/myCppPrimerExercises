#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
bool str_contain_cap(const string &s) {
	unsigned cnt = 0;
	for (auto c : s) {
		if(isupper(c)) {
			++cnt;
			break;
		}
	}
	if (cnt == 0)
		return false;
	return true;
}
void str_to_all_lower(string &s) {
	for (auto &c : s)
		c = tolower(c);		//note "c =",revise the tolower() function.
	return;
}
int main() {
	string s;
	cin >> s;
	cout << s << " contain capital?" << str_contain_cap(s) << endl;
	cout << "Hello?" << " contain capital?" << str_contain_cap("Hello?") << endl;
	str_to_all_lower(s);
	cout << s << endl;
	return 0;
}

/*	I think I could also define the first function as:
	bool str_contain_cap(string s);
	this version would copy the value of its argument into its parameter.but I think it works the same as the orginal function.
	I may not define the first function with parameters exactly the same as that of the second,for that will limit the argument types I can pass to its parameter.
	the second function must have a plain reference parameter,for its function is to change its argument.non-reference parameter can not change its argument,and a reference to const
	parameter can not be used to change its corresponding argument.
*/
