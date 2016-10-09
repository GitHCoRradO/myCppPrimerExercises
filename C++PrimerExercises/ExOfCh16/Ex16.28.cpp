#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "./Ex16.28_my_shared_ptr.h"
#include "./Ex16.28_my_unique_ptr.h"

int main() {
	My_shared_ptr<int> msp1(new int(10)), msp2(msp1);
	cout << *msp2 << endl;
	cout << msp2.use_count() << endl;

	My_unique_ptr<string> mup1(new string("Shakespear"));
	cout << *mup1 << endl;
	cout << mup1->size() << endl;
	return 0;
}
