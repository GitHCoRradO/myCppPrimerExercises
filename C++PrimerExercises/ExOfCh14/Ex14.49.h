#ifndef EX_14_49_H
#define EX_14_49_H
#include <iostream>
class Date {
public:
	//constructors:
	Date() = default;
	Date(unsigned y, unsigned m, unsigned d) : Year(y), Month(m), Day(d) { }
	Date(std::istream &is);
	//conversion operator
	operator bool() const;
private:
	unsigned Year = 2016, Month = 1, Day = 1;
};
Date::Date(std::istream &is) {
	is >> Year >> Month >> Day;
}
Date::operator bool() const {
	if (Year >= 2016)
		return true;
	else
		return false;
}
#endif
