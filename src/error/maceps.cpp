/***********************************
Frost Mitchell
A01514458
MATH 4610

Functions:
    singleMacEps
    doubleMacEps
    longDoubleMacEps

Summary:
    Calculate the machine epsilon for each respective data type.
    Epsilon is computed by adding it to 1, which guarantees that
    epsilon is not simply a floating point number with a mantissa
    of 1 and a large negative exponent.

***********************************/
#include "src/error/maceps.hpp"
#include <stdio.h>
#include <math.h>

int singleMacEps(){
    float floatEps=1;
    while(1 + floatEps  != 1.0)
        floatEps /= 2;
    return round(log10(floatEps))*-1;
    //return floatEps;
}

int doubleMacEps(){
    double dubEps=1;
    while(1 + dubEps  != 1.0)
        dubEps /= 2;
    return round(log10(dubEps))*-1;
    //return dubEps;
}

int longDoubleMacEps(){
    long double ldubEps=1;
    while(1 + ldubEps  != 1.0)
        ldubEps /= 2;
    return round(log10(ldubEps))*-1;
    //return ldubEps;
}
