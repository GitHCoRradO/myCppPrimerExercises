#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <functional>
using std::function;
#include <string>
using std::string;
#include <map>
using std::map;

int add(int i, int j) { return i + j; }

auto mod = [](int i, int j) { return i % j; };

struct divide {
	int operator()(int i, int j) const { return i / j; }
};
map<string, function<int(int, int)>> binops = 
{ {"+", add}, {"-", std::minus<int>()}, {"/", divide()}, {"*", [](int i, int j) { return i * j;}}, {"%", mod} };
int main() {
	int lhs, rhs;
	string op;
	cin >> lhs >> op >> rhs;
	cout << binops[op](lhs, rhs) << endl;
	return 0;
}
