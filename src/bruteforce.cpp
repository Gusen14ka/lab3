#include "bruteforce.hpp"
#include "function.hpp"
#include <cstddef>
#include <cmath>
#include <iostream>

size_t bruteforceIter(double a, double b, double eps){
    return static_cast<size_t>(std::ceil((b - a) / eps - 1));
}

std::pair<double, double> bruteforce(double a, double b, double eps, double &inter, size_t &calls){
    size_t n = bruteforceIter(a, b, eps);
    double delta = (b - a) / (n + 1);
    double x = a + delta;
    double f_min = func(x);
    double x_min = x;
    size_t called = 1;
    for (size_t i = 2; i <= n; ++i) {
        x = a + i * delta;
        double f_x = func(x);
        if (f_x < f_min) {
            f_min = f_x;
            x_min = x;
        }
        ++called;
    }
    std::cout << "Вызвано раз: " << called << std::endl;
    std::cout << "Теоретически вызвано раз: " << bruteforceIter(a, b, eps) << std::endl;
    inter = delta;
    calls = called;
    return {x_min, f_min};

}