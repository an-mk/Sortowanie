#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <iterator>
#include <vector>
#include <array>
#include <cstring>
#include <type_traits>
#include "utils.h"

namespace sort
{
    template <class It>
    inline It partition(It begin, It end) noexcept
    {
        std::remove_reference_t<decltype(*begin)> pivot = *(begin + std::distance(begin, end)/2);
        while (true)
        {
			while (*end > pivot) end--;
			while (*begin < pivot) begin++;
            if (std::distance(begin, end) > 0)
            {
                swap(*begin, *end);
                begin++;
                end--;
            }
            else
                return end;
        }
    }

    template <class It>
    void quickSortHelper(It begin, It end) noexcept
    {
        if (std::distance(begin, end) >= 1)
        {
            It pivot = partition(begin, end);
			quickSortHelper(begin, pivot);
			quickSortHelper(pivot + 1, end);
        }
    }

	template <class It>
	void quickSort(It begin, It end) noexcept
	{
		quickSortHelper(begin, end - 1);
	}
}
#endif /* !QUICKSORT_H_ */
