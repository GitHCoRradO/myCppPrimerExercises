#include <iostream>
#include "./Ex7.23_24_27.h"

using std::cout;

int main() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	return 0;
}
	
