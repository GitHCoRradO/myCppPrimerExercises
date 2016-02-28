#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() {
	vector<unsigned> scores(11,0);
	unsigned grade = 0;
	while (cin >> grade) {
		if (grade <= 100) {
		auto beg = scores.begin();
		auto n = grade/10;
		*(beg + n) += 1;
		}
	}
	auto beg = scores.begin();
	for (; beg != scores.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
	return 0;
}
