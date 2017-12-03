# Vector Error 
## Table of Contents
1. [vec1error](#function-name-vec1error)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
2. [vec2error](#function-name-vec2norm)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)
3. [vecInfError](#function-name-vecinfnorm)
    1. [Description](#description-2)
    2. [Input](#input-2)
    3. [Output](#output-2)
    4. [Code](#code-2)
    5. [Example](#example-2)

# Function Name: vec1error 

## Description: 
Calculate the error between two vectors, v1, and v2. Use the 1 norm for the error.

## Input:
*  `double* v1` - A pointer to an array of elements  
*  `double* v2` - A pointer to an array of elements  
*  `int size` - The number of elements in the array  

## Output:
Return the 1 norm of v1 - v2
 
## Code:
```c
double vec1error(double* v1, double* v2, int size){
    double* v = new double[size];
    for (int i = 0; i < size; i++)
        v[i] = v1[i] - v2[i];
    return vec1norm(v, size);
}
```


# Function Name: vec2error

## Description: 
Calculate the error between two vectors, v1, and v2. Use the 2 norm for the error.

## Input:
*  `double* v1` - A pointer to an array of elements  
*  `double* v2` - A pointer to an array of elements  
*  `int size` - The number of elements in the array  

## Output:
Return the 2 norm of v1 - v2

## Code:
```c
double vec2error(double* v1, double*> v2, int size){
    double* v = new double[size];
    for (int i = 0; i < size; i++)
        v[i] = v1[i] - v2[i];
    return vec2norm(v, size);
}
```

# Function Name: vecInfError

## Description: 
Calculate the error between two vectors, v1, and v2. Use the Infinity norm for the error.

## Input:
*  `double* v1` - A pointer to an array of elements  
*  `double* v2` - A pointer to an array of elements  
*  `int size` - The number of elements in the array  

## Output:
Return the Infinity norm of v1 - v2

## Code:
```c
double vecInfError(double* v1, double* v2, int size){
    double* v = new double[size];
    for (int i = 0; i < size; i++)
        v[i] = v1[i] - v2[i];
    return vecInfNorm(v, size);
}
```

### Author: 
Frost Mitchell

### Last edited:
2017-12-2

