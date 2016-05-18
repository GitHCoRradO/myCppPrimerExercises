//as soon as iter denotes an odd number,the while loop will always add a duplicate before the current element,iter wi-
//ll always denote the ood number it denotes at the moment.
#include <iostream>
#include <vector>
using std::endl;
using std::cout;
using std::vector;

int main() {
	vector<int> vi{1, 2, 3, 4};
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2)
			iter = vi.insert(iter, *iter);
		++iter;
	}
	for (auto i : vi)
		cout << i << endl;
	return 0;
}
