#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <iterator>
#include <vector>
#include <type_traits>

template <class It, class VIt>
void merge(It beginA, It endA, It beginB, It endB, VIt dest)
{
    while (beginA < endA && beginB < endB)
    {
        if (*beginA <= *beginB)
            *(dest++) = *(beginA++);
        else
            *(dest++) = *(beginB++);
    }
    while (beginA < endA)
        *(dest++) = *(beginA++);
    while (beginB < endB)
        *(dest++) = *(beginB++);
}

template <class It>
void mergeSort(It begin, It end)
{
    std::size_t distance = std::distance(begin, end);
    if (distance <= 1)
        return;
    mergeSort(begin, begin + distance/2);
    mergeSort(begin + distance/2, end);
    std::vector<std::remove_reference_t <decltype(*begin)>> temp(distance);
    merge(begin, begin + distance/2, begin + distance/2, end, temp.begin());
    auto vIt = temp.begin();
    while (begin != end)
        *(begin++) = *(vIt++);
}

#endif /* !MERGESORT_H_ */
