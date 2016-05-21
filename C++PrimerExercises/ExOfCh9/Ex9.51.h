#ifndef EX_9_51_H
#define EX_9_51_H

#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

const vector<string> monthoftheyear{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Date {
public:
//constructors
	Date() = default;
	Date(const string&);
//member function to show date
	void showdate() { cout << day << "/" << month << "/" << year << endl; }
private:
//data members
	unsigned day = 1;
	unsigned month = 1;
	unsigned year = 2016;
};

//handle 2 date formats:#1 "Janaury 1,1999",#2 "1/1/1999"
Date::Date(const string &date_str) {
	//dealing with #1
	if (date_str.find_first_of("abcdefghijklmnopqrstuvwxyz") != string::npos) {
		unsigned i = 1;
		for (auto mon : monthoftheyear) {
			if (date_str.find(mon) != string::npos) {
				month = i;
				break;
			}
			++i;
		}
		unsigned len_of_mon = (monthoftheyear.begin() + month - 1)->size();
		auto comma_id = date_str.find(',');
		day = stoul(date_str.substr(len_of_mon + 1, comma_id - len_of_mon - 1));//stoul ??
		year = stoul(date_str.substr(comma_id + 1));
	}
	//dealing with #2
	else {
		auto index1 = date_str.find_first_of('/'), index2 = date_str.find_last_of('/');
		day = stoul(date_str.substr(0, index1));
		month = stoul(date_str.substr(index1 + 1, index2 - index1 - 1));
		year = stoul(date_str.substr(index2 + 1));
	}
}

#endif
