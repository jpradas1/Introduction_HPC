#include <iostream>
#include "mpi.h"

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int pid; /* rank of process */
    int np; /* number of processes */

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    // Generate a message with the process ID
    int message = pid;

    int tag = 0;

    if (pid != 0){
        int dest = 0;
        MPI_Send(&message, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
    }
    else { // pid == 0
        std::cout << "Hello from pid: " << message << " out of np: " << np << "\n";
        for (int iipid = 1; iipid < np; iipid++){
            MPI_Recv(&message, 1, MPI_INT, iipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            std::cout << "Hello from pid: " << message << " out of np: " << np << "\n";
        }
    }

    MPI_Finalize();
    return 0;
}