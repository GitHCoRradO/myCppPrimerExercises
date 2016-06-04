#include <memory>
using std::unique_ptr;

int main() {
	unique_ptr<int> p1(new int(42));
	unique_ptr<int> p2(p1);
	unique_ptr<int> p3 = p1;
	return 0;
}
/*
Ex12.16.cpp: In function ‘int main()’:
Ex12.16.cpp:6:23: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
  unique_ptr<int> p2(p1);
                       ^
In file included from /usr/include/c++/5/memory:81:0,
                 from Ex12.16.cpp:1:
/usr/include/c++/5/bits/unique_ptr.h:356:7: note: declared here
       unique_ptr(const unique_ptr&) = delete;
       ^
Ex12.16.cpp:7:23: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
  unique_ptr<int> p3 = p1;
                       ^
In file included from /usr/include/c++/5/memory:81:0,
                 from Ex12.16.cpp:1:
/usr/include/c++/5/bits/unique_ptr.h:356:7: note: declared here
       unique_ptr(const unique_ptr&) = delete;
*/
