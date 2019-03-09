#ifndef TESTGENERATORS_H_
#define TESTGENERATORS_H_

#include <vector>
#include <random>
#include <limits>

std::random_device rd;
std::mt19937 mt;
std::uniform_int_distribution<int> rng;

std::vector<int> randomTestGenerator(const std::size_t& sizeOfTest)
{
    std::vector<int> ret(sizeOfTest);
    for(int& n : ret)
    {
        n = rng(mt);
    }
    return ret;
}

std::vector<int> sortedTestGenerator(const std::size_t& sizeOfTest)
{
    std::vector<int> ret = randomTestGenerator(sizeOfTest);
    std::sort(ret.begin(), ret.end());
    return ret;
}

std::vector<int> reversedSortedTestGenerator(const std::size_t& sizeOfTest)
{
    std::vector<int> ret = sortedTestGenerator(sizeOfTest);
    std::sort(ret.begin(), ret.begin() + ret.size() / 2);
    std::sort(ret.begin() + ret.size() / 2 + 1, ret.end());
    return ret;
}

std::vector<int> vShapedTestGenerator(const std::size_t& sizeOfTest)
{
    std::vector<int> ret = randomTestGenerator(sizeOfTest);
    std::sort(ret.begin(), ret.end());
    return ret;
}

#endif /* !TESTGENERATORS_H_ */
