#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin >> ch) {
		switch (ch) {
			case 'a':		//Originally,I count each vowel,either lower- or upper- case in their separate cases 
			case 'A':		//with break statments at the end of each case.
			++aCnt;			//according to Moophy's repo,I modify the code this way,which looks much prettier.
			break;			//"grouping" the cases is rather clever.
			case 'e':
			case 'E':
			++eCnt;
			break;
			case 'i':
			case 'I':
			++iCnt;
			break;
			case 'o':
			case 'O':
			++oCnt;
			break;
			case 'u':
			case 'U':
			++uCnt;
			break;
		}
	}
	cout << "Number of vowel a:\t" << aCnt << '\n'
	     << "Number of vowel e:\t" << eCnt << '\n'
	     << "Number of vowel i:\t" << iCnt << '\n'
	     << "Number of vowel o:\t" << oCnt << '\n'
	     << "Number of vowel u:\t" << uCnt << endl;
	return 0;
}
