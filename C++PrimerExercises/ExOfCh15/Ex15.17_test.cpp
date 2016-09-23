#include "./Ex15.15_16.h"
int main() {
/*

Ex15.17_test.cpp: In function ‘int main()’:
Ex15.17_test.cpp:3:13: error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
  Disc_quote dq;
             ^
In file included from Ex15.17_test.cpp:1:0:
./Ex15.15_16.h:22:7: note:   because the following virtual functions are pure within ‘Disc_quote’:
 class Disc_quote : public Quote {
       ^
./Ex15.15_16.h:27:9: note: 	virtual double Disc_quote::net_price(size_t) const
  double net_price(size_t) const = 0;
         ^


*/
	Disc_quote dq;
	return 0;
}
