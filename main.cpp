#include "goldRatio.hpp"
#include "bruteforce.hpp"
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double a = 0.3;
    double b = 1;
    std::ofstream o1("o1.txt"), o2("o2.txt");
    for(int i = 1; i < 8; ++i){
        double eps = std::pow(10.0, -i);
        int per = static_cast<int>(-std::log10(eps));
        std::cout << "Eps: " << std::fixed << std::setprecision(per) << eps << std::endl;
        std::cout << "-Равномерный поиск-" << std::endl;
        double inter;
        size_t calls;
        auto res = bruteforce(a, b, eps, inter, calls);
        std::cout  << "x_min = " << res.first << " f_min " <<res.second << std::endl;
        o1 << eps << " " << inter << " " << calls << std::endl;
        std::cout << std::endl;
        std::cout << "-Золотое сечение-" << std::endl;
        res = goldRatio(a, b, eps, inter, calls);
        std::cout << "x_min = " << res.first << " f_min " << res.second << std::endl;
        o2 << eps << " " << inter << " " << calls << std::endl;
        std::cout << std::endl;
    }
    return 0;
}