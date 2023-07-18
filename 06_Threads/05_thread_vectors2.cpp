#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex g_display_mutex;


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
    g_display_mutex.lock();
    result += x * x;    
    g_display_mutex.unlock();
}