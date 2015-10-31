#include<iostream>
#include<string>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main(){
	Sales_data total,trans;
	double price = 0.0;
	while (std::cin >> trans.bookNo >>trans.units_sold >> price ) {
	total.units_sold += trans.units_sold;
	total.revenue += trans.units_sold * price;
	total.bookNo = trans.bookNo;
	}
	std::cout << std::endl << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue/total.units_sold <<std::endl;
	return 0;
}
