/* I am not very familiar with how strcpy() and strcat() work.*/
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::strcat;
using std::strcpy;
using std::strlen;
const char arr1[] = "Stack", arr2[] = "Overflow.";	//originally,I defined arr1 and arr2 inside main(),the compiler tells me that strlen(arr1) is not a constexpr.why?
int main() {						//so size_arr3 is not a const expression.arr1 and arr2 defined outside main() works just fine.why?
	constexpr size_t size_arr3 = strlen(arr1) + strlen(arr2) + 1;
	char arr3[size_arr3];
	strcpy(arr3,arr1);
	strcat(arr3,arr2);
	cout << arr3 << endl;
	return 0;
}
