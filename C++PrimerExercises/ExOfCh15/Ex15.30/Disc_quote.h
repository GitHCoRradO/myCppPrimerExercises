#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "./Quote.h"

class Disc_quote : public Quote {
friend bool operator!=(const Disc_quote&, const Disc_quote&);
public:
	//constructors
	Disc_quote() { }
	Disc_quote(const std::string &book, double p, size_t qty, double disc) :
	Quote(book, p), quantity(qty), discount(disc) { }
	//copy control
	Disc_quote(const Disc_quote &dq) :
	Quote(dq), quantity(dq.quantity), discount(dq.discount) { }
	Disc_quote &operator=(const Disc_quote &);
	Disc_quote(Disc_quote &&dq) noexcept :
	Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) { }
	Disc_quote &operator=(Disc_quote &&) noexcept;
	~Disc_quote() override { }
	//other members
	double net_price(size_t) const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

inline bool operator!=(const Disc_quote &lhs, const Disc_quote &rhs) {
	return Quote(lhs) != Quote(rhs) && lhs.quantity != rhs.quantity &&
	lhs.discount != rhs.discount;
}

inline Disc_quote &Disc_quote::operator=(const Disc_quote &rhs) {
	Quote::operator=(rhs);
	quantity = rhs.quantity;
	discount = rhs.discount;
	return *this;
}
inline Disc_quote &Disc_quote::operator=(Disc_quote &&rhs) noexcept {
	if (*this != rhs) {
		Quote::operator=(std::move(rhs));
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	return *this;
}

#endif
