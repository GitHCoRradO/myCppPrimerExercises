#ifndef EX_16_6_H
#define EX_16_6_H
template <unsigned N, typename T>
T *begarr(T (&arr)[N]) {
	return arr;
}
template <unsigned N, typename T>
T *endarr(T (&arr)[N]) {
	return arr + N;
}
#endif
