#include "MeasurementTool.h"
#include "testGenerators.h"
#include "mergeSort.h"
#include "quick_iter.hpp"

int main() 
{
    auto stdSortTest = makeMeasurementTool([](std::vector<int>& v){std::sort(v.begin(), v.end());}, randomTestGenerator, 1000, 50000, 100000);
    std::cout<<"stdSort\t\t";
    for (const auto& el : stdSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
    std::cout<<"oldMergeSort\t";
    auto mergeSortOldTest = makeMeasurementTool([](std::vector<int>& v){mergeSortOld(v.begin(), v.end());}, randomTestGenerator, 1000, 50000, 100000);
    for (const auto& el : mergeSortOldTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
    std::cout<<"mergeSort\t";
    auto mergeSortTest = makeMeasurementTool([](std::vector<int>& v){mergeSort(v.begin(), v.end());}, randomTestGenerator, 1000, 50000, 100000);
    for (const auto& el : mergeSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
    std::cout<<"quickSortIter\t";
    auto quickSortTest = makeMeasurementTool(sort::quicksort_iter<int>, randomTestGenerator, 1000, 50000, 100000);
    for (const auto& el : quickSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
    return 0;
}