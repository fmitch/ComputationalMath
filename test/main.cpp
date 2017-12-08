#include "src/linalg/norms.hpp"
#include "src/linalg/matop.hpp"
#include "src/linalg/parmatop.hpp"
#include "src/linalg/print.hpp"
#include "src/linalg/error.hpp"
#include "src/matrix_solutions/iterative.hpp"
#include "src/eigenvalues/power.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){
    double A[32][32];
    double guess[32];
    for (int i = 0; i < 32; i++)
    {
        A[i][i] = i+1;
        guess[i] = (double)rand()/INT_MAX;
    }
    printVec(guess, 32);
    double lambda = powerMethod((double*) A, guess, 32, 1e-8, 500);
    A[30][30] = 30;
    printf("A DONE\n \n \n");
    lambda = powerMethod((double*) A, guess, 32, 1e-8, 500);
    printf("B DONE\n \n \n");
/*
    double A[][4] = {{5, .1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[] = {1,2,3,4};
    double lambda = powerMethod((double*) A, b, 4, 1e-8, 500);
    
    */
    return 0;
}
