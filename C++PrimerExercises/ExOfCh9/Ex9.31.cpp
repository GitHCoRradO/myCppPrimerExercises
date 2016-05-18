//the program will not work for list or forward_list for that these 2 containers does not support iterator arithmetic operations such as iter += 2;
#include <iostream>
#include <list>
#include <forward_list>
using std::cout;
using std::endl;
using std::list;
using std::forward_list;

int main() {
	list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	forward_list<int> fwdli{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto li_iter = li.begin();
	while (li_iter != li.end()) {
		if (*li_iter % 2 == 1) {
			li_iter = li.insert(li_iter, *li_iter);
			++li_iter;
			++li_iter;
		}
		else
			li_iter = li.erase(li_iter);
	}
	auto fwdli_iter_prev = fwdli.before_begin();
	auto fwdli_iter_curr = fwdli.begin();
	while (fwdli_iter_curr != fwdli.end()) {
		if (*fwdli_iter_curr % 2 == 1) {
			fwdli_iter_prev = fwdli.insert_after(fwdli_iter_prev, *fwdli_iter_curr);
			++fwdli_iter_prev;
			++fwdli_iter_curr;
		}
		else
			fwdli_iter_curr = fwdli.erase_after(fwdli_iter_prev);
	}
	for (auto i : li)
		cout << i << " ";
	cout << endl;
	for (auto i : fwdli)
		cout << i << " ";
	cout << endl;
	return 0;
}
		
