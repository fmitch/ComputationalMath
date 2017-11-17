#ifndef PARITERATIVE_HPP
#define PARITERATIVE_HPP

static int parc = 0;
double* parJacobi(double* A, double* b, int N, int& count = parc, long double tol=1e-8, int maxIter = 1e6);
double* parGaussSeidel(double* A, double* b, int N, int& count=parc, long double tol=1e-8, int maxIter = 1e6);
double* parSteepestDescent(double* A, double* b, int N, int& count=parc, long double tol=1e-8, int maxIter = 1e6);
double* parConjugateGradient(double* A, double* b, int N, int& count=parc, long double tol=1e-8, int maxIter = 1e6);

#endif
