#include "./Ex12.27.h"
#include <fstream>
#include <iostream>
#include <string>
using std::ifstream;
using std::cin;
using std::endl;
using std::cout;
using std::string;

int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	runQueries(ifst);
	return 0;
}
