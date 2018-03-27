#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc, char *argv){

    //Initializes first matrix values
    int a[100][100] = { {3,2,1},
                        {1,4,5}
                      };

    //Initializes second matrix values
    int b[100][100] = {{2,2,2},
                       {1,3,5},
                       {1,2,3}
                      };

    int x[100][100] = {0};

    
    int i;
    int j;
    int k;
    #pragma omp parallel for collapse(3)
    #ifdef _OPENMP
    for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            for(k=0; k<100; k++){   
                x[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    //Prints the resulting matrix
    printf("%d ",x[0][0]);
    printf("%d ",x[0][1]);
    printf("%d\n",x[0][2]);
    printf("%d ",x[1][0]);
    printf("%d ",x[1][1]);
    printf("%d ",x[1][2]);
    #endif
} 
