#include "../ExOfCh1/Sales_item.h"
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using std::accumulate;
//using std::find;
using std::find_if_not;
using std::sort;
//using std::unique_copy;
using std::vector;
using std::istream_iterator;
using std::cin;
using std::cout;
using std::endl;
//using std::back_inserter;
/*
bool compIsbn(const Sales_item &item1, const Sales_item &item2) {
	return item1.isbn() < item2.isbn();
}

int main() {
	istream_iterator<Sales_item> is_iter(cin), eof;
	vector<Sales_item> vec(is_iter, eof), uni_vec;
	sort(vec.begin(), vec.end(), compIsbn);
	unique_copy(vec.begin(), vec.end(), back_inserter(uni_vec));			//this usage of unique_copy is stupid.I do not know if it works as I think.
	auto uni_vec_iter = uni_vec.cbegin();
	while (uni_vec_iter != (uni_vec.cend() - 1)) {
		auto vec_curr = find(vec.cbegin(), vec.cend(), *uni_vec_iter);
		auto vec_next = find(vec.cbegin(), vec.cend(), *(uni_vec_iter + 1));
		Sales_item init(uni_vec_iter->isbn());
		auto  sum = accumulate(vec_curr, vec_next, init);
		cout << sum << endl;
	}
	auto vec_final = find(vec.cbegin(), vec.cend(), *uni_vec_iter);
	Sales_item init_(uni_vec_iter->isbn());
	auto sum_ = accumulate(vec_final, vec.cend(), init_);
	cout << sum_ << endl;
	return 0;
}
*/	//all that is in the comment part above belongs to my first version of code

int main() {
	istream_iterator<Sales_item> is_iter(cin), eof;
	vector<Sales_item> vec(is_iter,eof);
	sort(vec.begin(), vec.end(), compareIsbn);	//there is a function named compareIsbn defined in Sales_item.h
							//and it is different from that one in Exercise 10.12
	for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
		end = find_if_not(beg, vec.cend(), [&](const Sales_item &item) { return item.isbn() == beg->isbn(); });
		Sales_item init(beg->isbn());
		cout << accumulate(beg, end, init) << endl;
	}
	return 0;
}
