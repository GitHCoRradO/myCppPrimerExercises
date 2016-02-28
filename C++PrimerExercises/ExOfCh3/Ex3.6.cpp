#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string str;
	cin >> str;
	cout << endl;
	for (auto &c : str) c = 'X';//for (auto c : str)
	cout << str << endl;	    //	c = 'X';
	return 0;	   	    //cout << str << endl;
}				    /* Here c has type char.When I see the output test of this version,I did not realise whereinlies the fault.(I should use a reference to refer to each char in str.here,c is just a copy of each of them.)In addtion,I refer to the previous chapters to check out how to assign a variable of type char but get no result.so how exactly should I initialize and assign a variable of type char?*/
