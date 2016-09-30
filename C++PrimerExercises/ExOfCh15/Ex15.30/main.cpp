#include <iostream>
#include <string>
#include <memory>

#include "./Quote.h"
#include "./Disc_quote.h"
#include "./Bulk_quote.h"
#include "./Basket.h"

int main() {
	Basket basket;
	for (unsigned i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("C++ Primer", 100, 8, 0.2));
	for (unsigned i = 0; i != 10; ++i)
		basket.add_item(Quote("Oxford Disctionary", 85.5));
	for (unsigned i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("From Mathematics to Programming", 45.8, 10, 0.1));
	basket.total_receipt(std::cout);
	return 0;
}
