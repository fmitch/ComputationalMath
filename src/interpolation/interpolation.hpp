#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

double* dividedDifferenceCoefficients(double* x, double* y, int size);
double* newtonEvaluation(double* guess, int sizeGuess, double* x, double* coeff, int sizeX);
double* newtonInterpolation(double* x, double* y, int sizeX, double* guess, int sizeGuess);

#endif
