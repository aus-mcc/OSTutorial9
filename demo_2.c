#include <stdio.h>
#include <omp.h>
int main (int argc, char *argv[])
{
    int num = 0; // Watch out for race conditions!
    int thread_num, nthreads = 16;
    //Only printed when -openmp is used in compilation
    //Sets the number of threads that will be used in next parallel region
    #ifdef _OPENMP
    omp_set_num_threads(nthreads);
    #endif
    printf("Testing OpenMP, you should see each thread print...\n");
    //Creates a parallel region (executed with multiple threads) where it will return thread number of the thread 
    #pragma omp parallel
    {
        thread_num = omp_get_thread_num();
        
        //Only 1 thread will be able to use variables in the critical section 
        #pragma omp critical
        {
            //Only will run if -openmp is used in compilation 
            //num variable is incremented by 1 and printf statement is printed
            #ifdef _OPENMP
            num += 1; // THREAD SAFE INCREMENT
            printf("This thread = %d, num = %d\n", thread_num, num);
            #endif
        }
    }
    return 0;
}
