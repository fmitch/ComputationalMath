/*****************************************
Frost Mitchell
A01514458
MATH 4610

Functions:
    expSeries
        Summary: 
                Evaluate the Taylor series expansion for e^x at a point x0.
                Since 1/(21!) is less than the machine precision for doubles,
                we stop evaluation after the 21st term of the series.

        Inputs:
                double x0: the point at which to evaluate the Taylor series expansion.

        Outputs:
                double x: The approximation of the Taylor series expansion.

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
#include <vector>
#include "src/constants/constants.hpp" //

double expSeries(double x0){
    double x = 1;
    for (int i=1; i<20; i++)
        x += pow(x0,i) / factorials.at(i-1);
	return x;
}

double sinDerivative(double x0, double h){
    double approximation = (sin(x0+h) - sin(x0))/h;
    return approximation;
}

float sinDerivative(float x0, float h){
    float approximation = (sin(x0+h) - sin(x0))/h;
    return approximation;
}
