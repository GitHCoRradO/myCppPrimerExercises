#ifndef EX_16_14_H
#define EX_16_14_H

#include <string>
using std::string;
#include <iostream>

template <unsigned, unsigned> class Screen;
template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &, const Screen<H, W> &);
template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &, Screen<H, W> &);

template <unsigned height, unsigned width>
class Screen {
friend std::ostream &operator<< <height, width>(std::ostream &, const Screen &);
friend std::istream &operator>> <height, width>(std::istream &, Screen &);
public:
	using pos = string::size_type;
	Screen() = default;
	Screen(char c) : contents(height * width, c) { }
	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd) const {
		pos row = ht * width;
		return contents[row + wd];
	}
	Screen &move(pos r, pos c) {
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
private:
	string contents;
	pos cursor = 0;
};

template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &scn) {
	for (unsigned i = 0; i != H; ++i) {
		for(unsigned j = 0; j != W; ++j)
			os << scn.contents[i * W + j];
		os << std::endl;
	}
	return os;
}

template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &scn) {
	char c;
	is >> c;
	string temp(H * W, c);
	scn.contents = temp;
	return is;
}

#endif
