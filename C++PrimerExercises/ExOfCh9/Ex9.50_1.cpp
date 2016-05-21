#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
	vector<string> vecs{"1", "2", "3", "4", "5", "-5", "-10", "17"};
	int sum = 0;
	for (auto s : vecs) {
		cout << "current number is " << s << endl;
		sum += stoi(s);
	}
	cout << "sum is:" << endl;
	cout << sum << endl;
	return 0;
}
