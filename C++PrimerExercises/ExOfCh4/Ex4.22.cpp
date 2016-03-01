#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
	//conditional operator version
	int grade = 0;
	cin >> grade;
	//odd low pass range....
	cout << ((grade > 90) ? "high pass" : ((grade < 75) && (grade > 60)) ? "low pass" : (grade > 60) ? "pass" : "fail") << endl;
	//cout << ((grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade < 75) ? "low pass" : "pass");
	//if loop version
	if (grade > 90)
		cout << "high pass" << endl;
	else if ((grade > 60) && (grade < 75))	//else if (grade < 60)
		cout << "low pass" << endl;	// cout << "fail" << endl;
	else if (grade > 60)			//else if (grade < 75)
		cout << "pass" << endl;		// cout << "low pass" << endl;
	else					//else
		cout << "fail" << endl;		// cout << "pass" << endl;
	return 0;
}
/*
surely I would perfer the if loop version,for the code control logic is more readable.
*/
