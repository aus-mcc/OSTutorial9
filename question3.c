#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

static int x[100000000];

int main(int argc, char **argv){
    
    int i;
    int norm;

    omp_get_wtime();
    for(i=0; i<100000000; i++){
        x[i] = rand() % 100;
        norm += fabs(x[i]);
    }
    omp_get_wtime();

    printf("norm is equal to: %s", norm);

    #pragma omp parallel for
    #ifdef _OPENMP for
    
    omp_get_wtime();
    for(int j=0; j<100000000; j++){
        x[i] = rand() % 100;
        norm += fabs(x[i]);
    }
    omp_get_wtime();
    
    reduction(+:norm);
    
    printf("norm is equal to: %s", norm);
    
    #endif
}
