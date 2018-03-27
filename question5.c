#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]){
    int thrdCount = atoi(argv[1]);
    int thread_num;

    #ifdef _OPENMP
    omp_set_num_threads(thrdCount)
    #endif
}