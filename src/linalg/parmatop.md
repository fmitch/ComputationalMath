# 2D Matrix/Vector Operations
## Table of Contents
1.  [parMatMul](#function-name-parmatmul)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
2. [parMatVecMul](#function-name-parmatvecmul)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)

# Function Name: parMatMul

## Description: 
Multiply two matrices, A and B. A must be MxN and B must be NxP in dimensions.
Uses OpenMP to parallelize operations.

## Input:
`double* A` - A pointer to a 2D array of elements
`double* B` - A pointer to a 2D array of elements
`int M` - The number of rows in A
`int N` - The number of columns in A and the number of rows in B
`int P` - The number of columns in B

## Output:
Returns the product of the two matrices.

## Code:
```c
#include <omp.h>

double* parMatMul(double* A, double* B, int M, int N, int P){
    double* C = new double[M*N];
    double dot;
    #pragma omp parallel for
    for (int i = 0; i<M; i++)
        for ( int k=0; k<P; k++)
        {
            dot = 0;
            for (int j=0; j<N; j++)
                dot += (*((A+i*N) + j)) * (*((B+j*P) + k));
            *((C+i*P) + k)  = dot;
        }
    return C;
}
```

## Example:
```c
    double mat2x3[2][3] = {{1.0, 2.0, 2.0},
                            {1.0,1.0,2.0}};
    double mat3x2[3][2] = {{1.0, 2.0}, 
                            {2.0,1.0},
                            {1.0,2.0}};
    printMat(parMatMul( (double*) mat2x3, (double*) mat3x2,2, 3, 2), 2, 2);
```
Output:
``` 
7.000000  8.000000 
5.000000  7.000000 
```

# Function Name: matVecMul

## Description: 
Calculate the product of a matrix and a vector. The matrix is MxN, and the vector must be Nx1. Uses OpenMP to parallelize operations.

## Input:
`double* A` - A pointer to a 2D array of elements
`double* v` - A pointer to an array of elements
`int M` - The number of rows in the matrix 
`int N` - The number of columns in the matrix 

## Output:
Return the product of A and v. 

## Code:
```c
double* parMatVecMul(double* A, double* v, int M, int N){
    double* C = new double[M];
    double dot;
    #pragma omp parallel for
    for (int i = 0; i<M; i++)
    {
        dot = 0;
        for (int j=0; j<N; j++)
            dot += *((A+i*N) + j) * v[j];
        C[i] = dot;
    }
    return C;
}
```

## Example:
```c
double mat2x3[2][3] = {{1.0, 2.0, 2.0},
						{1.0,1.0,2.0}};
double vec3[3] = { 1.0, 1.0, 2.0};
printVec(parMatVecMul( (double*) mat2x3,vec3, 2, 3),2);
```
Output:
```
7.000000 
6.000000 
```

### Author: 
Frost Mitchell

### Last edited:
2017-10-19

