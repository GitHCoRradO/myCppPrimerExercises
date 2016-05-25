#include <iterator>
#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	ofstream ofst1(argv[2]), ofst2(argv[3]);
	istream_iterator<int> is_iter(ifst), eof;
	ostream_iterator<int> os_iter1(ofst1, " "), os_iter2(ofst2, "\n");
	while (is_iter != eof) {
		if (*is_iter % 2)		//better not use "*is_iter % 2 == 1" as the condition.even number,either position or negative, modulus 2 equals 0. yet negative odd number modulus 2 equals -1.
			os_iter1 = *is_iter++;
		else
			os_iter2 = *is_iter++;
	}
	return 0;
}
