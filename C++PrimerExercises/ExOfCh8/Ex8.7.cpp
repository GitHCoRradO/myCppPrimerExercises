#include "../ExOfCh7/Ex7.21.h"
#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::endl;

int main(int argc, char *argv[]) {
        ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
        Sales_data total;
        if (read(ifst, total)) {
                Sales_data trans;
                while (read(ifst, trans)) {
                        if (total.isbn() == trans.isbn()) {
                                total.combine(trans);
                        }
                        else {
                                print(ofst, total) << endl;
                                total = trans;
                        }
                }
                print(ofst, total) << endl;
        }
        else {
                std::cerr << "No Data?!" << endl;
        }
        return 0;
}
