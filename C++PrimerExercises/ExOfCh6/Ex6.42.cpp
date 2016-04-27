#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
string make_plural(size_t ctr, const string &word, const string &ending = "s") {	//using const sring &ending = 's'  would result in error:cannot convert char to const string&
	return (ctr > 1) ? word + ending : word;
}
int main() {
	cout << make_plural(1, "success") << " " << make_plural(1,"failure");
	cout << endl;
	cout << make_plural(2, "success", "es") << " " << make_plural(2,"failure");
	cout << endl;
	return 0;
}
