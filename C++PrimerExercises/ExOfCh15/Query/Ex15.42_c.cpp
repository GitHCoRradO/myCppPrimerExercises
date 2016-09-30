#include "./Query.h"
#include "./Query_base.h"
#include "./WordQuery.h"
#include "./BinaryQuery.h"
#include "./AndQuery.h"
#include "./OrQuery.h"
#include "./TextQuery.h"
#include "./QueryResult.h"
#include "./QueryHistory.h"
#include <fstream>
#include <iostream>

int main() {
        std::ifstream is("./text");
        TextQuery tq(is);
        Query q1("fiery"), q2("bird"), q3("wind");
	QueryHistory qh;
	qh.add_query(q1);
	qh.add_query(q2);
	qh.add_query(q3);
	Query q4 = qh[0] & qh[1] | qh[2];
	qh.add_query(q4);
        print(std::cout, q4.eval(tq), 4, 5);
        return 0;
}

