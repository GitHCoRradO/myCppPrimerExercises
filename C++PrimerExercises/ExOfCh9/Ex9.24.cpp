#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
	vector<int> veci{1, 2, 3, 4, 5}, veci1;
	cout << veci.at(0) << " " << veci[0] << " " << veci.front() << " " << *veci.begin();
	cout << veci1.at(0);
//	cout << veci1[0];
//	cout << *veci1.begin();
//	cout << veci1.front();
	return 0;
}
