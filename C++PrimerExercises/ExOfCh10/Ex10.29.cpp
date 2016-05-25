#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
using std::cout;
using std::ifstream;
using std::endl;
using std::vector;
using std::string;
using std::istream_iterator;
int main() {
	ifstream ifst("testfile");
	istream_iterator<string> istrm_iter(ifst), eof;
	vector<string> vecs(istrm_iter, eof);
	for (auto s : vecs)
		cout << s << " ";
	cout << endl;
	return 0;
}
