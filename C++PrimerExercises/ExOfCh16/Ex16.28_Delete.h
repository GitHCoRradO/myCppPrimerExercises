#ifndef EX_16_28_DELETE_H
#define EX_16_28_DELETE_H

class Delete {
public:
	template <typename T>
	void operator()(T *p) const { delete p; }
};

#endif
