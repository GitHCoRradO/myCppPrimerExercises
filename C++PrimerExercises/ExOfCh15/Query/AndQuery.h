#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "./BinaryQuery.h"


class AndQuery : public BinaryQuery {
friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query &left, const Query &right) :
	BinaryQuery(left, right, "&") { }
	QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif
