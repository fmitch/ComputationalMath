# Nested Polynomial Computation
1. [Description](#description)
2. [Input](#input)
3. [Output](#output)
4. [Code](#code)
5. [Example](#example)

## Function Name: nestedPolynomial
## Description: 
Evaluates a nested polynomial at the point x, where the
polynomial is of the form  
p_n(x) = (...((c_(n)x +c_(n−1))x +c_(n−2))x ...)x +c_0,
sometimes called Horner's Rule.

## Input: 
*  `vector<double> coefficients` -  A vector of doubles containing the coefficients of the polynomial.
*  `double x` - The point at which to evaluate the polynomial.
 
## Output: 
*  `double p` - The value of the polynomial evaluated at x.

## Code:
```c
#include <vector>
#include <stdio.h>

double nestedPolynomial(std::vector<double> coefficients, double x){
    double p = 0;           //Initialize p
    int counter = 0;
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); it++){ //Loop for each coefficient in vector
        p = p*x + *it;      //Multiply p by x and add a coefficient
        printf("%d \t %f \t %f\n", counter, *it, p);
        counter += 1;
    }
    return p;
}
```

### Author: 
Frost Mitchell

### Last edited:
2017-12-2
