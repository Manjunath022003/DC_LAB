#include <stdio.h>
#include <mpi.h>
int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank)
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int send_data[10];   // Only root will use full data
    int recv_value;      // Each process receives one value
    // Root initializes data
    if (rank == 0) {
        for (int i = 0; i < size; i++) {
            send_data[i] = (i + 1) * 10;   // 10, 20, 30, 40,...
        }
        printf("Root data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", send_data[i]);
        }
        printf("\n");
    }

    MPI_Scatter(send_data,      // send buffer (root)
                1, MPI_INT,     // 1 integer to each process
                &recv_value,    // each process receives one integer
                1, MPI_INT,
                0, MPI_COMM_WORLD);

    printf("Rank %d received %d\n", rank, recv_value);
    recv_value *= 2;
    int gathered[10];   // Root collects results here
    MPI_Gather(&recv_value, 1, MPI_INT,
               gathered,     1, MPI_INT,
               0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Gathered Result: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", gathered[i]);
        }
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}
Output
Root data: 10 20 30 40
Rank 0 received 10
Rank 1 received 20
Rank 2 received 30
Rank 3 received 40
Gathered Result: 20 40 60 80
