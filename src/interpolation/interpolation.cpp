#include "src/interpolation/interpolation.hpp"
#include <omp.h>

double* dividedDifferenceCoefficients(double* x, double* y, int size){
    double* coeff = new double[size];
    double f1, f2;
    double fhold;
    for (int i = 0; i < size; i++){
        coeff[i] = y[i];
    }
    int count = 1;
    for (int j = 0; j < size-1; j++){
        f1 = coeff[count-1];
        for (int i = count; i < size; i++){
            f2 = coeff[i];
            coeff[i] = (coeff[i]-f1) / (x[i] - x[i-count]);
            f1 = f2;
        }
        count++;
    }
    return coeff;
}

double* newtonEvaluation(double* guess, int sizeGuess, double* x, double* coeff, int sizeX){
    double* values = new double[sizeGuess];
    #pragma omp parallel for
    for (int i = 0; i < sizeGuess; i++){
        values[i] = 0;
        for (int j = sizeX-1; j > -1  ; j--)
            values[i] = values[i]*(guess[i] - x[j]) + coeff[j];
    }
    return values;
}


double* newtonInterpolation(double* x, double* y, int sizeX, double* guess, int sizeGuess){
    double* coeff = dividedDifferenceCoefficients(x, y, sizeX);
    double* output =  newtonEvaluation(guess, sizeGuess, x, coeff, sizeX);
    delete[] coeff;
    return output;
}
