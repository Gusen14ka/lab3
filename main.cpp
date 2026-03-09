#include "goldRatio.hpp"
#include "bruteforce.hpp"
#include <iomanip>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double a = 0.3;
    double b = 1;
    std::vector<double> eps = {0.1, 0.01, 0.001};
    for(auto& ep: eps){
        int per = static_cast<int>(-std::log10(ep));
        std::cout << "Eps: " << std::fixed << std::setprecision(per) << ep << std::endl;
        std::cout << "-Равномерный поиск-" << std::endl;
        auto res = bruteforce(a, b, ep);
        std::cout  << res << " ± " << ep << std::endl;
        std::cout << std::endl;
        std::cout << "-Золотое сечение-" << std::endl;
        res = goldRatio(a, b, ep);
        std::cout << std::fixed << std::setprecision(per) << res << " ± " << ep << std::endl;
        std::cout << std::endl;
    }
    return 0;
}