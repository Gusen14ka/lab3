#pragma once
#include <cstddef>
constexpr double phi = 0.618033988749; // 12 знаков

double goldRatio(double a, double b, double eps);

size_t goldRatioIter(double a, double b, double eps);