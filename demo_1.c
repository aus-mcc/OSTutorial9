#include <stdio.h>
#include <omp.h>
int main (int argc, char *argv[])
{
    //Will be printed everytime the program is compiled
    printf("This statement will always print.\n");
    //This part of the program will only print if -fopenmp is used in compilation. Everything after the #endif will be printed everytime program is compiled.
    #ifdef _OPENMP
    printf("This statement will only print when compiled with \"-fopenmp\"\n");
    #endif
    return 0;
}
