#ifndef EX_12_27_H
#define EX_12_27_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::shared_ptr;
using std::weak_ptr;

class QueryResult;

class TextQuery {
friend class QueryResult;
public:
	//constructors:
	TextQuery(ifstream &ifstr);
	//member functions:
	QueryResult query(const string &s);
private:
	//data members:
	shared_ptr<vector<string>> textfile;
	shared_ptr<map<string, set<unsigned>>> map_of_QR;
	shared_ptr<map<string, unsigned>> word_cnt;
};

TextQuery::TextQuery(ifstream &ifstr) {
	string line;
	while (getline(ifstr, line))
		textfile->push_back(line);
}

class QueryResult {
friend ostream &print(ostream &, const QueryResult &);
private:
	//data members:
	shared_ptr<map<string, set<unsigned>>> ptr_map_of_QR;	//in first version,I used weak_ptr for these 3 pointers.
	shared_ptr<map<string, unsigned>> ptr_wordcnt;		/*  the compliers complains as follows:
								Ex12.27.h: In function ‘void print(std::ostream&, QueryResult&)’:
Ex12.27.h:60:22: error: base operand of ‘->’ has non-pointer type ‘std::weak_ptr<std::map<std::__cxx11::basic_string<char>, unsigned int> >’
  if ((qrt.ptr_wordcnt->find(qrt.word_query)) != qrt.ptr_wordcnt->end()) {
                      ^
Ex12.27.h:60:64: error: base operand of ‘->’ has non-pointer type ‘std::weak_ptr<std::map<std::__cxx11::basic_string<char>, unsigned int> >’
  if ((qrt.ptr_wordcnt->find(qrt.word_query)) != qrt.ptr_wordcnt->end()) {
                                                                ^
Ex12.27.h:61:44: error: no match for ‘operator*’ (operand type is ‘std::weak_ptr<std::map<std::__cxx11::basic_string<char>, unsigned int> >’)
   os << qrt.word_query << " occurs " << (((*qrt.ptr_wordcnt)[qrt.word_query]) > 1 ? " times" : " time") << endl;
                                            ^
Ex12.27.h:63:27: error: no match for ‘operator*’ (operand type is ‘std::weak_ptr<std::map<std::__cxx11::basic_string<char>, std::set<unsigned int> > >’)
   set<unsigned> &lines = (*qrt.ptr_map_of_QR)[qrt.word_query];
                           ^
Ex12.27.h:66:11: error: no match for ‘operator*’ (operand type is ‘std::weak_ptr<std::vector<std::__cxx11::basic_string<char> > >’)
    os << (*qrt.ptr_vec)[*iter] << endl;

								*/
	shared_ptr<vector<string>> ptr_vec;
	string word_query;
public:
	QueryResult(TextQuery &tq, const string &s) : ptr_map_of_QR(tq.map_of_QR), ptr_wordcnt(tq.word_cnt), ptr_vec(tq.textfile), word_query(s) { }
};

ostream &print(ostream &os, const QueryResult &qrt) {
	if ((*qrt.ptr_wordcnt).find(qrt.word_query) != qrt.ptr_wordcnt->end()) {						
		os << qrt.word_query << " occurs " << (((*qrt.ptr_wordcnt)[qrt.word_query]) > 1 ? " times" : " time") << endl;
		os << '\t';
		set<unsigned> &lines = (*qrt.ptr_map_of_QR)[qrt.word_query];
		for (auto iter = lines.cbegin(); iter != lines.cend(); ++iter) {
			os << "(line " << *iter << ") ";
			os << (*qrt.ptr_vec)[*iter] << endl;
		}
	}
	else
		os << qrt.word_query << " is not found in the textfile." << endl;
	return os;
}

//search the text each time we run query function,yet the string to set map grows as user search the text each time.
QueryResult TextQuery::query(const string &s) {
	const vector<string> &vec_s = *textfile;
	map<string, unsigned> &m_wordcnt = *word_cnt;
	map<string, set<unsigned>> &m_QR = *map_of_QR;
	for (auto iter = vec_s.cbegin(); iter != vec_s.cend(); ++iter) {
		unsigned line_ind = iter - vec_s.cbegin();
		istringstream istr(*iter);
		string each_word;
		while (istr >> each_word) {
			if (s == each_word) {
				++m_wordcnt[s];
				m_QR[s].insert(line_ind);
			}
		}
	}
	QueryResult query_result(*this, s);
	return query_result;
}

void runQueries(ifstream &infile) {
        TextQuery tq(infile);
        while (true) {
                cout << "enter word to search or q to quit" << endl;
        string s;
        if (!(cin >> s) || s == "q")
                break;
        print(cout, tq.query(s)) << endl;
	}
}

#endif
