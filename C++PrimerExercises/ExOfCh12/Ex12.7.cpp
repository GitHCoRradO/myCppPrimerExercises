#include <iostream>
#include <memory>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> create_vec() {
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> add_ele() {
	auto ptr = create_vec();
	int i = 0;
	while (cin >> i)
		ptr->push_back(i);
	return ptr;
}

void print_ele(shared_ptr<vector<int>> ptr) {		//void print_ele() {
	for(int i : *ptr)				//	for(int i : *add_ele())			the final output always replaces the first element with 0.  why?
		cout << i << " ";			// /*..
	cout << endl;					// ..
}							// ..
int main() {						// ..*/
	print_ele(add_ele());				//print_ele();
	return 0;
}
