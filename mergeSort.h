#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <iterator>
#include <vector>
#include <array>
#include <cstring>
#include <type_traits>

template <class It, class VIt>
inline void merge(It beginA, It endA, It beginB, It endB, VIt dest) noexcept
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
        
    // Rozwiązanie z memcpy jest wbrew pozorom wolniejsze!!!

    //if (beginA < endA)
    //    std::memcpy(&*dest, &*beginA, std::distance(beginA, endA) * sizeof(std::remove_reference_t<decltype(*dest)>));
    //if (beginB < endB)
    //    std::memcpy(&*dest, &*beginB, std::distance(beginB, endB) * sizeof(std::remove_reference_t<decltype(*dest)>));
}

template <class It>
void mergeSortOld(It begin, It end) noexcept
{
    std::size_t distance = std::distance(begin, end);
    if (distance <= 1)
        return;
    mergeSortOld(begin, begin + distance/2);
    mergeSortOld(begin + distance/2, end);
    std::vector<std::remove_reference_t <decltype(*begin)>> temp(distance);
    merge(begin, begin + distance/2, begin + distance/2, end, temp.begin());
    auto vIt = temp.begin();
    while (begin != end)
        *(begin++) = *(vIt++);
}

template <class It, class TIt>
void mergeSortHelper(It begin, It end, TIt tempBegin) noexcept
{
    std::size_t distance = std::distance(begin, end);
    if (distance <= 1)
        return;
    mergeSortHelper(begin, begin + distance/2, tempBegin);
    mergeSortHelper(begin + distance/2, end, tempBegin);
    merge(begin, begin + distance/2, begin + distance/2, end, tempBegin);
    TIt tIt = tempBegin;
    while (begin != end)
        *(begin++) = *(tIt++);
}

template <class It>
void mergeSort(It begin, It end)
{
    static std::array<std::remove_reference_t<decltype(*begin)>, 100000> temp;
    mergeSortHelper(begin, end, temp.begin());
}

#endif /* !MERGESORT_H_ */
