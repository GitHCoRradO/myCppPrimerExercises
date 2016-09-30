#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "./Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
	//constructors
	Bulk_quote() { }
	using Disc_quote::Disc_quote;
	//copy control
	Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) { }
	Bulk_quote &operator=(const Bulk_quote &);
	Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq)) { }
	Bulk_quote &operator=(Bulk_quote &&) noexcept;
	virtual ~Bulk_quote() override { }
	//other member functions
	double net_price(size_t) const override;
	Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
	Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};
inline Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs) {
	Disc_quote::operator=(rhs);
	return *this;
}
inline Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs) noexcept {
	Disc_quote::operator=(std::move(rhs));
	return *this;
}
#endif
