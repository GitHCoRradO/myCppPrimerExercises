#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
	string curr_str,pre_str;
	vector<string> vec_str;
	unsigned max_num = 0,curr_num = 0;
	while (cin >> curr_str) {
		vec_str.push_back(curr_str);
		if (curr_str != pre_str)
			curr_num = 0;
		++curr_num;
		if (curr_num >= max_num)
			max_num = curr_num;
		pre_str = curr_str;
	}
	if (vec_str.size() > 1 && max_num == 1)
		cout << "no word was repeated." << endl;
	else {
		unsigned num = 1,index = 0;
		for (unsigned i = 1; i != vec_str.size(); ++i) {
			if (vec_str[i] != vec_str[i - 1])
				num = 1;
			++num;
			if (num == max_num) {
				index = i;
				break;
			}
		}
		cout << vec_str[index] << " occurs " << max_num << " times." << endl;
	}
	return 0;
}			
			
			
