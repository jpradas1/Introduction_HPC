#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <eigen3/Eigen/Dense>

void solve_eigensystem(int size, double &time);

int main(int arg, char **argv)
{
  const int M = atoi(argv[1]); // Matrix size
  const int R = atoi(argv[2]); // Repetitions
  // const int S = atoi(argv[3]); // seed
  // srand(S);

  double totaltime = 0, totaltime2 = 0, auxtime = 0;
  double mean_time = 0, sigma = 0;
  for(int irep = 0; irep < R; ++irep) {
    srand(irep+1);
    solve_eigensystem(M, auxtime);
    totaltime += auxtime;
    totaltime2 += auxtime*auxtime;
  }
  mean_time = totaltime/R;
  sigma = std::sqrt(R*(totaltime2/R - mean_time*mean_time)/(R-1));
  std::cout << M << "\t" << mean_time << "\t" << sigma << "\n";

 }

void solve_eigensystem(int size, double &time)
{
  double aux;
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);

  // walltime starts
  auto start = std::chrono::steady_clock::now();

  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(A);
  aux = eigensolver.eigenvalues()(0);

  // walltime ends
  auto end = std::chrono::steady_clock::now();

  std::clog << "The first eigenvalue of A is:\n" << aux << std::endl;
  std::chrono::duration<double> diff = end - start;
  time = diff.count();
}