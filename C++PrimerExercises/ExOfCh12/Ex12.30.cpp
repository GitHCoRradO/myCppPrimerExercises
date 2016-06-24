#include "./Ex12.30.h"
#include <fstream>
using std::ifstream;
int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	runQueries(ifst);
	return 0;
}
