#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

namespace sort{

template<typename It>
void heapsort(const It beg,const It end);

//template<typename T>
//void heapsort(T &c)
//{
//	heapsort(begin(c), end(c));
//}

}

#include "heapsort.cpp"

#endif