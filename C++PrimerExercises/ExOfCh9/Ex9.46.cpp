#include <iostream>
#include <string>
#include "./Ex9.46.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	string great_activist("Martin Luther King");
	add_addresses(great_activist, "Mr.", " Jr.");
	cout << great_activist << endl;
	return 0;
}
