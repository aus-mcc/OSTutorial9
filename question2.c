#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>



#define n 100000000 // n = 100,000,000


double y[n];
double dx = 1/(n+1);


double calc(int count){
    return count*dx;
}


int main(int argc, char *argv[]){
    clock_t  begin = clock();
    // Command line arg set to being amount of threads
    int thrdCount = atoi(argv[1]);
    int thread_num, x;
    // In OPENMP set the thread count to what's entered.
    #ifdef _OPENMP
    omp_set_num_threads(thrdCount);
    #endif

    #pragma omp parallel for private(x)
    for(int i=0;i<=n;i++){

        double x = calc(i);
        y[i] = exp(x)*cos(x)*sin(x)*sqrt(5*x+6);
            
    }
    clock_t end = clock();
    double timetaken = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("%f\n", timetaken);
}