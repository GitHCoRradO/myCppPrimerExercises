#include <iostream>
#include <vector>
using std::cin;
using std::vector;
int main() {
	vector<int> vec_int;
	int n = 0;
	while (cin >> n) {		//if there is no input,then cin >> n would yield false and the loop body would not execute,thus
		vec_int.push_back(n);	//vec_int remains empty.How is check this out?
	}
	return 0;
}
