#include <iostream>
using std::cout;
using std::endl;
int larger_int(int v1, const int *v2) {
	return v1 > *v2 ? v1 : *v2;
}
int main() {
	int i = 10, *p = &i;
	cout << larger_int(0, p);
	return 0;
}
