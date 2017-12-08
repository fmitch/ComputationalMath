# Polynomial Interpolation
1. [newtonInterpolation](#function-name-newtonInterpolation)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
 
## Function Name: newtonInterpolation

## Description:
For a given data set of the form (x0,y1), calculate the divided difference table
for this data, and use the coefficients to give the Newton form of the 
interpolating polynomial, and evaluate the polynomial at a given set of points.
 
## Input:
*  `double* x` - A pointer to an array containing the abscissa points of the dataset
*  `double* y` - A pointer to an array containing the ordinate points of the dataset
*  `int sizeX` - The length of the arrays x and y.  
*  `double* guess` - A pointer to an array containing the points to interpolate on.  
*  `int sizeGuess` - The length of the arrays of points to interpolate on.
    
## Output:
`double* ` - A pointer to an array of length `sizeGuess` containing the interpolated data.  

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

double* newtonInterpolation(double* x, double* y, int sizeX, double* guess, int sizeGuess){
    double* coeff = dividedDifferenceCoefficients(x, y, sizeX);
    double* output =  newtonEvaluation(guess, sizeGuess, x, coeff, sizeX);
    delete[] coeff;
    return output;
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
    double* values = newtonInterpolation(x,y,size, interval, 2e4);
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
