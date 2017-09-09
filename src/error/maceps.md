### Table of Contents
https://github.com/kbentum/math4610/blob/master/src/error/maceps.md#function-name-singlemaceps
1. [singleMacEps](#function-name-singlemaceps)
   1. [Description](#description)
   2. [Input](#input)
   3. [Output](#output)
   4. [Code](#code)
   5. [Example](#example)
2. [doubleMacEps](#function-name-doublemaceps)
   1. [Description](#description-1)
   2. [Input](#input-1)
   3. [Output](#output-1)
   4. [Code](#code-1)
   5. [Example](#example-1)

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
```c
#include "precision.hpp"
#include <stdio.h>
#include <math.h>

int singleMacEps(){
    float floatEps=1;
    while(1 + floatEps != 1.0)
        floatEps /= 2;
    return round(log10(floatEps))*-1;
}
```

## Example
```c
#include "src/error/precision.hpp"
#include <stdio.h>

int main(){
    int digits = singleMacEps();
    printf("The number of digits of precision for a float is %d\n", digits);
    return 0;
}
```
Output:
```
The number of digits of precision for a float is 7
```



# Function Name: doubleMacEps

## Description: 
Calculate the machine epsilon for a double-precision number on this machine.
Add 1 to epsilon to calculate the error without changing the exponent in the
floating point representation of the error.

## Input:
None

## Output:
Returns the number of digits represented by a double-precision floating point
number.

## Code:
```c
#include "precision.hpp"
#include <stdio.h>
#include <math.h>

int doubleMacEps(){
    double dubEps=1;
    while(1 + dubEps != 1.0)
        dubEps /= 2;
    return round(log10(dubEps))*-1;
}
```

## Example
```c
#include "src/error/precision.hpp"
#include <stdio.h>

int main(){
    int digits = doubleMacEps();
    printf("The number of digits of precision for a float is %d\n", digits);
    return 0;
}
```
Output:
```
The number of digits of precision for a float is 16
```
