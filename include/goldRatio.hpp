#pragma once
#include <cstddef>
#include <utility>
constexpr double phi = 0.618033988749; // 12 знаков

std::pair<double, double> goldRatio(double a, double b, double eps, double &inter, size_t &calls);

size_t goldRatioIter(double a, double b, double eps);