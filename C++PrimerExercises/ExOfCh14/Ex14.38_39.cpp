#include "./Ex14.38.h"

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	length_bound lb(1, 10), lb_1_9(1, 9), lb_10_more(10, 1024);
	string s;
	int cnt_1_10 = 0, cnt_1_9 = 0, cnt_10_more = 0;
	while(ifst >> s) {
		if(lb(s))
			++cnt_1_10;
		if(lb_1_9(s))
			++cnt_1_9;
		if(lb_10_more(s))
			++cnt_10_more;
	}
	cout << "1 <= length <= 10: " << cnt_1_10 << endl;
	cout << "1 <= length <= 9: " << cnt_1_9 << endl;
	cout << "10 <= length: " << cnt_10_more << endl;
	return 0;
}
