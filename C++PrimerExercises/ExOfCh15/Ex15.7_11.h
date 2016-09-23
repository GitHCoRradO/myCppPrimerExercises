#ifndef EX_15_7_11_H
#define EX_15_7_11_H

#include <iostream>
using std::ostream;
#include <string>
using std::string;

class Quote {
public:
	Quote() = default;
	Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual void debug() const;
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};
void Quote::debug() const{
	std::cout << bookNo << " " << price << std::endl;
}
class Bulk_Quote : public Quote {
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string &book, double p, size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc) { }
	double net_price(size_t) const override;
	void debug() const override;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};
double Bulk_Quote::net_price(size_t cnt) const {
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
void Bulk_Quote::debug() const {
//	std::cout << isbn() << " " << price << " " << min_qty << " " << discount << std::endl;
	Quote::debug();
	std::cout << min_qty << " " << discount << std::endl;
}
class limited_disc_Quote : public Quote {
public:
	limited_disc_Quote() = default;
	limited_disc_Quote(const string &book, double p, size_t qty, double disc) :
	Quote(book, p), lim_qty(qty), discount(disc) { }
	double net_price(size_t) const override;
	void debug() const override;
private:
	size_t lim_qty = 0;
	double discount = 0.0;
};
double limited_disc_Quote::net_price(size_t cnt) const {
	if (cnt <= lim_qty)
		return cnt * (1 - discount) * price;
	else
		return lim_qty * (1 - discount) * price + (cnt - lim_qty) * price;
}
void limited_disc_Quote::debug() const {
//	std::cout << isbn() << " " << price << " " << lim_qty << " " << discount << std::endl;
	Quote::debug();
	std::cout << lim_qty << " " << discount << std::endl;
}
double print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
#endif
