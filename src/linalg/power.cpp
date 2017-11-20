#include "power.hpp"
#include "pariterative.hpp"
#include "parmatop.hpp"
#include "matop.hpp"
#include "norms.hpp"
#include <omp.h>
#include <utility>
#include <math.h>

double powerMethod(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parMatVecMul(A, v0, N, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parMatVecMul(A, x, N, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    delete [] x;
    return lambda;
}


std::pair <double, double*> powerMethodPair(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parMatVecMul(A, v0, N, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parMatVecMul(A, x, N, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    return std::make_pair(lambda, x);
}


double inversePowerMethod(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parConjugateGradient(A, v0, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parConjugateGradient(A, x, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    delete [] x;
    return 1/lambda;
}
std::pair <double, double*> inversePowerMethodPair(double* A, double* v0, int N, long double tol, int maxIter){
    double* y = new double[N];
    y = parConjugateGradient(A, v0, N);
    double* x = new double[N];
    double error = tol*100;
    int count=0;
    double lambda, lambdaOld=0;
    while(tol < error && count < maxIter)
    {
        double ymag = vec2norm(y, N);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / ymag;
        y = parConjugateGradient(A, x, N);
        lambda = dotProduct(x,y,N);
        error = fabs(lambda - lambdaOld);
        lambdaOld = lambda;
        count++;
    }
    delete [] y;
    return std::make_pair(1/lambda, x);
}
