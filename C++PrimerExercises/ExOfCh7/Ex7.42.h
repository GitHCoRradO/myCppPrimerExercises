#ifndef EX_7_42_H
#define EX_7_42_H

#include <iostream>

class Date {
public:
	//constructors:
	Date(unsigned y, unsigned m, unsigned d) : Year(y), Month(m), Day(d) { }
	Date() : Date(2016, 1, 1) { }
	Date(std::istream &is) : Date() { is >> Year >> Month >> Day; }
private:
	unsigned Year = 2016, Month = 1, Day = 1;
};
#endif
