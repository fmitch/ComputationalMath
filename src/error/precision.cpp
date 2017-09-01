#include "precision.hpp"
#include <stdio.h>
#include <math.h>

float singleMacEps(){
    float floatEps=1;
    while(1 + floatEps  != 1.0)
        floatEps /= 2;
    return round(log10(floatEps))*-1;
}

double doubleMacEps(){
    double dubEps=1;
    while(1 + dubEps  != 1.0)
        dubEps /= 2;
    return round(log10(dubEps))*-1;
}

long double longDoubleMacEps(){
    long double ldubEps=1;
    while(1 + ldubEps  != 1.0)
        ldubEps /= 2;
    return round(log10(ldubEps))*-1;
}
