4. [Conjugate Gradient Iteration](#function-name-conjugateGradient)
    1. [Description](#description-3)
    2. [Input](#input-3)
    3. [Output](#output-3)
    4. [Code](#code-3)
    5. [Example](#example-3)
 

## Function Name: conjugateGradient

## Description:
Use the conjugate gradient method of iteration to solve the linear system Ax = b.
If A is a symmetric, positive definite matrix, this method converges much faster 
on average than any of the other iterative matrix methods.
 
## Input:
*  `double* A` - A pointer to a square, 2D array of doubles   
*  `double* b` - A pointer to an array containing the solution b to Ax=b.    
*  `int N` - The dimension of the square matrix A.  
*  `int& count = 0` - A counter which will contain the number of iterations performed.  
*  `long double tol = 1e-8` - The tolerance for convergence.  
*  `int maxIter = 1e6` - The maximum number of iterations performed before the method exits.  
    
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
2017-12-2
