#include "./Bulk_quote.h"
double Bulk_quote::net_price(size_t n) const {
	if (n >= quantity)
		return n * (1 - discount) * price;
	else
		return n * price;
}
