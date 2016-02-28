#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main() {
	Sales_data currdata, data;
	double price = 0.0;
	if (cin >> currdata.bookNo >> currdata.units_sold >> price) {
	int cnt = 1;
	while (cin >> data.bookNo >> data.units_sold >> price) {
		if (data.bookNo == currdata.bookNo)
			++cnt;
		else {
		cout << '\n' << currdata.bookNo << " occurs "
		     << cnt  << " times." << endl;
		currdata.bookNo = data.bookNo;
		cnt = 1;
		}
	}
	cout << '\n' << currdata.bookNo << " occurs " << cnt
	     << " times." << endl;
	}
	return 0;
}
