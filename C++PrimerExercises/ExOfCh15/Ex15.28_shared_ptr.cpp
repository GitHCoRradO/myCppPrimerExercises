#include "./Ex15.28.h"
#include <iostream>
#include <vector>
#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::vector;
int main() {
	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Bulk_quote>("0123456789", 5.5, 10, 0.25));
	basket.push_back(make_shared<Bulk_quote>("0123456789", 10, 6, 0.25));
	basket.push_back(make_shared<Bulk_quote>("1234567343", 5, 10, 0.25));
	basket.push_back(make_shared<Bulk_quote>("1234567343", 20, 5, 0.25));
	double sum = 0.0;
	for (const auto &ele : basket)
		sum += ele->net_price(9);
	std::cout << sum << std::endl;
	return 0;
}
/*
the discrepancy between the results are expected,for vector<Quote> can only hold Quote object and vector<shared_ptr<Quote>> can hold pointers to
both Quote and Bulk_quote objects,on which discounts might be applied when running net_price(size_t).
*/
