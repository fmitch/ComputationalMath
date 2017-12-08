# Root finding methods
1. [bisectN](#function-name-bisectn)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)


# Function Name: bisectN

## Description: 
Use the bisection method to bisect the interval [a, b] and modify the values
by reference in order to prepare for a hybrid root finding method. 
If there is no root guaranteed in the interval, (i.e., a\*b > 0) a runtime_error is thrown. 

## Input:
*  `double &a` - The lower bound of the interval  
*  `double &b` - The upper bound of the interval  
*  `funx f` - A lambda function of the form `[](double x){return <FUNCTION>;}`,
 where <FUNCTION> is a function of x such as x\*x + x\*2  
* `int n` - The number of times to perform bisection.  

## Output:
*  The function has no outputs. Instead, either a or b is modified by reference.

## Code:
```c
template <typename funx>
void bisectN(double &a, double &b, funx f, int n){
    double fa = f(a);
    double fb = f(b);
    if (n < 1)
        throw std::runtime_error("Bisection must be run more than 0 times.");
    for(int i = 0; i < n; i++)
    {
        if (fa * fb > 0)
            throw std::runtime_error("There doesn't seem to be a root in the given interval");
        double c = 0.5 * (a + b);
        double fc = f(c);
        if (fa * fc < 0)
            b = c;
        else
            a = c;
    }
}
```

## Example:
```
#include "roots.hpp"
#include <stdio.h>

int main(){
    double a = -1, b = 2;
    printf("The interval is [%f, %f].\n", a, b);
    bisectN(a, b, [](double x){return x;});
    printf("The interval is [%f, %f].\n", a, b);
    bisectN(a, b, [](double x){return x;});
    printf("The interval is [%f, %f].\n", a, b);

    return 0;
```
OUTPUT:
```
The interval is [-1.000000, 2.000000].
The interval is [-1.000000, 0.500000].
The interval is [-0.250000, 0.500000].
```



### Author: 
Frost Mitchell

### Last edited:
2017-12-2
