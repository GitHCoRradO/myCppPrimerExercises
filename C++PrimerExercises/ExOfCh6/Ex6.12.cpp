#include <iostream>
using std::cout;
using std::endl;
void swap_ref(int &v1, int &v2) {
	int i = 0;
	i = v1;
	v1 = v2;
	v2 = i;
	return;
}
int main() {
	int i = 2, j = 10;
	swap_ref(i, j);
	cout << i << " " << j << endl;
	return 0;
}
//the reference version could be a little bit easier to use than the pointer version,for when we call the swap function using reference,we do not need to use the & operater
//to take the address of the ints.
