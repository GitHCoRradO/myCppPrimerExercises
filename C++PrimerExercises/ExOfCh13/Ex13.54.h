#ifndef EX_13_54_H
#define EX_13_54_H

#include <string>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string());
    HasPtr(const HasPtr &hp);
    HasPtr(HasPtr &&p) noexcept;
    HasPtr& operator=(HasPtr rhs);
//  HasPtr& operator=(const HasPtr &rhs);
    HasPtr& operator=(HasPtr &&rhs) noexcept;
    ~HasPtr();

private:
    std::string *ps;
    int i;
};

#endif
