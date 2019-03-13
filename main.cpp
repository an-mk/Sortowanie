#include "MeasurementTool.h"
#include "testGenerators.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "quick_iter.hpp"
#include "heapsort.hpp"
#include "selection.hpp"

#define TESTS 10000, 50000, 100000

int main() 
{
    auto stdSortTest = makeMeasurementTool([](std::vector<int>& v){std::sort(v.begin(), v.end());}, randomTestGenerator, TESTS);
    std::cout<<"stdSort\t\t";
    for (const auto& el : stdSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;

    std::cout<<"mergeSort\t";
    auto mergeSortTest = makeMeasurementTool([](std::vector<int>& v){sort::mergeSort(v.begin(), v.end());}, randomTestGenerator, TESTS);
    for (const auto& el : mergeSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;

    std::cout<<"quickSort\t";
    auto quickSortTest = makeMeasurementTool([](std::vector<int>& v){sort::quickSort(v.begin(), v.end());}, randomTestGenerator, TESTS);
    for (const auto& el : quickSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;

    std::cout<<"quickSortIter\t";
    auto quickSortIterTest = makeMeasurementTool(sort::quicksort_iter<int>, randomTestGenerator, TESTS);
    for (const auto& el : quickSortIterTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;

    std::cout<<"heapsort\t";
    auto heapSortTest = makeMeasurementTool([](std::vector<int>& v){sort::heapsort(v.begin(), v.end());}, randomTestGenerator, TESTS);
    for (const auto& el : heapSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;
	
	std::cout<<"selectionSort\t";
    auto selectionSortTest = makeMeasurementTool([](std::vector<int>& v){sort::selectionSort(v.begin(), v.end());}, randomTestGenerator, TESTS);
    for (const auto& el : selectionSortTest.getResults())
        std::cout<<el.count()<<" ";
    std::cout<<std::endl;


    return 0;
}