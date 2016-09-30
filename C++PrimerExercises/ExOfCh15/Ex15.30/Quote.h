#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
friend bool operator!=(const Quote&, const Quote&);
public:
	//constructors
	Quote() { }
	Quote(const std::string &book, double p) : bookNo(book), price(p) { }
	//copy control
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) { }
	Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { }
	Quote &operator=(const Quote &);
	Quote &operator=(Quote &&rhs) noexcept {
		if(*this != rhs) {
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
			}
	return *this;
	}
	virtual ~Quote() { }
	//other function members
	std::string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return price * n; }
	virtual Quote *clone() const & { return new Quote(*this); }
	virtual Quote *clone() && { return new Quote(std::move(*this)); }
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

inline Quote &Quote::operator=(const Quote &rhs) {
	bookNo = rhs.bookNo;
	price = rhs.price;
	return *this;
}

inline
bool operator!=(const Quote &lhs, const Quote &rhs) {
	return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}


double print_total(std::ostream &, const Quote &, size_t);
#endif
