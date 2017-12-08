#include "src/matrix_solutions/iterative.hpp"
#include "src/linalg/matop.hpp"
#include <math.h>

double* jacobi(double* A, double* b, int N, int& count, long double tol, int maxIter, double* guess){
    double LUx;
    count = 0;
    double* xk;
    if (guess == nullptr)
    {
        xk = new double[N];
        for( int i = 0; i < N; i++)
            xk[i] = b[i];
    }
    else
        xk = guess;
    double* xkk = new double[N];
    long double error = tol * 100;
    double diff;
    while(count < maxIter && error > tol){
        error = 0;
        for( int i = 0; i < N; i++){
            LUx = 0;
            for ( int j = 0; j < i; j++)
                LUx += *((A+i*N) + j) * xk[j];
            for ( int j = i+1; j < N; j++)
                LUx += *((A+i*N) + j) * xk[j];
            xkk[i]  = (b[i] - LUx) / *((A+i*N)+i);
            diff = fabs(xkk[i] - xk[i]);
            error += diff*diff;
        }
        for( int i = 0; i < N; i++)
            xk[i] = xkk[i];
        error = sqrt(error);
        count++;
    }
    delete[] xkk;
    return xk;
}

double* gaussSeidel(double* A, double* b, int N, int& count, long double tol, int maxIter, double* guess){
    double Lx;
    count = 0;
    double* xk;
    if (guess == nullptr)
    {
        xk = new double[N];
        for( int i = 0; i < N; i++)
        {
            xk[i] = b[i];
        }
    }
    else
        xk = guess;
    double* xkk = new double[N];
    long double error = tol*100;
    double sum, diff;
    while(count < maxIter && error > tol){
        diff = 0;
        for( int i = 0; i < N; i++){
            Lx = 0;
            for ( int j = 0; j < i; j++)
                Lx += *((A+i*N) + j) * xk[j];
            xkk[i]  = (b[i] - Lx) ;
        }
        for( int i = N-1; i >= 0; i--){
            sum = 0;
            for ( int j = i+1; j < N; j++)
                sum += *((A+ i*N) + j) * xkk[j];
            xkk[i] = (xkk[i] - sum) / *((A+i*N) + i);
        }
        for( int i = 0; i < N; i++){
            diff += fabs(xkk[i] - xk[i]);
            xk[i] = xkk[i];
        }
        error = diff*diff;
        count++;
    }
    delete[] xkk;
    return xk;
}

double* steepestDescent(double* A, double* b, int N, int& count, long double tol, int maxIter){
    double* r = new double[N];
    double* xk = new double[N];
    double* Ar = new double[N];
    Ar = matVecMul(A, b, N, N);
    for (int i = 0; i < N; i++){
        r[i] = b[i] - Ar[i];
        xk[i] = b[i];
    }
    double delta_k = dotProduct(r, r, N);
    double b_delta = dotProduct(b, b, N);
    double error = 100 * tol;
    double alpha;
    count = 0;
    while( delta_k > tol * tol * b_delta && count < maxIter){
        Ar = matVecMul(A, r, N, N);
        alpha = delta_k/(dotProduct(r, Ar, N));
        for (int i = 0; i < N; i++){
            xk[i] = xk[i] + alpha*r[i];
            r[i] = r[i] - alpha*Ar[i];
        }
        delta_k = dotProduct(r, r, N);
        count++;
    }
    delete[] r;
    delete[] Ar;
    return xk;
}

double* conjugateGradient(double* A, double* b, int N, int& count, long double tol, int maxIter){
    double* r = new double[N];
    double* p = new double[N];
    double* xk = new double[N];
    double* Ap = new double[N];
    Ap = matVecMul(A, b, N, N);
    for (int i = 0; i < N; i++){
        r[i] = b[i] - Ap[i];
        p[i] = r[i];
        xk[i] = b[i];
    }
    double delta_k = dotProduct(r, r, N);
    double b_delta = dotProduct(b, b, N);
    double error = 100 * tol;
    double alpha, delta_k1;
    count = 0;
    while( delta_k > tol * tol * b_delta && count < maxIter){
        Ap = matVecMul(A, p, N, N);
        alpha = delta_k/(dotProduct(p, Ap, N));
        for (int i = 0; i < N; i++){
            xk[i] = xk[i] + alpha*p[i];
            r[i] = r[i] - alpha*Ap[i];
        }
        delta_k1 = dotProduct(r, r, N);
        for (int i = 0; i < N; i++)
            p[i]= r[i] + delta_k1 / delta_k * p[i];
        delta_k = delta_k1;
        count++;
    }
    delete[] r;
    delete[] Ap;
    delete[] p;
    return xk;
}
