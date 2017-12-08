#include "src/approximations/polynomial.hpp"
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
