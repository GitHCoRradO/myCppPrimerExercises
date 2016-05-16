#include <iostream>
#include <list>
#include <deque>
using std::list;
using std::deque;
using std::cout;
using std::endl;

int main() {
	list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	deque<int> deque_even, deque_odd;
	for(auto i : li) {
		if(i % 2 == 0)
			deque_even.push_back(i);
		else
			deque_odd.push_back(i);
	}
	for(auto i : deque_even)
		cout << i << " ";
	cout << endl;
	for(auto i : deque_odd)
		cout << i << " ";
	cout << endl;
	return 0;
}
