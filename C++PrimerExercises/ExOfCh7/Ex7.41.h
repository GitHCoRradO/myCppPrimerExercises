#ifndef EX7_41_H
#define EX7_41_H

#include <iostream>
#include <string>
using std::string;

class Sales_data {
friend Sales_data add(const Sales_data &, const Sales_data &);
friend std::istream &read(std::istream &, Sales_data &);
friend std::ostream &print(std::ostream &, const Sales_data &);

public:
	//constructors
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { 
		std::cout << "Work of constructor Sales_data(const string &, unsigned, unsigned) done." << std::endl; }
	Sales_data() : Sales_data("", 0, 0) { 
		std::cout << "Work of constructor Sales_data() done." << std::endl; }
	Sales_data(const string &s) : Sales_data(s, 0, 0) {
		std::cout << "Work of constructor Sales_data(const string &) done." << std::endl; }
	Sales_data(std::istream &is) : Sales_data() { read(is, *this);
		std::cout << "Work of constructor Sales_data(std::istream &) done." << std::endl; }
	//member functions
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);

private:
	//member function and data members
	double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//member function defition outside the class body
Sales_data &Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline double Sales_data::avg_price() const {
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

//friend functions:
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

#endif
