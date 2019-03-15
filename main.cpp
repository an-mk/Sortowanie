#include "MeasurementTool.h"
#include "testGenerators.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "quick_iter.hpp"
#include "heapsort.hpp"
#include "selection.hpp"
#include "insertion.hpp"


int main() 
{
    MesurementLab<1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000> lab;
    lab.setTestGenerator(randomTestGenerator);
    lab(std::sort, "stdSort ");
    lab(sort::mergeSort, "mergeSort");
    lab(sort::quickSort, "quickSort");
    lab(sort::quicksort_iter, "quickSortIter");
    lab(sort::heapsort, "heapsort");
    lab(sort::selectionSort, "selectionSort");
    lab(sort::insertionSort, "insertionSort");
    return 0;
}