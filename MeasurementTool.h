#ifndef MEASUREMENTTOOL_H_
#define MEASUREMENTTOOL_H_

#include <cstddef>
#include <chrono>
#include <algorithm>
#include <array>
#include <vector>
#include <iostream>

template <typename T>
struct getArity
{
    constexpr static int value = getArity<decltype(&T::operator())>::value;
};

template <typename R, typename... Args>
struct getArity<R(*)(Args...)>
{
    constexpr static int value = sizeof...(Args);
};

template <typename R, typename C, typename... Args>
struct getArity<R(C::*)(Args...)>
{
    constexpr static int value = sizeof...(Args);
};

template <typename R, typename C, typename... Args>
struct getArity<R(C::*)(Args...) const>
{
    constexpr static int value = sizeof...(Args);
};

template<int N>
struct intHolder {};


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
    MeasurementTool(intHolder<1>, FunctionToTest f, TestGenerator t, SizesOfTests... numbers)
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
    MeasurementTool(intHolder<2>, FunctionToTest f, TestGenerator t, SizesOfTests... numbers)
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
                f(std::begin(testData), std::end(testData));
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
    return MeasurementTool<FunctionToTest, TestGenerator, SizesOfTests...>(intHolder<getArity<FunctionToTest>::value>{}, f, t, numbers...);
}

template <int... SizesOfTests>
class MesurementLab
{
public:
    void operator()(void(*f)(std::vector<int>::iterator, std::vector<int>::iterator), const char* str)
    {
        process(f, str);
    }
    void operator()(void(*f)(std::vector<int>&), const char* str)
    {
        process(f, str);
    }
private:
    template <class T>
    void process(T f, const char* str)
    {
        auto stdSortTest = makeMeasurementTool(f, randomTestGenerator, SizesOfTests...);
        std::cout<<str<<"\t\t";
        for (const auto& el : stdSortTest.getResults())
        std::cout<<el.count()<<" ";
        std::cout<<std::endl;
    }
    std::vector<int>(*testGenerator)(const std::size_t& sizeOfTest) = nullptr;
};

#endif /* !MEASUREMENTTOOL_H_ */
