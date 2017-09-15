/******************************************
*Frost Mitchell
*A01514458
*MATH 4610
*
*Function Title: nestedPolynomial
*
*Summary: Evaluates a nested polynomial at the point x, where the
*         polynomial is of the form
*         p_n(x) = (...((c_(n)x +c_(n−1))x +c_(n−2))x ...)x +c_0,
*         sometimes called Horner's Rule.
*
*Inputs: vector<double> coefficients, a vector of doubles containing
*            the coefficients of the polynomial.
*        double x, the point at which to evaluate the polynomial.
*
*Outputs: double p, the value of the polynomial evaluated at x.
*
*Pseudocode:
*    Begin
*        Initialize p
*        Loop for each coefficient in vector
*            Multiply p by x and add a coefficient.
*        End loop
*    End
*
******************************************/
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
