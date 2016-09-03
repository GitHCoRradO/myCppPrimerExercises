#include <iostream>
#include <vector>
using std::vector;
#include <algorithm>
class equality {
public:
	equality(int n) : comp(n) { }
	bool operator()(int num) const { return num == comp; }
private:
	int comp;
};

int main() {
	vector<int> vec{0, 1, 2, 3, 4, 5, 5, 5, 7, 7, 12, 13, 14, 15};
	//equality eq(5);
	//std::replace_if(vec.begin(), vec.end(), eq, 1000);
	std::replace_if(vec.begin(), vec.end(), equality(5), 1000);
	for (auto i : vec)
		std::cout << i << std::endl;
	return 0;
}
