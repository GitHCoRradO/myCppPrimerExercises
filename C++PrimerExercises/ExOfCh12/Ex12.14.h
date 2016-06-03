#ifndef EX12_14_H
#define EX12_14_H
#include <memory>
using std::shared_ptr;

struct destination { };
struct connection { };
connection connect(destination *);
void disconnect(connection);
void end_connection(connection *p) { disconnect(*p); }

void f(destination &d) {
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
	/*....*/
}

#endif
