#include <iostream>
#include <string>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::allocator;

int main() {
	unsigned n = 0;
	cout << "input the number of strings to allocate:" << endl;
	cin >> n;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	string s;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	for (int i = 0; i != (q - p); ++i)
		cout << *(p + i) << endl;
	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);
	return 0;
}
