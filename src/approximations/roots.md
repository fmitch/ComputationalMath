### Table of Contents
1. [singleMacEps](#function-name-bisect)
   1. [Description](#description)
   2. [Input](#input)
   3. [Output](#output)
   4. [Code](#code)
   5. [Example](#example)

# Function Name: bisect

## Description: 
Use the bisection method to find a root of a function of x over the closed
interval [a, b].  If there is no root guaranteed in the interval, (i.e., a\*b > 0) an error is output and 0 is returned. If the 
max number of iterations is reached, the closest approximation at that point
is returned, along with an error message.

## Input:
*  `double a` - The lower bound of the interval  
*  `double b` - The upper bound of the interval  
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  
*  `double tol` - The tolernace for the error of the function  
*  `int maxIter` - The maximum number of iterations.  

## Output:
*  `double c` - The root approximated in the interval inside the tolerance. If there is no guaranteed root in the interval, the function returns 0 with an error message, and if no solution within tolerance is found within the max number of iterations, the closest value c is returned, with an error message.

## Code:
```c
#include <stdio.h>

template <typename funx>
double bisect(double a, double b, funx f, double tol, int maxIter){
    double error = 10.0 * tol;
    double counter = 0;
    double fa = f(a);
    double fb = f(b);
    if (fa == 0)
        return fa;
    if (fb == 0)
        return fb;
    if (fa * fb > 0)
    {
        printf("There doesn't seem to be a root in the given interval (%f,%f).\n", fa, fb);
        return 0;
    }
    double c;
    double fc;
    while ((error > tol) && (counter < maxIter))
    {
        c = 0.5 * (a + b);
        fc = f(c);
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        error = b - a;
        counter++;
    }
    if (counter == maxIter)
        printf("Max number of iterations has been reached. The approximation is outside the acceptable tolerance.\n");
    return c;
}
```

## Example
```c
#include "src/approximations/roots.hpp"
#include <stdio.h>

int main(){
    double out = bisect(0,5, [](double x){return x*x - 5;}, 0.000001, 50);
    printf("A root was found in the interval (0,50]: %f\n", out);
    return 0;
}
```
Output:
```
A root was found in the interval (0,50]: 2.236068
A root was found in the interval [0,50]: 0.000000
```

### Author: 
Frost Mitchell

### Last edited:
2017-9-14
