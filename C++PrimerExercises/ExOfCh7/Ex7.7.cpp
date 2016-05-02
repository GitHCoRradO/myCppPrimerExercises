#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
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
istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);
istream &read(istream &is,Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue
	   << " "	  << item.avg_price();
	return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
int main() {
	Sales_data total;
	if(read(cin,total)) {
		Sales_data trans;
		while(read(cin,trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
			cout << endl;
			print(cout, total) << endl;
			total = trans;		//?
			}
		}
	print(cout,total) << endl;
	}
	else {
	cerr << "No data?!" << endl;
	return -1;
	}
	return 0;
}
