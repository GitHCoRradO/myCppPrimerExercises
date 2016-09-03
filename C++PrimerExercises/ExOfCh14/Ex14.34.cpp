#include <iostream>
using std::cout;
using std::endl;

class if_then_else {
public:
	int operator()(int i, int j, int k) const {
		if (i)
			return j;
		else
			return k;
	}
};
int main() {
	if_then_else obj;
	cout << obj(0, 1, 2) << endl;
	cout << obj(-1, 1, 2) << endl;
	return 0;
}
