#include "./Ex15.26_27.h"

int main() {
	Bulk_quote bq1;
	Bulk_quote bq2("1234567890", 2.5, 12, 0.2); //why are there 2 Quote copy constructors and 2 Quote destructors here?
	bq1 = std::move(bq2);
	return 0;
}
