#include <stdio.h>
#include <omp.h>
int main() {
    int sum = 0;
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        #pragma omp critical
        {
            sum += tid;
            printf("Thread %d updated sum to %d\n", tid, sum);
        }
    }
    printf("\nFinal Sum = %d\n", sum);
    return 0;
}

Output
Thread 0 updated sum to 0
Thread 1 updated sum to 1
Thread 3 updated sum to 4
Thread 2 updated sum to 6
Final Sum = 6
