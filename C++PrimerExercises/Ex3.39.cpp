#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
using std::strcmp;
int main() {
	string str1("Hello?"), str2("Hello!");
	if (str1 == str2)
		cout << "str1 and str2 are equal." << endl;
	else if (str1 > str2)
		cout << "str1 is larger than str2." << endl;
	else
		cout << "str2 is larger than str1." << endl;
	const char ch_arr1[] = "Ohyeah~", ch_arr2[] = "Ohyeah~";
	if (strcmp(ch_arr1, ch_arr2) == 0)
		cout << "ch_arr1 and ch_arr2 are equal." << endl;
	else if (strcmp(ch_arr1,ch_arr2) > 0)
		cout << "ch_arr1 is larger than ch_arr2." << endl;
	else
		cout << "ch_arr2 is larger than ch_arr1." << endl;
	return 0;
}
		
	
		
