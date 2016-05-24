#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using namespace std::placeholders;
using std::vector;
using std::find_if;
using std::bind;
using std::size_t;
bool check_size(string const& str, size_t sz)
{
    return str.size() < sz;
}

int main()
{
    vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
    string str("123456");
    auto f = bind(check_size, str, _1);
    auto result = find_if(vec.begin(), vec.end(), f);
    if (result != vec.cend())
        cout << *result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
