#include <iostream>
using std::cout;
using std::endl;
class numbered {
friend void f(numbered s);
public:
	//constructor:
	numbered() : mysn(++sn) { }
private:
	static unsigned sn;
	unsigned mysn;
};
unsigned numbered::sn = 0;

void f (numbered s) {
	cout << s.mysn << endl;
}

int main() {
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
