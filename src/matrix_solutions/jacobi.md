1. [Jacobi Iteration](#function-name-jacobi)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
 
## Function Name: jacobi

## Description:
Uses the Jacobi method of iteration to solve the linear system Ax = b.
 
## Input:
*  `double* A` - A pointer to a square, 2D array of doubles   
*  `double* b` - A pointer to an array containing the solution b to Ax=b.    
*  `int N` - The dimension of the square matrix A.  
*  `int& count = 0` - A counter which will contain the number of iterations performed.  
*  `long double tol = 1e-8` - The tolerance for convergence.  
*  `int maxIter = 1e6` - The maximum number of iterations performed before the method exits.  
*  `double* guess = nullptr` - A optional argument to a pointer for an initial guess, if the guess is not b.
    
## Output:
`double* xk` - A pointer to the solution x for Ax=b. Once the error between two 
iterations of x is less than the tolerance, `xk` is returned.

## Code:
```c
#include <math.h>

double* jacobi(double* A, double* b, int N, int& count, long double tol, int maxIter, double* guess){
    double LUx;
    count = 0;
    double* xk;
    if (guess == nullptr)
    {
        xk = new double[N];
        for( int i = 0; i < N; i++)
            xk[i] = b[i];
    }
    else
        xk = guess;
    double* xkk = new double[N];
    long double error = tol * 100;
    double diff;
    while(count < maxIter && error > tol){
        error = 0;
        for( int i = 0; i < N; i++){
            LUx = 0;
            for ( int j = 0; j < i; j++)
                LUx += *((A+i*N) + j) * xk[j];
            for ( int j = i+1; j < N; j++)
                LUx += *((A+i*N) + j) * xk[j];
            xkk[i]  = (b[i] - LUx) / *((A+i*N)+i);
            diff = fabs(xkk[i] - xk[i]);
            error += diff*diff;
        }
        for( int i = 0; i < N; i++)
            xk[i] = xkk[i];
        error = sqrt(error);
        count++;
    }
    delete[] xkk;
    return xk;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    double* x;
    x = jacobi((double*) A, b, 4);
    printVec(x, 4);
    return 0;
}

```
OUTPUT:
```
0.161250
0.298965
0.267067
0.368137
```


### Author: 
Frost Mitchell

### Last edited:
2017-12-2
