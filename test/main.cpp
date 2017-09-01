#include "src/error/precision.hpp"
#include "src/approximations/series.hpp"
#include <stdio.h>

int main(){
    int pres = singleMacEps();
    printf("precision of float is %d digits.\n", pres); 
    pres = doubleMacEps();
    printf("precision of double is %d digits.\n", pres); 
    pres = longDoubleMacEps();
    printf("precision of long double is %d digits\n", pres); 

    double ex1 = expSeries(1);
    printf("e is %f \n", ex1); 
    return 0;

}
