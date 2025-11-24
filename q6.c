#include <stdio.h>
#include <omp.h>
int fib(int n) {
    int x, y;
    if (n <= 1)
        return n;
    #pragma omp task shared(x)
    x = fib(n - 1);
    #pragma omp task shared(y)
    y = fib(n - 2);
    #pragma omp taskwait        // wait for both tasks to finish
    return x + y;
}
int main() {
    int n = 10;
    int result;
    #pragma omp parallel
    {
        #pragma omp single      // only one thread starts the recursion
       {
            result = fib(n);
        }
    }
    printf("Fibonacci(%d) = %d\n", n, result);
    return 0;
}

Output
Fibonacci(10) = 55
