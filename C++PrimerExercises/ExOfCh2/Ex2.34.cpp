#include<iostream>
int main()
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto &g = ci;
/*	std::cout << a << std::endl;
	a = 42;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b = 42;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	c= 42;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	d = 42;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	e = 42;
	std::cout << e << std::endl;*/
	std::cout << g << std::endl;
	g = 42;
	std::cout << g << std::endl;
	return 0;
}
