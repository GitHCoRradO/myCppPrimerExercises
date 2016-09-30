#ifndef QUERY_BUILT_IN_PTR_H
#define QUERY_BUILT_IN_PTR_H 

#include "./TextQuery.h"
#include "./WordQuery.h"
#include "./Query_base.h"
#include "./QueryResult.h"

#include <iostream>
#include <string>
#include <memory>
class Query {
friend Query operator~(const Query&);
friend Query operator|(const Query&, const Query&);
friend Query operator&(const Query&, const Query&);
friend bool operator!=(const Query&, const Query&);
public:
	Query(const std::string &s) : q(new WordQuery(s)) { }
	Query(const Query &qry) : q(qry.q) { }
	Query(Query &&qry) noexcept : q(std::move(qry.q)) { }
	Query &operator=(const Query &);
	Query &operator=(Query &&) noexcept;
	QueryResult eval(const TextQuery &t) const
		{ return q->eval(t); }
	std::string rep() const { return q->rep(); } 
	~Query();
private:
	Query(Query_base *query) : q(query) { }
	Query_base *q;
};

inline Query::~Query() {
	delete q;
}

inline bool operator!=(const Query &lhs, const Query &rhs) {
	return lhs.rep() != rhs.rep();
}

inline Query &Query::operator=(const Query &qry) {
	if(*this != qry) {
		delete q;
		q = qry.q;
	}
	return *this;
}

inline Query &Query::operator=(Query &&qry) noexcept {
	if(*this != qry) {
		delete q;
		q = std::move(qry.q);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &, const Query &);


#endif
