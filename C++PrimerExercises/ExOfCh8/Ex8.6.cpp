#include "../ExOfCh7/Ex7.21.h"
#include <fstream>
#include <iostream>
using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	Sales_data total;
	if (read(ifst, total)) {
		Sales_data trans;
		while (read(ifst, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		std::cerr << "No Data?!" << endl;
	}
	return 0;
}
