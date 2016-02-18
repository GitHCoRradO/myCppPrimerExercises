#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main() {
	Sales_data data1;
	double price = 0.0;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	cout << data1.bookNo << " " << data1.units_sold 
	     << " " << data1.revenue << " " 
	     << price << endl;
	return 0;
}
