#include <math.h>

double relativeError(double exact, double approx){
    return fabs(exact - approx) / exact;
}

double absoluteError(double exact, double approx){
    return fabs(exact - approx);
}
