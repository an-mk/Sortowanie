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
    MesurementLab<20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160> lab;


    //lab.setTestGenerator(randomTestGenerator);
    //lab(sort::heapsort, "losowa");
    //lab.setTestGenerator(sortedTestGenerator);
    //lab(sort::heapsort, "rosnaca");
    //lab.setTestGenerator(reversedSortedTestGenerator);
    //lab(sort::heapsort, "malejaca");
    //lab.setTestGenerator(constTestGenerator);
    //lab(sort::heapsort, "stala");
    //lab.setTestGenerator(vShapedTestGenerator);
    //lab(sort::heapsort, "v-ksztaltna");

    
    lab.setTestGenerator(vShapedTestGenerator);
    lab(sort::insertionSort, "Insertion Sort");
    lab(sort::selectionSort, "SelectionSort");
    lab(sort::heapsort, "Heap Sort");
    lab(sort::mergeSort, "Merge Sort");
    return 0;
}