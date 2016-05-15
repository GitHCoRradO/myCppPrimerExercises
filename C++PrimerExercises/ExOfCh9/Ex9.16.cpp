#include <iostream>
#include <vector>
#include <list>
using std::list;
using std::vector;
using std::cout;
using std::endl;
int main() {
	list<int> l1{1, 2, 3, 4, 5};
	vector<int> v2{1, 2, 3, 4, 5};
	cout << (l1 == v2) << endl;	//compilation error.
/*	added:
	what does this do?
	vector<int>(l1.begin(),l1.end())

	is this constructor implicit convertion?  check out Page 295. 
	no. because converting constructors take only 1 single argument.
	
	this is not old style cast: type (expr); or (type) expr;

	(vector<int>(l1.begin(),l1.end()) == v2) might yield bool type?


*/
	return 0;
}
