#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int add_func(int i, int j) {
	return i + j;
}
int subtract_func(int i, int j) {
	return i - j;
}
int multiply_func(int i, int j) {
	return i * j;
}
int divide_func(int i, int j) {
	if(j != 0)
		return i / j;
	else
	return -1;
}
typedef int (*funcP)(int, int);		//typedef int funcP(int, int);		will result in compile error.
int main() {
	vector<funcP> funcP_vec = {add_func, subtract_func, multiply_func, divide_func};
	int i1 = 4, i2 = 2;
	cout << funcP_vec[0](i1, i2) << endl;
	cout << funcP_vec[1](i1, i2) << endl;
	cout << funcP_vec[2](i1, i2) << endl;
	cout << funcP_vec[3](i1, i2) << endl;
	return 0;
}
