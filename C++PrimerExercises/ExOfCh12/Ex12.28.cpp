#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;
#include <memory>
using std::shared_ptr;
#include <map>
using std::map;
#include <set>
using std::set;
using line_no = vector<string>::size_type;

int main(int argc, char *argv[]) {
	ifstream ifst(argv[1]);
	vector<string> file;
	map<string, shared_ptr<set<line_no>>> wm;
	string text;
	while (getline(ifst, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
	cout << "input your query word:" << endl;
	string temp;
	cin >> temp;
	if (wm.find(temp) != wm.end()) {
		cout << temp << " occurs " << wm[temp]->size() << " times." << endl;
		for (auto num : *(wm[temp])) {
			cout << "\t(line " << num + 1 << ") " << *(file.begin() + num) << endl;
		}
	}
	else
		cout << temp << " not in file." << endl;	
	return 0;
}
