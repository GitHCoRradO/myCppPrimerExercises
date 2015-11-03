#include<iostream>
#include<string>
#include"Sales_data.h"
int main(){
	Sales_data data1,data2;
	double price = 0.0;
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	std::cout << data1.bookNo << " " << data1.units_sold + data2.units_sold << " " << data1.revenue + data2.revenue << " " 
		  << (data1.revenue + data2.revenue)/(data1.units_sold + data2.units_sold) << std::endl;
	return 0;
}
