#ifndef EX_12_32_H
#define EX_12_32_H
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
using std::string;
using std::initializer_list;
using std::vector;
using std::shared_ptr;
using std::out_of_range;
using std::make_shared;

class QueryResult;
class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//add and remove elements
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	//element access
	string &front();
	string &back();
	string &front() const;
	string &back() const;
	vector<string>::iterator begin() { return data->begin(); }
	vector<string>::const_iterator begin() const { return data->cbegin(); }
	
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
	std::string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult {
friend std::ostream &print(std::ostream &, const QueryResult &);
using line_no = std::vector<std::string>::size_type;
public:
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
std::ostream &print(std::ostream &os, const QueryResult & qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " times." << std::endl;
	for (auto num : *qr.lines)
		os << "\tline " << num + 1 << ") "<< *(qr.file->begin() + num) << std::endl;
	return os;
}
void runQueries(std::ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		std::cout << "enter word to search or q to quit:";
		std::string s;
		if(!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

#endif
