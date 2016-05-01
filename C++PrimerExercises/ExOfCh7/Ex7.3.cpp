#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
struct Sales_data {
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data &Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
double Sales_data::avg_price() const {
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}
int main() {
	Sales_data total;
	double price = 0.0;
	if (cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
			cout << '\n' << total.isbn() << " " << total.units_sold << " "
			     << total.revenue << " " << total.avg_price() << endl;
			total.bookNo = trans.bookNo;
			total.units_sold = trans.units_sold;
			total.revenue = trans.revenue;
			}
		}
	cout << '\n' << total.isbn() << " " << total.units_sold << " " << total.revenue
	     << " " << total.avg_price() << endl;
	}
	else {
	cerr << "No data?!" << endl;
	return -1;
	}
	return 0;
}
