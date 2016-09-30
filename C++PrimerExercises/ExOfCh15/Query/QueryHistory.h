#ifndef QUERYHISTORY_H
#define QUERYHISTORY_H

#include "./Query.h"

#include <vector>
#include <memory>
class QueryHistory {
public:
	Query &operator[](size_t n) { return *qh[n]; }
	void add_query(const Query&);
private:
	std::vector<std::shared_ptr<Query>> qh;
};

inline void QueryHistory::add_query(const Query &q) {
	qh.push_back(std::make_shared<Query>(q));
}

#endif
