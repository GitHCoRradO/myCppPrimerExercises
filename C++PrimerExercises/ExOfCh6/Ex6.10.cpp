#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap_int(int *v1, int *v2) {
	int temp = 0;
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
	return;
}
int main() {
	int v1 = 2, v2 = 10;
	swap_int(&v1, &v2);
	cout << v1 << " " << v2 << endl;
	return 0;
}
