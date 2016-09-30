#ifndef EX_16_4_H
#define EX_16_4_H

template <typename T, typename U>
T find_iter(T beg, T end, const U &v) {
	for(;beg != end; ++beg) {
		if(*beg == v)
			return beg;
	}
	return end;
}
#endif

