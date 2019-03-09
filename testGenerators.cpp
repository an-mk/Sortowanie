#include "testGenerators.h"

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> rng(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());