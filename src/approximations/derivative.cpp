/*****************************************
Frost Mitchell
A01514458
MATH 4610

Functions:

    sinDerivative
        Summary: Approximate the derivative of the sin function at a point x0
                 with a given h. This function is implemented with single precision
                 and double precision. 

                 The algorithm used to approximate the derivative is

                 f'(x) = ( f(x0 + h) - f(x0) ) / h

                 The user should be aware that as h reaches low values, the 
                 absolute error of the approximation increases.

        Inputs:
                double x0: the point at which to approximate the derivative
                           of the sin function.
                double h: the small constant used to approximate the derivative

        Outputs:
                double approximation: The approximation of the derivative at x0.

*****************************************/
#include <math.h>
#include "src/constants/constants.hpp" //

double sinDerivative(double x0, double h){
    double approximation = (sin(x0+h) - sin(x0))/h;
    return approximation;
}

float sinDerivative(float x0, float h){
    float approximation = (sin(x0+h) - sin(x0))/h;
    return approximation;
}

double sin2hDerivative(double x0, double h){
    double approximation = (sin(x0+h) - sin(x0-h))/(2*h);
    return approximation;
}

float sin2hDerivative(float x0, float h){
    float approximation = (sin(x0+h) - sin(x0-h))/(2*h);
    return approximation;
}
