#ifndef EX_14_STRVEC_H
#define EX_14_STRVEC_H

#include <memory>
#include <string>
#include <initializer_list>

class StrVec
{
friend bool operator==(const StrVec &, const StrVec &);
friend bool operator!=(const StrVec &, const StrVec &);
friend bool operator<(const StrVec &, const StrVec &);
friend bool operator>(const StrVec &, const StrVec &);
friend bool operator<=(const StrVec &, const StrVec &);
friend bool operator>=(const StrVec &, const StrVec &);
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    StrVec &operator=(std::initializer_list<std::string>);
    std::string &operator[](size_t n) { return elements[n]; }
    const std::string &operator[](size_t n) const { return elements[n]; }

    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string&);

private:
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const std::string*, const std::string*);

private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;
    std::allocator<std::string> alloc;
};
bool operator==(const StrVec &, const StrVec &);
bool operator!=(const StrVec &, const StrVec &);
bool operator<(const StrVec &, const StrVec &);
bool operator>(const StrVec &, const StrVec &);
bool operator<=(const StrVec &, const StrVec &);
bool operator>=(const StrVec &, const StrVec &);

#endif
