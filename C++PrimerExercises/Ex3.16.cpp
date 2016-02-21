#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main() {
	vector<int> v1;
	cout << "Size of v1:" << v1.size() << endl;
	vector<int> v2(10);
	cout << "Size of v2:" << v2.size() << endl;
	for (auto i : v2)
		cout << i << " ";
	cout << endl;
	vector<int> v3(10 ,42);
	cout << "Size of v3:" << v3.size() << endl;
	for (auto i : v3)
		cout << i << " ";
	cout << endl;
	vector<int> v4{10};
	cout << "Size of v4:" << v4.size() << endl;
	for (auto i : v4)
		cout << i << " ";
	cout << endl;
	vector<int> v5{10,42};
	cout << "Size of v5:" << v5.size() << endl;
	for (auto i : v5)
		cout << i << " ";
	cout << endl;
	vector<string> v6{10};
	cout << "Size of v6:" << v6.size() << endl;
	vector<string> v7{10,"hi"};
	cout << "Size of v7:" << v7.size() << endl;
	for ( auto str : v7)
		cout << str << " ";
	cout << endl;
	return 0;
}
	
