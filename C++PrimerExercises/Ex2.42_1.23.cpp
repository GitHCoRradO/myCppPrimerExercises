#include<iostream>
#include<string>
#include"Sales_data.h"
int main(){
	Sales_data currdata,data;
	double price = 0.0;
	if (std::cin >> currdata.bookNo >> currdata.units_sold >> price) {
		int cnt = 1;
		while (std::cin >> data.bookNo >> data.units_sold >> price){
			if (data.bookNo == currdata.bookNo)
				++cnt;
			else {
			std::cout << '\n' <<  currdata.bookNo << " occurs " << cnt << " times." << std::endl;
			currdata.bookNo = data.bookNo;
			cnt = 1;
			}
		}
		std::cout << '\n' << currdata.bookNo << " occurs " << cnt << " times." << std::endl;
	}
	return 0;
}
