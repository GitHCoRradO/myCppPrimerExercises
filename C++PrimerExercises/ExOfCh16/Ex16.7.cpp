#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

template <typename T, unsigned N>
constexpr unsigned sizearr(T (&arr)[N]) {
	return N;
}
int main() {
	int iarr[] = {0, 1, 2, 3, 4};
	string sarr[] = {"array", "string", "vector"};
	cout << sizearr(iarr) << " " << sizearr(sarr) << endl;
	return 0;
}
