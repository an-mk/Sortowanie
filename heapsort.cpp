#include "heapsort.hpp"

#include <iterator>
#include <utility>

template <typename It>
inline static void heapify(It begin, It end, It i)
{
	auto first = begin + (std::distance(begin, i)+1)*2-1;
	auto second = begin + (std::distance(begin, i)+1)*2;
	
	It largest;

	if(first < end && *first > *i)largest = first;
	else largest = i;
	if(second < end && *second > *largest) largest = second;

	if(largest != i){		
		std::swap(*largest, *i);
		heapify(begin, end, largest);
	}
	
}

template <typename It>
inline static void build_heap(It begin, It end)
{
	for(auto i = begin + std::distance(begin,end)/2-1; i >= begin; i--)
	{
		heapify(begin, end, i);
	}
}


template <typename It>
void sort::heapsort(It begin, It end)
{
	build_heap(begin, end);
	for(auto i = end-1; i > begin; i--)
	{
		std::swap(*begin, *i);
		heapify(begin, i, begin);
	}

}