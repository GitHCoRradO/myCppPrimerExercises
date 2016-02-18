#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int a = 0, b = 0;
	cout << "Enter two integers:" << endl;
	cin >> a >> b;
	while (a > b)
	{
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
	while (a < b - 1)
	{
		cout << ++a << " ";
	}
	cout << endl;
	return 0;
}
