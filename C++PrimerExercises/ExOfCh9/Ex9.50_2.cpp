#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
	vector<string> vecs{".15", ".202", "3.1415", "-4.87", "5.193", "-5.374", "-10.10205", "17.18e2"};
	double sum = 0;
	for (auto s : vecs) {
		cout << "current number is " << s << endl;
		sum += stod(s);
	}
	cout << "sum is:" << endl;
	cout << sum << endl;//output is 1706.34 instead of 1706.34045.why?
	return 0;
}
