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
	//constructors:
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) { }
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { }
	Sales_data(istream &);
	//other members:
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//member function definitions:
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
//nonmember function declarations and definitions:
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
//constructor definitions:
Sales_data::Sales_data(istream &is) {
	read(is, *this);
}
int main() {
	Sales_data data1, data2("1234567890"), data3("2345678901", 10, 2), data4(cin);
	print(cout,data1) << endl;
	print(cout,data2) << endl;
	print(cout,data3) << endl;
	print(cout,data4) << endl;
	return 0;
}
