#include "./Ex15.28.h"
#include <iostream>
#include <vector>
using std::vector;
int main() {
	vector<Quote> basket;
	basket.push_back(Bulk_quote("0123456789", 5.5, 10, 0.25));
	basket.push_back(Bulk_quote("0123456789", 10, 6, 0.25));
	basket.push_back(Bulk_quote("1234567343", 5, 10, 0.25));
	basket.push_back(Bulk_quote("1234567343", 20, 5, 0.25));
	double sum = 0.0;
	for (const auto &ele : basket)
		sum += ele.net_price(9);
	std::cout << sum << std::endl;
	return 0;
}

