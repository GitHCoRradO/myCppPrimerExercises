#include <iostream>
#include <fstream>
#include <string>
#include "./Ex9.49.h"
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

int main() {
	ifstream ifst("./testfile");
	if (!ifst)
		return -1;
	string longest;
	ifst >> longest;
	unsigned longest_count = number_of_a_d(longest);
	string curr;
	while(ifst >> curr) {
		unsigned curr_count = number_of_a_d(curr);
		if (curr_count <= longest_count) {
			longest = curr;
			longest_count = curr_count;
		}
	}
	cout << "the word that contains the least ascenders or descenders is: " << longest << endl;
	return 0;
}
