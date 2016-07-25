#ifndef EX_13_18_H
#define EX_13_18_H
include <iostream>
using std::cin;
using std::cout;
using std::endl;
include <string>
using std::string;

class Employee {
public:
//	constructors
	Employee() : uiD(++cnt) { 
		cout << "enter your name:" << endl;
		getline(cin, name);
	}
	Employee(const string s) : name(s), uiD(++cnt) { }
private:
	static unsigned cnt;
	string name;
	unsigned uiD;
};
unsigned Employee::cnt = 0;

#endif

/*
I think the synthesised version of copy-control members will work just fine.
when creating objects of Employee type using the copy constructor, or assigning to an object of Employee type,these objects all refer to the same person.I do not want to change the person's name or unique ID.
for instance,I am talking about an employee,whose name and unique ID are strange to me,I shall refer to him/her as A.latter on,I talk about another employee,who I refer to as B.when my story reach some point,it turns out that A and B are the same person.In this case,I might overload the symbol = this way:
A = B.
it means A and B are the same person.

*/
