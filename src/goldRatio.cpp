#include "goldRatio.hpp"
#include "function.hpp"
#include <cstddef>
#include <cmath>
#include <iostream>

size_t goldRatioIter(double a, double b, double eps){
    return static_cast<size_t>(std::ceil(std::abs(std::log(2 * eps / (b - a)) / std::log(phi)) ) + 2);
}

double goldRatio(double a, double b, double eps){
    double x1 = b - phi * (b - a);
    double x2 = a + phi * (b - a);
    double f1 = func(x1);
    double f2 = func(x2);
    size_t teor_calls = goldRatioIter(a, b, eps);
    size_t called = 2;
    while (std::abs(b - a) > 2 *eps) {
        if (f1 < f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - phi * (b - a);  
            f1 = func(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + phi * (b - a);
            f2 = func(x2);
        }
        ++called;
    }
    std::cout << "Вызвано раз: " << called << std::endl;
    std::cout << "Теоретически вызвано раз: " << teor_calls << std::endl;
    return (a + b) / 2;
}
