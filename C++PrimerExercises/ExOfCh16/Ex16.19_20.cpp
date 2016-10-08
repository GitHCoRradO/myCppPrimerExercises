#include <iostream>
#include <vector>
using std::vector;
#include <deque>
using std::deque;

template <typename T>
void print_container(const T &container) {
	for (typename T::size_type i = 0; i != container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}
template <typename T>
void print_container_iter(const T &container) {
	for (typename T::const_iterator iter = container.cbegin(); iter != container.cend(); ++iter)
		std::cout << *iter << std::endl;
	std::cout << std::endl;
}

int main() {
	vector<int> vi{0, 1, 2, 3, 5};
	print_container(vi);
	print_container_iter(vi);
	deque<double> dd{0.1, 0.2, 0.3, 0.4, 0.5};
	print_container(dd);
	print_container_iter(dd);
	return 0;
}
