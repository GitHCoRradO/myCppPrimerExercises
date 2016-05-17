#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main() {
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	vector<int> veci;
	list<int> listi;
	for(auto ptr = begin(ia); ptr != end(ia); ++ptr) {
		veci.push_back(*ptr);
		listi.push_back(*ptr);
	}
	cout << "original veci:" << endl;
	for (auto i : veci)
		cout << i << " ";
	cout << endl;	
	cout << "original listi:" << endl;
	for (auto i : listi)
		cout << i << " ";
//	for(auto it = listi.begin();  it != listi.end(); )
//	        if(*it & 0x1) it = listi.erase(it);
//	      	else ++it;	
	for (auto iter = listi.begin(); iter != listi.end();) {
		if (*iter % 2 == 1)
			iter = listi.erase(iter);
		else
			++iter;
	}


//	for (auto iter = veci.rbegin(); iter != veci.rend();) {
//		if (*iter % 2 == 0) {
//			auto temp = iter + 1;
//			veci.erase(iter);
//			iter = temp;
//		}
//		else
//			++iter;
//	}
	for (auto iter = veci.begin(); iter != veci.end();) {			// is it not that after the erasure point,all iterators would be invalidated?
		if (*iter % 2 == 0) 
			iter = veci.erase(iter);
		else
			++iter;
	}
	cout << endl;
	cout << "changed veci:" << endl;
	for (auto i : veci)
		cout << i << " ";
	cout << endl;
	cout << "changed listi:" << endl;
	for (auto i : listi)
		cout << i << " ";
	cout << endl;
	return 0;
}
