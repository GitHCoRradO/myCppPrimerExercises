#ifndef EX_13_58_H
#define EX_13_58_H

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <iostream>
using std::cout;
using std::endl;

class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	vector<int> data;
};
Foo Foo::sorted() && {
	sort(data.begin(), data.end());
	cout << "Foo sorted() &&;" << endl;
	return *this;
}

/*
//Exercise 13.56
Foo Foo::sorted() const & {
	Foo ret(*this);
	cout << "Foo sorted() const &;" << endl;
	return ret.sorted();
}
*/


//Exercise 13.57
Foo Foo::sorted() const & {
	cout << "Foo sorted() const &;" << endl;
	return Foo(*this).sorted();
}


/*
Foo Foo::sorted() const & {
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	cout << "Foo sorted() const &;" << endl;
	return ret;
}
*/
#endif
