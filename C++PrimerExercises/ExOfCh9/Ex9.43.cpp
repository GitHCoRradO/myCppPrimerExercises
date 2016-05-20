#include <iostream>
#include <string>
#include "./Ex9.43.h"
using std::cout;
using std::endl;
using std::string;

int main() {
	string mainstr("Go thru the door~"), newVal("through");\
	replace_old_to_new(mainstr, "thru", newVal);
	cout << mainstr << endl;
	return 0;
}
