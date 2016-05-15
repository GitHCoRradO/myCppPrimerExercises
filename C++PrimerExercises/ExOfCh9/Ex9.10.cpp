#include <vector>
using std::vector;

int main() {
	vector<int> v1;
	const vector<int> v2;
//	auto it1 = v1.begin(), it2 = v2.begin();
/*	gcc version 5.3.1
error: inconsistent deduction for ‘auto’: ‘__gnu_cxx::__normal_iterator<int*, std::vector<int> >’ and then ‘__gnu_cxx::__normal_iterator<const int*, std::vector<int> >’
  auto it1 = v1.begin(), it2 = v2.begin();
*/
	auto it1 = v1.begin();		//vector<int>::iterator
	auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();	//vector<int>::const_iterator
	return 0;
}
