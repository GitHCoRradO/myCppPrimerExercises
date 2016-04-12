#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main(int argc,char **argv) {
	string str;
	for (int i = 1; i != argc; ++i)
//		str += *argv[i] + " ";		//strange charater output.maybe it is because *argv[i] results in a C-style string.but it is illegal to add two C-style strings,right?this is strange.
		str += static_cast<string>(argv[i]) + " ";
	cout << str << endl;
	return 0;
}
