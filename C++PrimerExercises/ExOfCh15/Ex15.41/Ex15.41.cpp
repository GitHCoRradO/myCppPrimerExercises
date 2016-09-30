#include "./Query_built_in_ptr.h"
#include "./Query_base.h"
#include "./WordQuery.h"
#include "./BinaryQuery.h"
#include "./AndQuery.h"
#include "./OrQuery.h"
#include "./TextQuery.h"
#include "./QueryResult.h"
#include <fstream>
#include <iostream>
int main() {
	std::ifstream is("./text");	
	TextQuery tq(is);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	print(std::cout, q.eval(tq));
	return 0;
}
