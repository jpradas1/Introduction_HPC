#include <iostream>
#include <vector>
#include <thread>
#include <cmath>

void square(const int x, int & result);

int main() {
    int accum = 0;
    std::vector<std::thread> ths;
    for (int i = 1; i <= 20; i++) {
        ths.push_back(std::thread(&square, i, std::ref(accum)));
    }

    for (auto & th : ths) {
        th.join();
    }
    std::cout << "accum = " << accum << std::endl;
    return 0;
}

void square(int x, int &result) {
    for (int ii = 0; ii < 10000; ++ii){
        result += std::fabs(x*std::sin(x) + std::sqrt(x)/3.4455)/(M_PI+1);
    }
    // result = result/10000;
}