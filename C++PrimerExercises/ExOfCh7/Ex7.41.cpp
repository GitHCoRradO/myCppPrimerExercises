#include <iostream>
#include <string>
#include "./Ex7.41.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	Sales_data item1;
	cout << "item1 created!" << endl;
	string str1 = "1234567890";
	Sales_data item2(str1);
	cout << "item2(str1) created!" << endl;
	Sales_data item3(str1, 0, 0);
	cout << "item3(str1, 0, 0) created!" << endl;
	Sales_data item4(cin);
	cout << "item4(cin) created!" << endl;
	return 0;
}

