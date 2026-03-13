#pragma once

#include <cstddef>
#include <utility>

std::pair<double, double> bruteforce(double a, double b, double eps, double &inter, size_t &calls);
size_t bruteforceIter(double a, double b, double eps);