# Power Methods for Finding Eigenvalues
## Table of Contents
1. [Power Method](#function-name-powerMethod)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
1. [Power Method](#function-name-powerMethodPair)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)
1. [Power Method](#function-name-inversePowerMethod)
    1. [Description](#description-2)
    2. [Input](#input-2)
    3. [Output](#output-2)
    4. [Code](#code-2)
    5. [Example](#example-2)
1. [Inverse Power Method Pair](#function-name-inversePowerMethodPair)
    1. [Description](#description-3)
    2. [Input](#input-3)
    3. [Output](#output-3)
    4. [Code](#code-3)
    5. [Example](#example-3)
 
## Function Name: powerMethod 

## Description:
Use the power method to approximate the largest eigenvalue of a real matrix A.
The power method is an interative method which approximates the eigenvalue by
multiplying a vector by A until the error in lambda is less than the tolerance.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* v0` - A pointer to an array containing a nonzero guess at the eigenvector.  
`int N` - The dimension of the square matrix A.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`double lambda` - The approximated largest eigenvalue. This value is returned once
the error between lambda in iterations is less that the tolerance.

## Code:
```c
#include "parmatop.hpp"
#include "matop.hpp"
#include "norms.hpp"
#include <omp.h>
#include <math.h>

double powerMethod(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parMatVecMul(A, v0, N, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parMatVecMul(A, x, N, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    delete [] x;
    return lambda;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    double lambda = powerMethod((double*) A, b, 4);
    printf("lambda = %f\n", lambda);
    return 0;
}

```
OUTPUT:
```
lambda 10.573567
```



## Function Name: powerMethodPair

## Description:
Use the power method to approximate the largest eigenvalue of a real matrix A.
The power method is an interative method which approximates the eigenvalue by
multiplying a vector by A until the error in lambda is less than the tolerance.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* v0` - A pointer to an array containing a nonzero guess at the eigenvector.  
`int N` - The dimension of the square matrix A.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`std::pair<double, double*> lambda` - A std::pair containing the approximated
largest eigenvalue and the pointer to the corresponding eigenvector.
This value is returned once
the error between lambda in iterations is less that the tolerance.

## Code:
```c
#include "parmatop.hpp"
#include "matop.hpp"
#include "norms.hpp"
#include <omp.h>
#include <utility>
#include <math.h>

std::pair<double, double*>  powerMethodPair(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parMatVecMul(A, v0, N, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parMatVecMul(A, x, N, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    return std::make_pair(lambda, x);;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    std::pair<double, double*> eigenpair = powerMethod((double*) A, b, 4);
    printf("lambda = %f\n", eigenpair.first);
    return 0;
}

```
OUTPUT:
```
lambda 10.573567
```


## Function Name: inversePowerMethod 

## Description:
Use the power method to approximate the smallest eigenvalue of a real matrix A.
The power method is an interative method which approximates the eigenvalue by
taking the action of the inverse of A on a vector until the error in lambda is 
less than the tolerance.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* v0` - A pointer to an array containing a nonzero guess at the eigenvector.  
`int N` - The dimension of the square matrix A.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`double lambda` - The approximated smallest eigenvalue. This value is returned once
the error between lambda in iterations is less that the tolerance.

## Code:
```c
#include "parmatop.hpp"
#include "matop.hpp"
#include "norms.hpp"
#include <omp.h>
#include <math.h>

double inversePowerMethod(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parJacobi(A, v0, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parJacobi(A, x, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    delete [] x;
    return 1/lambda;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    double lambda = inversePowerMethod((double*) A, b, 4);
    printf("lambda = %f\n", lambda);
    return 0;
}

```
OUTPUT:
```
lambda 4.940448
```



## Function Name: powerMethodPair

## Description:
Use the power method to approximate the smallest eigenvalue of a real matrix A.
The power method is an interative method which approximates the eigenvalue by
taking the action of the inverse of A on a vector until the error in lambda is 
less than the tolerance.
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`double* v0` - A pointer to an array containing a nonzero guess at the eigenvector.  
`int N` - The dimension of the square matrix A.
`long double tol = 1e-8` - The tolerance for convergence.
`int maxIter = 1e6` - The maximum number of iterations performed before the method exits..
    
## Output:
`std::pair<double, double*> lambda` - A std::pair containing the approximated
smallest eigenvalue and the pointer to the corresponding eigenvector.
This value is returned once
the error between lambda in iterations is less that the tolerance.

## Code:
```c
#include "parmatop.hpp"
#include "matop.hpp"
#include "norms.hpp"
#include <omp.h>
#include <utility>
#include <math.h>

std::pair<double, double*>  inversePowerMethodPair(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parMatVecMul(A, v0, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parJacobi(A, x, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    return std::make_pair(1/lambda, x);;
}
```

## Example:
```c
int main(){
    double A[4][4] = {{5,.1,.2,.3},{.2,6,.1,.4},{.8,.6,8.7,1},{.3,.1,.9,10}};
    double b[4] = { 1, 2, 3, 4};
    std::pair<double, double*> eigenpair = inversePowerMethod((double*) A, b, 4);
    printf("lambda = %f\n", eigenpair.first);
    return 0;
}

```
OUTPUT:
```
lambda 4.940448
```



### Author: 
Frost Mitchell

### Last edited:
2017-11-19
