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
	Sales_data total, trans;
	double price = 0.0;
	while (cin >> trans.bookNo >> trans.units_sold >> price) {
	total.units_sold += trans.units_sold;
	total.revenue += trans.units_sold * price;
	total.bookNo = trans.bookNo;
	}
	cout << endl << total.bookNo << " " << total.units_sold << " "
	     << total.revenue << " " << total.revenue/total.units_sold << endl;
	return 0;
}
