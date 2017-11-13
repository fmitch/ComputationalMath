# Iterative Matrix Methods 
## Table of Contents
1. [Jacobi Iteration](#function-name-jacobi)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
2. [Gauss-Seidel Iteration](#function-name-gaussSeidel)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)
3. [Steepest Descent Iteration](#function-name-steepestDescent)
    1. [Description](#description-2)
    2. [Input](#input-2)
    3. [Output](#output-2)
    4. [Code](#code-2)
    5. [Example](#example-2)
4. [Conjugate Gradient Iteration](#function-name-conjugateGradient)
    1. [Description](#description-3)
    2. [Input](#input-3)
    3. [Output](#output-3)
    4. [Code](#code-3)
    5. [Example](#example-3)
 
## Function Name: jacobi

## Description:
Uses the Jacobi method of iteration to solve the linear system Ax = b.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* b` - A pointer to an array containing the solution b to Ax=b.  
`int N` - The dimension of the square matrix A.
`int& count = 0` - A counter which will contain the number of iterations performed.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`double* xk` - A pointer to the solution x for Ax=b. Once the error between two 
iterations of x is less than the tolerance, `xk` is returned.

## Code:
```c
#include <math.h>

double* jacobi(double* A, double* b, int N, int& count, long double tol, int maxIter){
    double LUx;
    count = 0;
    double* xk = new double[N];
    double* xkk = new double[N];
    long double error = tol * 100;
    double diff;
    for( int i = 0; i < N; i++)
        xk[i] = b[i];
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



## Function Name: gaussSeidel

## Description:
Use the Gauss-Seidel method of iteration to solve the linear system Ax = b.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* b` - A pointer to an array containing the solution b to Ax=b.  
`int N` - The dimension of the square matrix A.
`int& count = 0` - A counter which will contain the number of iterations performed.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`double* xk` - A pointer to the solution x for Ax=b. Once the error between two 
iterations of x is less than the tolerance, `xk` is returned.

## Code:
```c
#include <math.h>

double* gaussSeidel(double* A, double* b, int N, int& count, long double tol, int maxIter){
    double Lx;
    count = 0;
    double* xk = new double[N];
    double* xkk = new double[N];
    long double error = tol*100;
    double sum, diff;
    for( int i = 0; i < N; i++)
    {
        xk[i] = b[i];
        xkk[i] = b[i];
    }
    while(count < maxIter && error > tol){
        diff = 0;
        for( int i = 0; i < N; i++){
            Lx = 0;
            for ( int j = 0; j < i; j++)
                Lx += *((A+i*N) + j) * xk[j];
            xkk[i]  = (b[i] - Lx) ;
        }
        for( int i = N-1; i >= 0; i--){
            sum = 0;
            for ( int j = i+1; j < N; j++)
                sum += *((A+ i*N) + j) * xkk[j];
            xkk[i] = (xkk[i] - sum) / *((A+i*N) + i);
        }
        for( int i = 0; i < N; i++){
            diff += fabs(xkk[i] - xk[i]);
            xk[i] = xkk[i];
        }
        error = diff*diff;
        count++;
    }
    return xk;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    double* x;
    x = gaussSeidel((double*) A, b, 4);
    printVec(x, 4);
    return 0;
}

```
OUTPUT:
```
0.161250
0.298965
0.267067
0.368136
```


## Function Name: steepestDescent 

## Description:
Use the steepest descent or gradient method of iteration to solve the linear system Ax = b.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* b` - A pointer to an array containing the solution b to Ax=b.  
`int N` - The dimension of the square matrix A.
`int& count = 0` - A counter which will contain the number of iterations performed.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`double* xk` - A pointer to the solution x for Ax=b. Once the dot product
 of the residual vector is less than the tolerance squared times the dot product
 of the vector b, `xk` is returned.

## Code:
```c
#include "matop.hpp"
#include <math.h>

double* steepestDescent(double* A, double* b, int N, int& count, long double tol, int maxIter){
    double* r = new double[N];
    double* xk = new double[N];
    double* Ar = new double[N];
    Ar = matVecMul(A, b, N, N);
    for (int i = 0; i < N; i++){
        r[i] = b[i] - Ar[i];
        xk[i] = b[i];
    }
    double delta_k = dotProduct(r, r, N);
    double b_delta = dotProduct(b, b, N);
    double error = 100 * tol;
    double alpha;
    count = 0;
    while( delta_k > tol * tol * b_delta && count < maxIter){
        Ar = matVecMul(A, r, N, N);
        alpha = delta_k/(dotProduct(r, Ar, N));
        for (int i = 0; i < N; i++){
            xk[i] = xk[i] + alpha*r[i];
            r[i] = r[i] - alpha*Ar[i];
        }
        delta_k = dotProduct(r, r, N);
        count++;
    }
    return xk;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    double* x;
    x = steepestDescent((double*) A, b, 4);
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


## Function Name: conjugateGradient

## Description:
Use the conjugate gradient method of iteration to solve the linear system Ax = b.
If A is a symmetric, positive definite matrix, this method converges much faster 
on average than any of the other iterative matrix methods.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* b` - A pointer to an array containing the solution b to Ax=b.  
`int N` - The dimension of the square matrix A.
`int& count = 0` - A counter which will contain the number of iterations performed.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`double* xk` - A pointer to the solution x for Ax=b. Once the dot product
 of the residual vector is less than the tolerance squared times the dot product
 of the vector b, `xk` is returned.

## Code:
```c
#include "matop.hpp"
#include <math.h>

double* conjugateGradient(double* A, double* b, int N, int& count, long double tol, int maxIter){
    double* r = new double[N];
    double* p = new double[N];
    double* xk = new double[N];
    double* Ap = new double[N];
    Ap = matVecMul(A, b, N, N);
    for (int i = 0; i < N; i++){
        r[i] = b[i] - Ap[i];
        p[i] = r[i];
        xk[i] = b[i];
    }
    double delta_k = dotProduct(r, r, N);
    double b_delta = dotProduct(b, b, N);
    double error = 100 * tol;
    double alpha, delta_k1;
    count = 0;
    while( delta_k > tol * tol * b_delta && count < maxIter){
        Ap = matVecMul(A, p, N, N);
        alpha = delta_k/(dotProduct(p, Ap, N));
        for (int i = 0; i < N; i++){
            xk[i] = xk[i] + alpha*p[i];
            r[i] = r[i] - alpha*Ap[i];
        }
        delta_k1 = dotProduct(r, r, N);
        for (int i = 0; i < N; i++)
            p[i]= r[i] + delta_k1 / delta_k * p[i];
        delta_k = delta_k1;
        count++;
    }
    return xk;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    double* x;
    x = conjugateGradient((double*) A, b, 4);
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
2017-11-12
