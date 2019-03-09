#include "MeasurementTool.h"
#include "testGenerators.h"

int main() 
{
    auto stdSortTest = makeMeasurementTool([](std::vector<int>& v){std::sort(v.begin(), v.end());}, randomTestGenerator, 100000, 2000000);
    for (const auto& el : stdSortTest.getResults())
        std::cout<<el.count()<<" ";
    return 0;
}