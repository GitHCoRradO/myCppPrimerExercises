#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main() {
	vector<int> vec_int_1{0, 1, 1, 2}, vec_int_2{0, 1, 1, 2, 3, 5, 8};
	decltype(vec_int_1.size()) size = vec_int_1.size() < vec_int_2.size() ? vec_int_1.size() : vec_int_2.size();
	for (decltype(vec_int_1.size()) i = 0; i != size; ++i) {
		if (vec_int_1[i] != vec_int_2[i]) {
			cout << "false" << endl;
			break;
		}
		if(i == size - 1)
			cout << "true" << endl;
	}
	return 0 ;
}
			
