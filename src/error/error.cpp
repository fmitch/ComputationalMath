/**************************************
Frost Mitchell
A01514458
MATH 4610

Functions:
    relativeError:
        Summary:
            Returns the relative error of an approximation, using the formula
            relativeError = |exactValue - approximation| / exactValue
        Inputs: 
            double exact: the exact value 
            double approx: the approximation of the value
        Outputs:
            double: the relative error of the approximation

    absoluteError:
        Summary:
            Returns the absolute error of an approximation, using the formula
            absoluteError = |exactValue - approximation|
        Inputs: 
            double exact: the exact value 
            double approx: the approximation of the value
        Outputs:
            double: the absolute error of the approximation

**************************************/
#include <math.h>

double relativeError(double exact, double approx){
    return fabs(exact - approx) / exact;
}

double absoluteError(double exact, double approx){
    return fabs(exact - approx);
}
