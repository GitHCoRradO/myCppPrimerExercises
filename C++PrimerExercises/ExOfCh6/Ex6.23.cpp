#include <iostream>
#include <iterator>
using std::begin;
using std::end;
using std::cout;
using std::endl;
void print_1(const int *i) {
	if (i)
		cout << *i << endl;
}
void print_2(const int *beg, const int *end) {
	while (beg != end)
		cout << *beg++ << endl;
}
void print_3(const int ia[], std::size_t size) {
	for (std::size_t i = 0; i != size; ++i)
		cout << ia[i] << endl;
}
void print_4(int (&arr)[2]) {
	for (auto elem : arr)
		cout << elem << endl;
}
int main() {
	int i = 0, j[2] = {0, 1};
	print_1(&i);
	print_2(begin(j), end(j));
	print_3(j, 2);
	print_4(j);
	return 0;
}
