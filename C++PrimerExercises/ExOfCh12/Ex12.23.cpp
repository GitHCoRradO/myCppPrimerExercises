#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::strcat;
using std::strlen;
using std::unique_ptr;
int main() {
	char str1[7] = "Hamlet", str2[11] = "Shakespear";
	strcat(str1, str2);
	cout << str1 << endl;
	unique_ptr<char []> up(new char[strlen(str1)]());
	for (int i = 0; i != strlen(str1); ++i)
		up[i] = *(str1 + i);
	for (int i = 0; i != strlen(str1); ++i)
		cout << up[i];
	cout << endl;
	up.reset();		//release or reset?
	string s1("Hamlet"), s2("Shakespear"), s3;
	s3 = s1 + s2;
	unique_ptr<char []> down(new char[s3.size()]);
	for (int i = 0; i != s3.size(); ++i)
		down[i] = s3[i];
	for (int i = 0; i != s3.size(); ++i)
		cout << down[i];
	cout << endl;
	down.reset();
	return 0;
}

/*
#include <iostream>
#include <string>
#include <string.h>

int main()
{
    // dynamically allocated array of char
    char *concatenate_string = new char[strlen("hello " "world") + 1]();
    strcat(concatenate_string, "hello ");
    strcat(concatenate_string, "world");
    std::cout << concatenate_string << std::endl;
    delete [] concatenate_string;
    
    // std::string
    std::string str1{ "hello " }, str2{ "world" };
    std::cout << str1 + str2 << std::endl;
}
*/
