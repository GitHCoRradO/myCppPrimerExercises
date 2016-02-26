/*the null terminated char array has a '\0' as the last element,thus when cp points to '\0',*cp yields \0 as the condition of while,which would end this loop.
if there is no '\0' at the end of the char array,pointer cp would go through memory,with the loop body printing strange values,until cp encounters a null character.
STRANGE THING HAPPENS:
Using g++ compiler,the resulting program a.out runs normally.why?
gcc version 5.2.1 20151010 (Ubuntu 5.2.1-22ubuntu2)
*/
#include <iostream>
using std::cout;
using std::endl;
int main() {
//	const char ca[] = {'h', 'e', 'l', 'l', 'o','\0'};
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp = ca;
	while (*cp) {
		cout << *cp << endl;
		++cp;
	}
	return 0;
}
