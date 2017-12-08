# Root finding methods
1. [secantMethod](#function-name-secantmethod)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)


# Function Name: secantMethod

## Description: 
Use the secant method to find a root of a function of x. The secant method
requires an initial guess x0 and another point x1 which is used to approximate
the root using a secant line.  The function finds the root using an 
iterative method:

x\_k+1 = x\_k - f(x\_k) * (x\_k - x\_k-1)/ (f(x\_k)-f(x\_k-1))

If the initial guess is not sufficiently close to
the root, the error will grow. In this case, a runtime error is thrown. If the
derivative of the function at a guess is 0, a runtime error is thrown. If the 
max number of iterations is reached, a runtime error is thrown..

## Input:
*  `double x0` - The initial guess at the root.  
*  `double x1` - Another initial point with which to approximate the root.  
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  
*  `double tol = 1e-12` - The tolernace for the error of the function  
*  `int maxIter = 1e5` - The maximum number of iterations.  

## Output:
*  `double x0` - The root approximated using Newton's method. 
If a value is returned, it is guaranteed to be within tolerance of a root of
the function.

## Code:
```c
template <typename funx>
double secantMethod(double x0, double x1, funx f,  double tol=1e-12, int maxIter=1e5){
    double error = DBL_MAX-1;
    double prevError = DBL_MAX;
    int counter = 0;
    double f0 = f(x0);
    double f1 = f(x1);
    double xk = x1;
    if (fabs(f1 - f0) < DBL_EPSILON)
        throw std::runtime_error("The function seems to have a derivative 
            of approximately 0 at the initial guess.\n");
    while ((error > tol) && (counter < maxIter)){
        if (prevError < error)
            throw std::runtime_error("The initial guesses are not sufficiently
                close to the root so as to converge.");
        counter++;
        xk = x1 - f1*(x1 - x0)/(f1 - f0); 
        prevError = error;
        error = fabs(xk - x1);
        x0 = x1;
        x1 = xk;
        f0 = f1;
        f1 = f(x1);
    }
    if (counter >= maxIter)
            throw std::runtime_error("Max iterations reached.\n");
    return x0;
}
```

## Example:
```c
#include "roots.hpp"
#include <math.h>
#include <stdio.h>

int main(){
    double num = secantMethod( 0.5, .6, [](double x){return x*exp(-x);});
    printf("The root returned by the secant method of x*e^-x is %f\n", num);
```
OUTPUT:
```
The root returned by the secant method of x*e^-x is -0.000000
```


### Author: 
Frost Mitchell

### Last edited:
2017-12-2
