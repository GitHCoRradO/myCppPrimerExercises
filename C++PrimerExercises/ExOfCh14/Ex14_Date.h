#ifndef EX_14_DATE_H
#define Ex_14_DATE_H

#include <iostream>
using std::istream;
using std::ostream;

class Date {
friend istream &operator>>(istream &, Date &);
friend ostream &operator<<(ostream &, const Date &);
friend bool operator==(const Date &, const Date &);
friend bool operator!=(const Date &, const Date &);
friend bool operator<(const Date &, const Date &);
friend bool operator<=(const Date &, const Date &);
friend bool operator>(const Date &, const Date &);
friend bool operator<=(const Date &, const Date &);
public:
	//constructors:
	Date() = default;
	Date(unsigned y, unsigned m, unsigned d) : Year(y), Month(m), Day(d) { }
	Date(std::istream &is) { is >> *this; }
	//I think the synthesized version of copy control members would work just fine.
private:
	unsigned Year = 2016;
	unsigned Month = 1;
	unsigned Day = 1;
};
istream &operator>>(istream &is, Date &dd) {
	is >> dd.Year >> dd.Month >> dd.Day;
	if (!is)
		dd = Date();
	return is;
}
ostream &operator<<(ostream &os, const Date &date) {
	os << date.Day << "," << date.Month << "'" << date.Year;
	return os;
}

/*
there is no logical meaning for arithmetic operators(+,-,*,/) for Date objects.so I do not define these operators.
*/
bool operator==(const Date &lhs, const Date &rhs) {
	return lhs.Year == rhs.Year && lhs.Month == rhs.Month && lhs.Day == rhs.Day;
}
bool operator!=(const Date &lhs, const Date &rhs) {
	return !(lhs == rhs);
}
bool operator<(const Date &lhs, const Date &rhs) {
	if (lhs.Year < rhs.Year)
		return true;
	else if (lhs.Year > rhs.Year)
		return false;
	else if (lhs.Year == rhs.Year) {
		if (lhs.Month < rhs.Month)
			return true;
		else if (lhs.Month > rhs.Month)
			return false;
		else if (lhs.Month == rhs.Month) {
			if (lhs.Day < rhs.Day)
				return true;
			else
				return false;
		}
	}
}

bool operator>(const Date &lhs, const Date &rhs) {
	return rhs < lhs;
}


bool operator<=(const Date &lhs, const Date &rhs) {
	return lhs < rhs || lhs == rhs;
}
bool operator>=(const Date &lhs, const Date &rhs) {
	return lhs > rhs || lhs == rhs;
}

#endif
