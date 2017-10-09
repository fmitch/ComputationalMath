#include "matop.hpp"
#include <stdio.h>

double* matAdd(double* A, double* B, int M, int N){
    double* C = new double[M*N];
    for (int i=0; i< M; i++)
        for (int j = 0; j < N; j++)
            *((C+i*N) + j) = *((A+i*N) + j) + *((B+i*N) + j);
    return C;
}

double* matSub(double* A, double* B, int M, int N){
    double* C = new double[M*N];
    for (int i=0; i< M; i++)
        for (int j = 0; j < N; j++)
            *((C+i*N) + j) = *((A+i*N) + j) - *((B+i*N) + j);
    return C;
}

double* scaleMat(double* A, int M, int N, double scalar){
    double* C = new double[M*N];
    for (int i=0; i<M ; i++)
        for (int j = 0; j < N; j++)
            *((C+i*N) + j) = *((A+i*N) + j) * scalar;
    return C;
}

double* matMul(double* A, double* B, int M, int N, int P){
    double* C = new double[M*N];
    double dot;
    for (int i = 0; i<M; i++)
        for ( int k=0; k<P; k++)
        {
            dot = 0;
            for (int j=0; j<N; j++)
            {
                dot += (*((A+i*N) + j)) * (*((B+j*P) + k));
            }
            *((C+i*P) + k)  = dot;
        }
    return C;
}

double* matVecMul(double* A, double* v, int M, int N){
    double* C = new double[M];
    double dot;
    for (int i = 0; i<M; i++)
    {
        dot = 0;
        for (int j=0; j<N; j++)
            dot += *((A+i*N) + j) * v[j];
        C[i] = dot;
    }
    return C;
}

double  dotProduct(double* v1, double* v2, int size){
    double out = 0;
    for (int i = 0; i < size; i++)
        out += v1[i] * v2[i];
    return out;
}
