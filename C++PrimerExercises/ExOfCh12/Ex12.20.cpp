#include <iostream>
#include <fstream>
#include <string>
#include "./Ex12.19.h"
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	string str;
	StrBlob strblob1;
	while (getline(ifst,str))
		strblob1.push_back(str);
	StrBlobPtr strblobptr(strblob1);
	for (size_t i = 0; i != strblob1.size(); ++i) {
		cout << strblobptr.deref();
		cout << endl;
		strblobptr.incr();
	}
	return 0;
}
