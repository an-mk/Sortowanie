#ifndef MEASUREMENTTOOL_H_
#define MEASUREMENTTOOL_H_

#include <cstddef>
#include <chrono>
#include <algorithm>
#include <array>
#include <iostream>

template <class FunctionToTest, class TestGenerator, class... SizesOfTests>
class MeasurementTool
{
public:
    MeasurementTool(FunctionToTest f, TestGenerator t, SizesOfTests... numbers)
    {
        std::size_t i = 0, j;
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        for (const auto& result : {numbers...})
        {
            j = iterationsOfTests;
            results[i] = std::chrono::microseconds(0);
            while (j--)
            {
                auto testData = t(result);
                start = std::chrono::high_resolution_clock::now();
                f(testData);
                end = std::chrono::high_resolution_clock::now();
                if (!std::is_sorted(std::begin(testData), std::end(testData)))
                    std::cerr<<"Sort failed\n";
                results[i] += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            }
            results[i] /= iterationsOfTests;
            i++;
        }
    }
    std::array<std::chrono::microseconds, sizeof...(SizesOfTests)>& getResults() { return results; }
private:
    std::array<std::chrono::microseconds, sizeof...(SizesOfTests)> results;
    static constexpr std::size_t iterationsOfTests = 100;
};

template <class FunctionToTest, class TestGenerator, class... SizesOfTests>
decltype(auto) makeMeasurementTool(FunctionToTest f, TestGenerator t, SizesOfTests... numbers)
{
    return MeasurementTool<FunctionToTest, TestGenerator, SizesOfTests...>(f, t, numbers...);
}


#endif /* !MEASUREMENTTOOL_H_ */
