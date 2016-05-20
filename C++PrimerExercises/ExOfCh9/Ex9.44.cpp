#include <iostream>
#include <string>
#include "./Ex9.44.h"
using std::cout;
using std::endl;
using std::string;

int main() {
	string mainstr("even tho we face the difficulties of today and tommorrow"), newVal("though");
	replace_old_to_new(mainstr, "tho", newVal);
	cout << mainstr << endl;
	return 0;
}
