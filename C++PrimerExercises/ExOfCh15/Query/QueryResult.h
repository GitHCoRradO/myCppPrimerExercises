#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include "./TextQuery.h"
class QueryResult {
friend std::ostream &print(std::ostream &, const QueryResult &);
friend std::ostream &print(std::ostream &, const QueryResult &, size_t, size_t);
using line_no = std::vector<std::string>::size_type;
public:
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) :
	sought(s), lines(p), file(f) { }
	std::set<line_no>::iterator begin();
	std::set<line_no>::iterator end();
	std::shared_ptr<std::vector<std::string>> get_file();
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

inline std::set<QueryResult::line_no>::iterator QueryResult::begin() {
	return lines->begin();
}
inline std::set<QueryResult::line_no>::iterator QueryResult::end() {
	return lines->end();
}

inline std::shared_ptr<std::vector<std::string>> QueryResult::get_file() {
	return file;
}
std::ostream &print(std::ostream &, const QueryResult &);
std::ostream &print(std::ostream &, const QueryResult &, size_t, size_t);

#endif
