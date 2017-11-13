#ifndef ITERATIVE_HPP
#define ITERATIVE_HPP

static int c = 0;
double* jacobi(double* A, double* b, int N, int& count = c, long double tol=1e-8, int maxIter = 1e6);
double* gaussSeidel(double* A, double* b, int N, int& count=c, long double tol=1e-8, int maxIter = 1e6);
double* steepestDescent(double* A, double* b, int N, int& count=c, long double tol=1e-8, int maxIter = 1e6);
double* conjugateGradient(double* A, double* b, int N, int& count=c, long double tol=1e-8, int maxIter = 1e6);

#endif
