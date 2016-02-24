#include <iostream>
using std::cout;
using std::endl;
int main() {
	int ia[10] = {0,1,2,3,4,5,6,7,8,9};
	int ib[10];		//ib[10] is defined inside main function.its elements are undefined.
	for (auto i : ia)	//test by printing the undefined values,the results are random numbers,large or small.
		ib[i] = i;	//assigning to ib[i] changes the originally undefined value.
	for (auto i : ib)
		cout << i << " ";
	cout << endl;
	return 0;
}
