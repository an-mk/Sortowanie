#ifndef _INSERTION_H_
#define _INSERTION_H_

namespace sort{

	template<typename It>
	void insertionSort(const It begin,const It end);	
	
	template<typename T>
	void insertionSort(T &container)
	{
		insertionSort(begin(container), end(container));
	}

}

template<typename It>
void sort::insertionSort(const It begin, const It end)
{
	for(auto i = begin +1; i < end; i++)
	{
		auto key = *i;
		auto j = i - 1;
		while( j >= begin && *j > key)
		{
			*(j+1) = *j;
			j--;
		}
		*(j+1) = key;
	}

}

#endif