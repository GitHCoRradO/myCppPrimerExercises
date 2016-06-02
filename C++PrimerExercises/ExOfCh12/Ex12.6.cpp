#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> *create_vec() {
	vector<int> *ptr = new vector<int>;
	return ptr;
}

vector<int> *add_ele(vector<int> *ptr) {
	int i = 0;
	while (cin >> i)
		ptr->push_back(i);
	return ptr;
}

void print_ele(vector<int> *ptr) {
	for (int i : *ptr)
		cout << i << " ";
	cout << endl;
	delete ptr;
}

int main() {
	auto ptr = add_ele(create_vec());
	print_ele(ptr);
	return 0;
}
