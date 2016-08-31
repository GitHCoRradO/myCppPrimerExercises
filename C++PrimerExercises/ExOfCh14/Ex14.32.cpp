#include "./Ex14.32.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	StrBlob strb{"apple", "bad", "cat", "doggy", "elf", "fly", "golf", "hat"};
	StrBlobPtr strbptr(strb, 1);
	cout << *strbptr << endl;
	++strbptr;
	cout << *strbptr << endl;
	Ptr_StrBlobPtr pt_strbptr(&strbptr);
	cout << pt_strbptr->operator*() << endl;
	return 0;
}
