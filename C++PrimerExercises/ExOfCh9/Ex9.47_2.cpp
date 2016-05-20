#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {
	string s("ab2c3d7R4E6"), numbers("0123456789");
	string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(numbers,pos)) != string::npos) {
		cout << "found letter at index: " << pos
		     << " element is " << s[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = s.find_first_not_of(alphabet,pos)) != string::npos) {
		cout << "found number at index: " << pos
		     << " element is " << s[pos] << endl;
		++pos;
	}
	return 0;
}
