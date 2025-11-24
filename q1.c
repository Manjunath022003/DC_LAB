#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Identify which process you are
    if(rank == 0) {
        long long number = 77770778589LL;       // Data to send (use long long)
        MPI_Send(&number, 1, MPI_LONG_LONG, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent number %lld to Process 1.\n", number);
    }
    else if(rank == 1) {
        long long received_number;
        MPI_Recv(&received_number, 1, MPI_LONG_LONG, 0, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received number %lld from Process 0.\n", received_number);
    }
    MPI_Finalize();
    return 0;
}

Output
Process 1 received number 77770778589 from Process 0.
Process 0 sent number 77770778589 to Process 1.
