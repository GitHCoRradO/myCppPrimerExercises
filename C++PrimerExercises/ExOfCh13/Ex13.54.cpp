#include "./Ex13.54.h"
#include <iostream>

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap" << std::endl;
}

HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0)
{
    std::cout << "call constructor" << std::endl;
}

HasPtr::HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i)
{
    std::cout << "call copy constructor" << std::endl;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
{
    p.ps = 0;
    std::cout << "call move constructor" << std::endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
	if (this != &rhs) {
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}

HasPtr::~HasPtr()
{
    std::cout << "call destructor" << std::endl;
    delete ps;
}

int main()
{
	HasPtr hp, hp1("world");
	/*
Ex13.54.cpp: In function ‘int main()’:
Ex13.54.cpp:52:5: error: ambiguous overload for ‘operator=’ (operand types are ‘HasPtr’ and ‘std::remove_reference<HasPtr&>::type {aka HasPtr}’)
  hp = std::move(hp1);
     ^
Ex13.54.cpp:28:9: note: candidate: HasPtr& HasPtr::operator=(HasPtr)
 HasPtr& HasPtr::operator=(HasPtr rhs)
         ^
Ex13.54.cpp:34:9: note: candidate: HasPtr& HasPtr::operator=(HasPtr&&)
 HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {

	*/
	hp = std::move(hp1);
	//neither copy-assignment operator or move-assignment operator can be overloaded with the single assignment operator
	return 0;
}

