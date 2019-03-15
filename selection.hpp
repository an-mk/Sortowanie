#ifndef _SELECTION_H_
#define _SELECTION_H_

namespace sort{

	template<typename It>
	void selectionSort(const It begin,const It end);	
	
	//template<typename T>
	//void selectionSort(T &container)
	//{
	//	selectionSort(begin(container), end(container));
	//}

}


template<typename It>
void sort::selectionSort(const It begin,const It end)
{
	for(auto i = end-1; i > begin; i--)
	{
		auto max = i;
		for(auto j = i - 1; j >= begin; j--)
		{
			if(*j > *max)max = j;
		}
		std::swap(*i, *max);
	}
}

#endif