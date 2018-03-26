#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[]){
    clock_t  begin = clock();
    // Command line arg set to being amount of threads
    int thrdCount = atoi(argv[1]);
    int thread_num;
    // In OPENMP set the thread count to what's entered.
    #ifdef _OPENMP
    omp_set_num_threads(thrdCount);
    #endif

    int n = 100000000; // n = 100,000,000

    double y[n];

    double dx = 1/(n+1);

    #pragma omp parallel
    {
        thread_num = omp_get_thread_num();

        #pragma omp for
        
            for(int i=0;i<=n;i++){
              double x = i*dx; 
              y[i] = exp(x)*cos(x)*sin(x)*sqrt(5*x+6);
            }
    }
    clock_t end = clock();
    double timetaken = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("%f\n", timetaken);
}