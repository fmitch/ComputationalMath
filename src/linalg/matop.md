# 2D Matrix/Vector Operations
## Table of Contents
1. [matAdd](#function-name-matAdd)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
2. [matSub](#function-name-matSub)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)
3. [scaleMat](#function-name-scaleMat)
    1. [Description](#description-2)
    2. [Input](#input-2)
    3. [Output](#output-2)
    4. [Code](#code-2)
    5. [Example](#example-2)
4. [matMul](#function-name-matMul)
    1. [Description](#description-3)
    2. [Input](#input-3)
    3. [Output](#output-3)
    4. [Code](#code-3)
    5. [Example](#example-3)
5. [matVecMul](#function-name-matVecMul)
    1. [Description](#description-4)
    2. [Input](#input-4)
    3. [Output](#output-4)
    4. [Code](#code-4)
    5. [Example](#example-4)
6. [dotProduct](#function-name-dotProduct)
    1. [Description](#description-5)
    2. [Input](#input-5)
    3. [Output](#output-5)
    4. [Code](#code-5)
    5. [Example](#example-5)

# Function Name: matAdd 

## Description: 
Add two 2D matrices with the same dimensions.

## Input:
*  `double* A` - A pointer to a 2D array of elements  
*  `double* B` - A pointer to a 2D array of elements  
*  `int M` - The number of rows in the matrix   
*  `int N` - The number of columns in the matrix   

## Output:
Returns the sum of the two matrices, element wise.
 
## Code:
```c
double* matAdd(double* A, double* B, int M, int N){
    double* C = new double[M*N];
    for (int i=0; i< M; i++)
        for (int j = 0; j < N; j++)
            *((C+i*N) + j) = *((A+i*N) + j) + *((B+i*N) + j);
    return C;
}
```

## Example:
```c
double mat2x3[2][3] = {{1.0, 2.0, 2.0},
						{1.0,1.0,2.0}};
double mat2x3B[2][3] = {{2.0, 1.0, 1.0},
						{2.0,1.0,1.0}};
printMat(matAdd( (double*) mat2x3, (double*) mat2x3B,2, 3), 2, 3);

```

Output:
```
3.000000  3.000000  3.000000 
3.000000  2.000000  3.000000 
```

# Function Name: matSub 

## Description: 
Calculate the difference between two matrices, A - B. 

## Input:
`double* A` - A pointer to a 2D array of elements  
`double* B` - A pointer to a 2D array of elements  
`int M` - The number of rows in the matrix   
`int N` - The number of columns in the matrix   

## Output:
Returns the difference between of the two matrices, A - B.

## Code:
```c
double* matSub(double* A, double* B, int M, int N){
    double* C = new double[M*N];
    for (int i=0; i< M; i++)
        for (int j = 0; j < N; j++)
            *((C+i*N) + j) = *((A+i*N) + j) - *((B+i*N) + j);
    return C;
}
```

## Example:
```c
double mat2x3[2][3] = {{1.0, 2.0, 2.0},
                        {1.0,1.0,2.0}};
double mat2x3B[2][3] = {{2.0, 1.0, 1.0},
						{2.0,1.0,1.0}};
printMat(matSub((double*)mat2x3,(double*)mat2x3B,2, 3), 2, 3);
```
Output:
```
 -1.000000  1.000000  1.000000 
 -1.000000  0.000000  1.000000 
```

# Function Name: scaleMat

## Description: 
Multiply a matrix A by a constant scalar, a double. 

## Input:
*  `double* A` - A pointer to a 2D array of elements  
*  `int M` - The number of rows in the matrix   
*  `int N` - The number of columns in the matrix   
*  `double scalar` - A real, constant scalar to multiply each element of A by.   

## Output:
Returns the matrix multiplied by the constant scalar.

## Code:
```c
double* scaleMat(double* A, int N, int M, double scalar){
    double* C = new double[cols][rows];
    for (int j = 0; j < cols; j++)
        for (int i=0; i< rows; i++)
            C[i][j] = A[i][j] * scalar;
    return C;
}
```

## Example:
```c
double mat2x3B[2][3] = {{2.0, 1.0, 1.0},
						{2.0,1.0,1.0}};
printMat(scaleMat( (double*) mat2x3B,2, 3, 0.5), 2, 3);
```
Output:
```
1.000000  0.500000  0.500000 
1.000000  0.500000  0.500000 
```

# Function Name: matMul

## Description: 
Multiply two matrices, A and B. A must be MxN and B must be NxP in dimensions.

## Input:
*  `double* A` - A pointer to a 2D array of elements  
*  `double* B` - A pointer to a 2D array of elements  
*  `int M` - The number of rows in A  
*  `int N` - The number of columns in A and the number of rows in B  
*  `int P` - The number of columns in B  

## Output:
Returns the product of the two matrices.

## Code:
```c
double* matMul(double* A, double* B, int M, int N, int P){
    double* C = new double[M*N];
    double dot;
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
    printMat(matMul( (double*) mat2x3, (double*) mat3x2,2, 3, 2), 2, 2);
```
Output:
``` 
7.000000  8.000000 
5.000000  7.000000 
```

# Function Name: matVecMul

## Description: 
Calculate the product of a matrix and a vector. The matrix is MxN, and the vector must be Nx1.

## Input:
*  `double* A` - A pointer to a 2D array of elements  
*  `double* v` - A pointer to an array of elements  
*  `int M` - The number of rows in the matrix   
*  `int N` - The number of columns in the matrix   

## Output:
Return the product of A and v. 

## Code:
```c
double* matVecMul(double* A, double* v, int M, int N){
    double* C = new double[M];
    double dot;
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
printVec(matVecMul( (double*) mat2x3,vec3, 2, 3),2);
```
Output:
```
7.000000 
6.000000 
```

# Function Name: dotProduct

## Description: 
Calculate the dot product of two vectors with the same size.

## Input:
*  `double* v1` - A pointer to an array of elements  
*  `double* v2` - A pointer to an array of elements  
*  `int size` - The number of elements in the vector   
 
## Output:
Return the dot product of v1 and v2. 

## Code:
```c
double  dotProduct(double* v1, double* v2, int size){
    double out = 0;
    for (int i = 0; i < size; i++)
        out += v1[i] * v2[i];
    return out;
}
```

## Example:
```c
double vec3[3] = { 1.0, 1.0, 2.0};
printf(" %f \n\n", dotProduct(vec3, vec3, 3));
```
Output:
```
6.000000 
```

### Author: 
Frost Mitchell

### Last edited:
2017-12-2

