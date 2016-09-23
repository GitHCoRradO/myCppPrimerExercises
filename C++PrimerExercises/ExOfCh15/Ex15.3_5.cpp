#include "./Ex15.3_5.h"
int main() {
	Quote qt("0000000001", 5.5);
	Bulk_Quote bq("0000000002", 5.6, 10, 0.2);
	print_total(std::cout, qt, 5);
	print_total(std::cout, bq, 5);
	print_total(std::cout, bq, 10);
	return 0;
}
