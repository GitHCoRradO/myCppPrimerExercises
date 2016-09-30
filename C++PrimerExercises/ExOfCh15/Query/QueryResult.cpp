#include "./QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " times." << std:: endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
} 

std::ostream &print(std::ostream &os, const QueryResult &qr, size_t beg, size_t end) {
	if(beg > end) {
		std::cout << "invalid line range.pls try again." << std::endl;
		return os;
	}
	else {
		os << qr.sought << " occurs " << qr.lines->size() << " times." << std:: endl;
		os << "those between line " << beg << " to line " <<  end << ":" << std::endl;
		for (auto num : *qr.lines) {
			if(num + 1 >= beg && num + 1 <= end)
			os << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
		}
		return os;
	}
}
