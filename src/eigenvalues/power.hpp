#ifndef POWER_HPP
#define POWER_HPP

#include <utility>

double powerMethod(double* A, double* v0, int N, long double tol=1e-8, int maxIter=1e6);
std::pair <double, double*> powerMethodPair(double* A, double* b, int N, long double tol=1e-8, int maxIter=1e6);
double inversePowerMethod(double* A, double* b, int N, long double tol=1e-8, int maxIter=1e6);
std::pair <double, double*> inversePowerMethodPair(double* A, double* b, int N, long double tol=1e-8, int maxIter=1e6);

#endif
