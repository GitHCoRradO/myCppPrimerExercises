#ifndef EX_15_26_H
#define EX_15_26_H

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <string>
using std::string;

class Quote {
friend bool operator!=(const Quote &, const Quote &);
public:
	Quote() { cout << "Quote() default constructor." << endl; }
	Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) { cout << "Quote(const Quote&) copy constructor." << endl; }
	Quote &operator=(const Quote &);
	Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), price(rhs.price) { cout << "Quote(Quote&&) move constructor." << endl; }
	Quote &operator=(Quote &&) noexcept;
	Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { cout << "Quote(const string&, double)." << endl; }
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual ~Quote() { cout << "~Quote() destructor." << endl; }
private:
	string bookNo;
protected:
	double price = 0.0;
};
Quote &Quote::operator=(const Quote &rhs) {
	bookNo = rhs.bookNo;
	price = rhs.price;
	cout << "Quote::operator=(const Quote&) copy-assignment operator." << endl;
	return *this;
}
inline bool operator!=(const Quote &lhs, const Quote &rhs) {
	return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}
Quote &Quote::operator=(Quote &&rhs) noexcept {
	if (*this != rhs){
		bookNo = std::move(rhs.bookNo);
		price = rhs.price;
	}		
	cout << "Quote::operator=(Quote &&) move-assignment operator." << endl;
	return *this;
}

class Disc_quote : public Quote {
friend bool operator!=(const Disc_quote&, const Disc_quote&);
public:
	Disc_quote() { cout << "Disc_quote() default constructor." << endl; }
	Disc_quote(const Disc_quote &rhs) : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) { cout << "Disc_quote(const Disc_quote &) copy constructor." << endl; }
	Disc_quote &operator=(const Disc_quote &);
	Disc_quote(Disc_quote &&rhs) noexcept : Quote(std::move(rhs)), quantity(rhs.quantity), discount(rhs.discount) { cout << "Disc_quote(Disc_quote &&) move constructor." << endl; }
	Disc_quote &operator=(Disc_quote &&) noexcept;
	Disc_quote(const string &book, double price, size_t qty, double disc) :
	Quote(book, price), quantity(qty), discount(disc)
	{ cout << "Disc_quote(const string&, double, size_t, double)." << endl; }
	double net_price(size_t) const = 0;
	~Disc_quote() override { cout << "~Disc_quote() destructor." << endl; }
protected:
	size_t quantity = 0;
	double discount = 0.0;
};
inline bool operator!=(const Disc_quote &lhs, const Disc_quote &rhs) {
	return Quote(lhs) != Quote(rhs) && lhs.quantity != rhs.quantity && lhs.discount != rhs.discount;
}
Disc_quote &Disc_quote::operator=(const Disc_quote &rhs) {
	Quote::operator=(rhs);
	quantity = rhs.quantity;
	discount = rhs.discount;
	cout << "Disc_quote::operator=(const Disc_quote &) copy-assignment operator." << endl;
	return *this;
}
Disc_quote &Disc_quote::operator=(Disc_quote &&rhs) noexcept {
	if (*this != rhs) {
		Quote::operator=(std::move(rhs));
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	cout << "Disc_quote::operator=(Disc_quote&&) move-assignment operator." << endl;
	return *this;
}

class Bulk_quote : public Disc_quote {
public:
	using Disc_quote::Disc_quote;
	Bulk_quote() { cout << "Bulk_quote() default constructor." << endl; }
	Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) { cout << "Bulk_quote(const Bulk_quote&) copy constructor." << endl; }
	Bulk_quote &operator=(const Bulk_quote &rhs);
	Bulk_quote(Bulk_quote &&rhs) noexcept : Disc_quote(std::move(rhs)) { cout << "Bulk_quote(Bulk_quote&&) move constructor." << endl; }
	Bulk_quote &operator=(Bulk_quote &&) noexcept;
	double net_price(size_t) const override;
	~Bulk_quote() override { cout << "~Bulk_quote() destructor." << endl; }
};
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs) {
	Disc_quote::operator=(rhs);
	cout << "Bulk_quote::operator=(const Bulk_quote &) copy-assignment operator." << endl;
	return *this;
}
Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs) noexcept {
	Disc_quote::operator=(std::move(rhs));
	cout << "Bulk_quote::operator=(Bulk_quote &&) move-assignment operator." << endl;
	return *this;
}
double Bulk_quote::net_price(size_t n) const {
	if (n >= quantity)
		return n * (1 - discount) * price;
	else
		return n * price;
}
#endif
