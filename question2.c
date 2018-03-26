#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]){
    
    // Command line arg set to being amount of threads
    int thrdCount = argv[1];
    // In OPENMP set the thread count to what's entered.
    #ifdef _OPENMP
    omp_set_num_threads(thrdCount);
    #endif


}