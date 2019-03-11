#include "MeasurementTool.h"
#include "testGenerators.h"
#include "mergeSort.h"
#include "quick_iter.hpp"

int main() 
{
    auto stdSortTest = makeMeasurementTool([](std::vector<int>& v){std::sort(v.begin(), v.end());}, randomTestGenerator, 1000, 50000);
    for (const auto& el : stdSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
    auto mergeSortTest = makeMeasurementTool([](std::vector<int>& v){mergeSort(v.begin(), v.end());}, randomTestGenerator, 1000, 50000);
    for (const auto& el : mergeSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
    auto quickSortTest = makeMeasurementTool(sort::quicksort_iter<int>, randomTestGenerator, 10, 50);
    for (const auto& el : quickSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
    return 0;
}