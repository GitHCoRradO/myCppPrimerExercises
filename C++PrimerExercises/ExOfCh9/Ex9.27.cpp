#include <iostream>
#include <forward_list>
using std::forward_list;
using std::cout;
using std::endl;

int main() {
	forward_list<int> flis{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	auto prev = flis.before_begin();
	auto curr = flis.begin();
	while (curr != flis.end()) {
		if(*curr % 2)
			curr = flis.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}
	}
	for (auto i : flis)
		cout << i << endl;
	return 0;
}
