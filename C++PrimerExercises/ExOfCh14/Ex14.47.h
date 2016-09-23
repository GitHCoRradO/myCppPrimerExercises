#ifndef EX_14_47_H
#define EX_14_47_H
struct Intergal {
	operator const int();//meaningless,it will be ignored by the compiler??
	operator int() const;//normal definition of a conversion operator
};
#endif
