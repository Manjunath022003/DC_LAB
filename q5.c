#include <stdio.h>
#include <omp.h>
int main() {
    int n = 10;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    int i;   // required for private(i)
    #pragma omp parallel for private(i) reduction(+:sum)
    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("Parallel Sum = %d\n", sum);
    return 0;
}

Output
Parallel Sum = 55
