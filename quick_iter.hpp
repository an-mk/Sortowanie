#ifndef _QUICK_ITER_H
#define _QUICK_ITER_H

#include <vector>
#if defined(__cplusplus) && __cplusplus >= 201402L
#define o__constexpr constexpr
#else
#define o__constexpr 
#endif

namespace sort{
	template<typename T>
	o__constexpr void quicksort_iter(std::vector<T>&);
}

#include "quick_iter.cpp"

#undef o__constexpr

#endif