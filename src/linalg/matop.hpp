#ifndef MATOP_HPP
#define MATOP_HPP

double mat();
double* matAdd(double* A, double* B, int M, int N);
double* matSub(double* A, double* B, int M, int N);
double* scaleMat(double* A, int M, int N, double scalar);
double* matMul(double* A, double* B, int M, int N, int P);
double* matVecMul(double* A, double* v, int M, int N);
double  dotProduct(double* v1, double* v2, int size);

#endif
