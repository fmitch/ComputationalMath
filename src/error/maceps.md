# Function Name: singleMacEps

## Description: 
Calculate the machine epsilon for a single-precision number on this machine.
Add 1 to epsilon to calculate the error without changing the exponent in the
floating point representation of the error.

## Input:
None

## Output:
Returns the number of digits represented by a single-precision floating point
number.

## Code:
`
#include "precision.hpp"
#include <stdio.h>
#include <math.h>

int singleMacEps(){
    float floatEps=1;
    while(1 + floatEps != 1.0)
        floatEps /= 2;
    return round(log10(floatEps))*-1;
}
`

## Example
`
#include "src/error/precision.hpp"
#include <stdio.h>

int main(){
    int digits = singleMacEps();
    printf("The number of digits of precision for a float is %d\n", digits);
    return 0;
}
` 
Output:
`
The number of digits of precision for a float is 7
`
