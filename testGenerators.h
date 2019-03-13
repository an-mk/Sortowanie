#ifndef TESTGENERATORS_H_
#define TESTGENERATORS_H_

#include <vector>
#include <random>
#include <limits>

extern std::random_device rd;
extern std::mt19937 mt;
extern std::uniform_int_distribution<int> rng;

std::vector<int> randomTestGenerator(const std::size_t& sizeOfTest);
std::vector<int> sortedTestGenerator(const std::size_t& sizeOfTest);
std::vector<int> reversedSortedTestGenerator(const std::size_t& sizeOfTest);
std::vector<int> vShapedTestGenerator(const std::size_t& sizeOfTest);
std::vector<int> costTestGenerator(const std::size_t& sizeOfTest);

#endif /* !TESTGENERATORS_H_ */
