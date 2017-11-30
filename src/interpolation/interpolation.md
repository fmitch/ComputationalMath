# Polynomial Interpolation
## Table of Contents
1. [Power Method](#function-name-dividedDifferenceCoefficients)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
2. [Power Method Pair](#function-name-newtonEvaluation)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)
 
## Function Name: dividedDifferenceCoefficients

## Description:
For a given data set of the form (x0,y1), calculate the divided difference table
for this data, and return the coefficients which will be used to give the Newton
form of the interpolating polynomial.
 
## Input:
`double* x` - A pointer to an array containing the abscissa points of the dataset
`double* y` - A pointer to an array containing the ordinate points of the dataset
`int size` - The length of the arrays x and y.
    
## Output:
`double* coeff` - The coefficients of the Newton form of the polynomial.

## Code:
```c
double* dividedDifferenceCoefficients(double* x, double* y, int size){
    double* coeff = new double[size];
    double f1, f2;
    double fhold;
    for (int i = 0; i < size; i++){
        coeff[i] = y[i];
    }
    int count = 1;
    for (int j = 0; j < size-1; j++){
        f1 = coeff[count-1];
        for (int i = count; i < size; i++){
            f2 = coeff[i];
            coeff[i] = (coeff[i]-f1) / (x[i] - x[i-count]);
            f1 = f2;
        }
        count++;
    }
    return coeff;
}
```


## Function Name: newtonEvalutation

## Description:
Given the coefficients of the Newton form of an interpolating polynomial and the 
dataset used to give the coefficients, calculate the values of the polynomial 
at a set of points.
 
## Input:
`double* guess` - A pointer to an array containing the points at which to evaluate the polynomial.
`int sizeGuess` - The length of the array of points to be evaluated.
`double* x` - A pointer to an array containing the abscissa points of the dataset
`double* coeff` - A pointer to an array containing the coefficients of the Newton polynomial.
`int sizeX` - The length of the arrays x and coeff.
    
## Output:
`double* values` - A pointer to the array of calculated values.

## Code:
```c
double* newtonEvaluation(double* guess, int sizeGuess, double* x, double* coeff, int sizeX){
    double* values = new double[sizeGuess];
    #pragma omp parallel for
    for (int i = 0; i < sizeGuess; i++){
        values[i] = 0;
        for (int j = sizeX-1; j > -1  ; j--)
            values[i] = values[i]*(guess[i] - x[j]) + coeff[j];
    }
    return values;
}
```

## Example:
```c
#include "interpolation.hpp"
#include <stdio.h>

int main(){
    double x[5] = {0,1,2,3,4};
    double xNear[5] = {0.01,1.01,2.01,3.01,4.01};
    double y[5] = {0,1,8,27,64};
    double* coeff = dividedDifferenceCoefficients(x, y, 5);
    double* values = newtonEvaluation(xNear, 5, x, coeff, 5);
    for (int i = 0; i < 5; i++)
        printf("%f \n", values[i]);
    return 0;
}
```
OUTPUT:
```
0.000001
1.030301
8.120601
27.270901
64.481201
```


### Author: 
Frost Mitchell

### Last edited:
2017-11-29
