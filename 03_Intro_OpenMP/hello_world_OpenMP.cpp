#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
  std::cout << "BEFORE\n";
#pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    // std::cout << "Hello World " << thread_id << "\n";
    printf("%d Hello World \n", thread_id);
  }
  std::cout << "AFTER\n";
    
  return 0;
}