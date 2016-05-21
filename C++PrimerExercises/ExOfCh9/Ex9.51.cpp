#include <iostream>
#include "./Ex9.51.h"
using std::cout;
using std::endl;

int main() {
	Date todaydate("May 21,2016"), dedate, tomodate("22/5/2016");
	cout << "default date: ";
	dedate.showdate(); 
	cout << "today date: ";
	todaydate.showdate(); 
	cout << "tomorrow date: ";
	tomodate.showdate();
	return 0;
}
