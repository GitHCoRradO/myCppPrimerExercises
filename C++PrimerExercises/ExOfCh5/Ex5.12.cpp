#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	//string model_ff("ff"), model_fl("fl"), model_fi("fi");
	//vector<char> curr_pair(2,0);
	//char ch;
	//unsigned ff_Cnt = 0, fl_Cnt = 0, fi_Cnt = 0;
	//here is a problem:fffff will be counted as "ff occurs: 2(Wrong,it should be 3,reasons are listed below.) times.",while considering the contious letter,this could be counted as 4 times.
	//while (cin >> ch) {
	//	curr_pair[0] = ch;
	//	cin >> ch;	//if the input is fffff,on the last loop,this statement will not read into ch.
	//	curr_pair[1] = ch;//It causes this ch in this statement unchanged with the value of (the 5th) 'f'.so the curr_pair here on the last loop is "ff",resulting in the count 
	//	int case_num = 0;	// of ff being 3.
	//	if ((curr_pair[0] == model_ff[0]) && (curr_pair[1] == model_ff[1]))
	//		case_num = 0;
	//	if ((curr_pair[0] == model_fl[0]) && (curr_pair[1] == model_fl[1]))
	//		case_num = 1;
	//	if ((curr_pair[0] == model_fi[0]) && (curr_pair[1] == model_fi[1]))
	//		case_num = 2;
	//	switch (case_num) {
	//		case 0:
	//		++ff_Cnt;
	//		break;
	//		case 1:
	//		++fl_Cnt;
	//		break;
	//		case 2:
	//		++fi_Cnt;
	//		break;
	//	}
	//}
	//cout << "ff occurs: " << ff_Cnt << " times." << '\n'		
	  //   << "fl occurs: " << fl_Cnt << " times." << '\n'		
	    // << "fi occurs: " << fi_Cnt << " times." << endl;	
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch, pre_ch = '\0';
	while (cin >> ch) {
		switch (ch) {
			case 'f':
			if (pre_ch == 'f') ++ffCnt;
			break;
			case 'l':
			if (pre_ch == 'f') ++flCnt;
			break;
			case 'i':
			if (pre_ch == 'f') ++fiCnt;
			break;
		}
		pre_ch = ch;
	}
	cout << "ff occurs: " << ffCnt << " times." << '\n'
	     << "fl occurs: " << flCnt << " times." << '\n'
	     << "fi occurs: " << fiCnt << " times." << endl;
	return 0;
}
