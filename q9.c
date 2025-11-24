#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void sequential_merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        sequential_merge_sort(arr, l, m);
        sequential_merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void parallel_merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            parallel_merge_sort(arr, l, m);

            #pragma omp section
            parallel_merge_sort(arr, m + 1, r);
        }
        merge(arr, l, m, r);
    }
}
int main() {
    int A[] = {5, 3, 8, 9, 1, 2, 6, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int seq[n];
    int par[n];
    for (int i = 0; i < n; i++) {
        seq[i] = A[i];
        par[i] = A[i];
    }
    // Sequential time
    double t1 = omp_get_wtime();
    sequential_merge_sort(seq, 0, n - 1);
    double t2 = omp_get_wtime();

    // Parallel time
    double t3 = omp_get_wtime();
    parallel_merge_sort(par, 0, n - 1);
    double t4 = omp_get_wtime();
    printf("\nSequential Time: %f seconds\n", t2 - t1);
    printf("Parallel Time:   %f seconds\n", t4 - t3);
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", par[i]);
    printf("\n");
    return 0;
}

Output
Sequential Time: 0.00001 seconds
Parallel Time:   0.00008 seconds
Sorted Array:
1 2 3 4 5 6 8 9
