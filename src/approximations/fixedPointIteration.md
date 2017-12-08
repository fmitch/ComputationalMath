# Root finding methods
1. [fixedPointIteration](#function-name-fixedpointiteration)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)

# Function Name: fixedPointIteration

## Description: 
Use fixed point iteration to find a root of a function. The success of the 
method is dependent on if the guess is close enough to the root, and if 
|g'(x\*)| < 1, where x\* is the exact value of the root.

## Input:
*  `funx g` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x where g(x) = x when  f(x) = 0.
*  `double tol` - The tolernace for the error of the function  
*  `int maxIter` - The maximum number of iterations.  
*  `double guess` - The initial guess at the root, which is the starting point
for the iterative function. 

## Output:
*  `double xnext` - The root approximated in the interval inside the 
tolerance . If no solution within tolerance is found within the max 
 number of iterations, the closest value xnext is returned, with an error message.

## Code:
```c
template <typename funx>
double fixedPointIteration(funx g, double tol=1e-12, int maxIter=1e5, double guess = 0.01){
    int counter = 0;
    double xk = g(guess);
    double xnext;
    while(counter < maxIter){
        xnext = g(xk);
        if (fabs(xnext - xk) < tol)
            return xnext;
        xk = xnext;
        counter++;
    }
    printf("Max number of iterations exceeded. Returning closest approximation...");
    return xnext;
}
```

## Example:
```c
#include "roots.hpp"
#include <math.h>
#include <stdio.h>

int main(){
    double out = fixedPointIteration([](double x){return x - (3*x*sin(10*x)/200);}, 0.00000001, 1000, 1.1);
    printf("A root was found: %f \n", out);
    out = fixedPointIteration([](double x){return x - (x*pow(M_E, -1*x));}, 0.00000001, 1000, 01.1);
    printf("A root was found: %f \n", out);

    out = bisect(0,5, [](double x){return x*x - 5;}, 0.000001, 50);
    printf("A root was found in the interval (0,50]: %f\n", out);
    out = bisect(0,2, [](double x){return x*x - 5;}, 0.000001, 50);
    printf("A root was found in the interval [0,50]: %f\n", out);
    return 0;
}
```

OUTPUT:
```
A root was found: 1.256637 
A root was found: 0.000000 
```


### Author: 
Frost Mitchell

### Last edited:
2017-12-2
