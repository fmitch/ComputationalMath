# Root finding methods
## Table of Contents
1. [bisect](#function-name-bisect)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
2. [fixedPointIteration](#function-name-fixedpointiteration)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)
3. [simpleNewtonsMethod](#function-name-simplenewtonsmethod)
    1. [Description](#description-2)
    2. [Input](#input-2)
    3. [Output](#output-2)
    4. [Code](#code-2)
    5. [Example](#example-2)
4. [newtonsMethod](#function-name-newtonsmethod)
    1. [Description](#description-3)
    2. [Input](#input-3)
    3. [Output](#output-3)
    4. [Code](#code-3)
    5. [Example](#example-3)
5. [secantMethod](#function-name-secantmethod)
    1. [Description](#description-4)
    2. [Input](#input-4)
    3. [Output](#output-4)
    4. [Code](#code-4)
    5. [Example](#example-4)
6. Hybrid Methods
    1. [bisectOnce](#function-name-bisectonce)
        1. [Description](#description-5)
        2. [Input](#input-5)
        3. [Output](#output-5)
        4. [Code](#code-5)
        5. [Example](#example-5)
    2. [Hybrid Newton's Method](#function-name-hybridnewtonsmethod)
        1. [Description](#description-6)
        2. [Input](#input-6)
        3. [Output](#output-6)
        4. [Code](#code-6)
        5. [Example](#example-6)
    3. [Hybrid Secant Method](#function-name-hybridsecantmethod)
        1. [Description](#description-7)
        2. [Input](#input-7)
        3. [Output](#output-7)
        4. [Code](#code-7)
        5. [Example](#example-7)

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

## Example:
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
```

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


# Function Name: simpleNewtonsMethod

## Description: 
Use Newton's method to find a root of a function of x. Newton's method
requires an initial guess x0. The function then finds the root using an iterative
method:

x\_k+1 = x\_k - f(x\_k) / f'(x\_k)

This function has no error checking other than returning after the maximum 
number of iterations has been reached, even if the value returned is not less
than the required tolerance.

## Input:
*  `double x0` - The initial guess at the root.  
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  
*  `funx2 df` - A lambda function of x of the same form, which is the derivative of f.   
*  `double tol = 1e-12` - The tolernace for the error of the function  
*  `int maxIter = 1e5` - The maximum number of iterations.  

## Output:
*  `double x0` - The root approximated using Newton's method. If no solution
within tolerance is found within the max number of iterations, the closest 
value is returned, with an error message.

## Code:
```c
template <typename funx, typename funx2>
double simpleNewtonsMethod(double x0, funx f, funx2 df, double tol=1e-12, int maxIter=1e5){
    double error = 10 * tol;
    int counter = 0;
    double f0 = f(x0);
    double df0 = df(x0);
    double xk = x0;
    while (( error > tol) && (counter < maxIter)){
        counter++;
        xk = x0 - f0/df0;
        error = fabs(xk - x0);
        x0 = xk;
        f0 = f(x0);
        df0 = df(x0);
    }
    printf("Max number of iterations exceeded. Returning closest approximation...\n");
    return x0;
}
```

## Example:
```c
#include "roots.hpp"
#include <math.h>
#include <stdio.h>

int main(){
    double num = simpleNewtonsMethod( -1.1, [](double x){return x*exp(-x);} , 
        [](double x){return -x*exp(-x) + exp(-x) ;}, 1e-12, 1e9);
    printf("The root returned by a simple Newton's method of x*e^-x is %f\n", num);
}
```
OUTPUT:
```
The root returned by a simple Newton's method of x*e^-x is 0.000000
```




# Function Name: newtonsMethod

## Description: 
Use Newton's method to find a root of a function of x. Newton's method
requires an initial guess x0. The function then finds the root using an 
iterative method:

x\_k+1 = x\_k - f(x\_k) / f'(x\_k)

If the initial guess is not sufficiently close to
the root, the error will grow. In this case, a runtime error is thrown. If the
derivative of the function at a guess is 0, a runtime error is thrown. If the 
max number of iterations is reached, a runtime error is thrown..

## Input:
*  `double x0` - The initial guess at the root.  
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  
*  `funx2 df` - A lambda function of x of the same form, which is the derivative of f.   
*  `double tol = 1e-12` - The tolernace for the error of the function  
*  `int maxIter = 1e5` - The maximum number of iterations.  

## Output:
*  `double x0` - The root approximated using Newton's method. 
If a value is returned, it is guaranteed to be within tolerance of a root of
the function.

## Code:
```c
template <typename funx, typename funx2>
double newtonsMethod(double x0, funx f, funx2 df, double tol=1e-12, int maxIter=1e5){
    double error = DBL_MAX - 1;
    int counter = 0;
    double f0 = f(x0);
    double df0 = df(x0);
    double prevError = DBL_MAX;
    if (fabs(df0) < DBL_EPSILON)
        throw std::runtime_error("The function seems to have a derivative 
            of approximately 0.\n");
    double xk = x0;
    while (( error > tol) && (counter < maxIter)){
        if (prevError < error)
            throw std::runtime_error("The initial guess is not sufficiently
                close to the root so as to converge.");
        counter++;
        xk = x0 - f0/df0;
        prevError = error;
        error = fabs(xk - x0);
        x0 = xk;
        f0 = f(x0);
        df0 = df(x0);
        if (df0 < tol)
            throw std::runtime_error("The function seems to have a 
                derivative of approximately 0 at the initial guess x0.\n");
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
    double num = newtonsMethod( -1, [](double x){return x*exp(-x);} , 
        [](double x){return -x*exp(-x) + exp(-x) ;}, 1e-12, 1e9);
    printf("The root returned by Newton's method of x*e^-x is %f\n", num);

    num = newtonsMethod( 1, [](double x){return x*exp(-x);} , 
        [](double x){return -x*exp(-x) + exp(-x) ;}, 1e-12, 1e9);
    printf("The root returned by Newton's method of x*e^-x is %f\n", num);
}
```
OUTPUT:
```
The root returned by Newton's method of x*e^-x is 0.000000
libc++abi.dylib: terminating with uncaught exception of type 
std::runtime_error: The function seems to have a derivative of 
approximately 0 at the initial guess x0.
```


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

# Function Name: bisectOnce

## Description: 
Use the bisection method to bisect the interval [a, b] and modify the values
by reference in order to prepare for a hybrid root finding method. 
If there is no root guaranteed in the interval, (i.e., a\*b > 0) a runtime_error is thrown. 

## Input:
*  `double &a` - The lower bound of the interval  
*  `double &b` - The upper bound of the interval  
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  

## Output:
*  The function has no outputs. Instead, either a or b is modified by reference.

## Code:
```c
template <typename funx>
void bisectOnce(double &a, double &b, funx f){
    double fa = f(a);
    double fb = f(b);
    if (fa * fb > 0)
        throw std::runtime_error("There doesn't seem to be a root in the given interval");
    double c = 0.5 * (a + b);
    double fc = f(c);
    if (fa * fc < 0)
        b = c;
    else
        a = c;
}
```

## Example:
```
#include "roots.hpp"
#include <stdio.h>

int main(){
    double a = -1, b = 2;
    printf("The interval is [%f, %f].\n", a, b);
    bisectOnce(a, b, [](double x){return x;});
    printf("The interval is [%f, %f].\n", a, b);
    bisectOnce(a, b, [](double x){return x;});
    printf("The interval is [%f, %f].\n", a, b);

    return 0;
```
OUTPUT:
```
The interval is [-1.000000, 2.000000].
The interval is [-1.000000, 0.500000].
The interval is [-0.250000, 0.500000].
```


# Function Name: hybridNewtonsMethod 

## Description: 
Perfroms a hybrid method to find the roots of a function using bisection and 
Newton's method. Initally, Newton's method of finding a root is attempted at
an initial guess x0. If the error begins to diverge, or if the derivative of
the function at the guess is 0, then bisection is performed
4 times on the given interval [a, b], which reduces the error by one
decimal place. Then Newton's method is attempted again on the midpoint of the 
new interval. As long as Newton's method does not converge to a value, then 
bisection is repeated 4 times, then Newton's method is attempted again. 

See [bisectOnce](#function-name-bisectOnce) and [newtonsMethod](#function-name-newtonsMethod) for more details.

## Input:
*  `double x0` - The initial guess of the root
*  `double a` - The lower bound of the interval containing a root  
*  `double b` - The upper bound of the interval containing a root
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  
*  `funx2 df` - A lambda function of x of the same form, which is the derivative of f.   
*  `double tol = 1e-12` - The tolernace for the error of the function  
*  `int maxIter = 1e5` - The maximum number of iterations.  

## Output:
*  Returns a root of the function within the given tolerance.

## Code:
```c
template <typename funx, typename funx2>
double hybridNewtonsMethod(double x0, double a, double b, funx f, 
    funx2 df, double tol=1e-12, int maxIter=1e5){
    while(true){
        try{
            return newtonsMethod(x0, f, df, tol, maxIter);
        }
        catch (...) {
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            x0 = (a + b) * 0.5;
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
    num = hybridNewtonsMethod( 1, -1, 1.5, [](double x){return x*exp(-x);} , 
        [](double x){return -x*exp(-x) + exp(-x) ;});
    printf("The root returned by the hybrid Newton's method of x*e^-x 
        is %f\n", num);

    num = hybridNewtonsMethod( 0.7978665712413240755245781207, -0.5, 2, 
        [](double x){return 3*x*sin(10*x);} , [](double x){return 3*sin(10*x) + 30*x*cos(10*x) ;});
    printf("The root returned by the hybrid Newton's method of 3x*cos(10x) 
        is %f\n", num);

    num = hybridSecantMethod( 1, 1.1, -1, 1.5, [](double x){return x*exp(-x);} );
    printf("The root returned by the hybrid secant method of x*e^-x is %f\n", num);

    num = hybridSecantMethod( 0.7978665712413240755245781207, 
        0.7978665712413240755245781307, -0.5, 2,  [](double x){return 3*x*sin(10*x);} );
    printf("The root returned by the hybrid secant method of 3x*cos(10x) is %f\n", num);

    return 0;
}
```
OUTPUT:
```
The root returned by the hybrid Newton's method of x*e^-x is -0.000000
The root returned by the hybrid Newton's method of 3x*cos(10x) is -0.314159
```

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

See [bisectOnce](#function-name-bisectOnce) and [secantMethod](#function-name-secantMethod) for more details.

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
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
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
