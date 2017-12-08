# Root finding methods
1. [Hybrid Secant Method](#function-name-hybridsecantmethod)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)


# Function Name: hybridSecantMethod 

## Description: 
Perfroms a hybrid method to find the roots of a function using bisection and 
the secant method. Initally, the secant method of finding a root is attempted
using the inital points x0 and x1. If the error begins to diverge, or if f(x1) -
f(x1) = 0, then bisection is performed
4 times on the given interval [a, b], which reduces the error by one
decimal place. Then the secant method is attempted again on the midpoint of the 
new interval. As long as the secant method does not converge to a value, then 
bisection is repeated 4 times, then the secant method is attempted again. 

See [bisectN](#function-name-bisectN) and [secantMethod](#function-name-secantMethod) for more details.

## Input:
*  `double x0` - The initial guess of the root  
*  `double x0` - The second initial point to approximate the secant line  
*  `double a` - The lower bound of the interval containing a root    
*  `double b` - The upper bound of the interval containing a root  
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  
*  `double tol = 1e-12` - The tolernace for the error of the function    
*  `int maxIter = 1e5` - The maximum number of iterations.    

## Output:
*  Returns a root of the function within the given tolerance.

## Code:
```c
template <typename funx, typename funx2>
double hybridSecantMethod(double x0, double x1,  double a, double b, 
    funx f, double tol=1e-12, int maxIter=1e5){
    while(true){
        try{
            return secantMethod(x0, x1, f, tol, maxIter);
        }
        catch (...) {
            bisectN(a, b, f, 4);
            x0 = (a + b) * 0.5;
            x1 = (a + b) * 0.7;
        }
    }
}
```

## Example:
```c
#include "roots.hpp"
#include <math.h>
#include <stdio.h>
#include <float.h>

int main(){
    num = hybridSecantMethod( 1, 1.1, -1, 1.5, [](double x){return x*exp(-x);} );
    printf("The root returned by the hybrid secant method of x*e^-x is %f\n", num);

    num = hybridSecantMethod( 0.7978665712413240755245781207, 
        0.7978665712413240755245781307, -0.5, 2,  [](double x){return 3*x*sin(10*x);} );
    printf("The root returned by the hybrid secant method of 3x*cos(10x) is %f\n", num);

    return 0;
}
```
OUTPUT:
```c
The root returned by the hybrid secant method of x*e^-x is 0.000000
The root returned by the hybrid secant method of 3x*cos(10x) is -0.314159
```

### Author: 
Frost Mitchell

### Last edited:
2017-12-2
