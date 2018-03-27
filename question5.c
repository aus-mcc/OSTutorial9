#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define n 100000000
double dx = 1/(n+1);


int main(int argc, char *argv[]){

    FILE *fp;
    fp = fopen("calculation.txt","w");

    int thrdCount = atoi(argv[1]);
    int thread_num;
    double x=0;
    double y=0;

    #ifdef _OPENMP
    omp_set_num_threads(thrdCount);
    #endif

    #pragma omp parallel for private(x,y)
    for(int i=0;i<=n;i++){
        x = i*dx;
        y = exp(x)*cos(x)*sin(x)*sqrt(5*x+6.0);
        #pragma omp critical
        {
            #ifdef _OPENMP
                if(i%1000000==0){
                    fprintf(fp, "Calculation Number: %d, X = %f, Y = %f\n", i,x,y);
                }
            #endif
        }
    }
}