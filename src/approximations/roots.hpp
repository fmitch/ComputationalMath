#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <stdexcept>

template <typename funx>
double bisect(double a, double b, funx f, double tol, int maxIter){
    double error = 10.0 * tol;
    int counter = 0;
    double fa = f(a);
    double fb = f(b);
    if (fa == 0)
        return fa;
    if (fb == 0)
        return fb;
    if (fa * fb > 0)
    {
        throw std::runtime_error("There doesn't seem to be a root in the given interval");
    }
    double c;
    double fc;
    while ((error > tol) && (counter < maxIter))
    {
        c = 0.5 * (a + b);
        fc = f(c);
        if (fc == 0)
            return c;
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        error = b - a;
        printf("%.16f\n", error);
        counter++;
    }
    if (counter == maxIter)
        printf("Max number of iterations has been reached. The approximation is outside the acceptable tolerance.\n");
    return c;
}

template <typename funx>
void bisectOnce(double &a, double &b, funx f){
    double fa = f(a);
    double fb = f(b);
    if (fa * fb > 0)
        throw std::runtime_error("There doesn't seem to be a root in the given interval");
    double c = 0.5 * (a + b);
    double fc = f(c);
    if (fa * fc < 0)
        b = c;
    else
        a = c;
}

template <typename funx>
double fixedPointIteration(funx g, double tol=1e-12, int maxIter=1e5, double guess = 0.01){
    int counter = 0;
    double xk = g(guess);
    double xnext;
    while(counter < maxIter){
        xnext = g(xk);
        if (fabs(xnext - xk) < tol)
            return xnext;
        xk = xnext;
        counter++;
    }
    printf("Max number of iterations exceeded. Returning closest approximation...");
    return xnext;
}

template <typename funx, typename funx2>
double simpleNewtonsMethod(double x0, funx f, funx2 df, double tol=1e-12, int maxIter=1e5){
    double error = 10 * tol;
    int counter = 0;
    double f0 = f(x0);
    double df0 = df(x0);
    double xk = x0;
    while (( error > tol) && (counter < maxIter)){
        counter++;
        xk = x0 - f0/df0;
        error = fabs(xk - x0);
        x0 = xk;
        f0 = f(x0);
        df0 = df(x0);
    }
    if (counter >= maxIter)
        printf("Max number of iterations exceeded. Returning closest approximation...\n");
    return x0;
}

template <typename funx, typename funx2>
double newtonsMethod(double x0, funx f, funx2 df, double tol=1e-12, int maxIter=1e5){
    double error = DBL_MAX - 1;
    int counter = 0;
    double f0 = f(x0);
    double df0 = df(x0);
    double prevError = DBL_MAX;
    if (fabs(df0) < DBL_EPSILON)
        throw std::runtime_error("The function seems to have a derivative of approximately 0 at the initial guess x0.\n");
    double xk = x0;
    while (( error > tol) && (counter < maxIter)){
        if (prevError < error)
            throw std::runtime_error("The initial guess is not sufficiently close to the root so as to converge.");
        counter++;
        xk = x0 - f0/df0;
        prevError = error;
        error = fabs(xk - x0);
        printf("%.16f\n", error);
        x0 = xk;
        f0 = f(x0);
        df0 = df(x0);
        if (fabs(df0) < tol)
            throw std::runtime_error("The function seems to have a derivative of approximately 0.\n");
    }
    if (counter >= maxIter)
            throw std::runtime_error("Max iterations reached.\n");
    return x0;
}

template <typename funx>
double secantMethod(double x0, double x1, funx f,  double tol=1e-12, int maxIter=1e5){
    double error = DBL_MAX-1;
    int counter = 0;
    double f0 = f(x0);
    double f1 = f(x1);
    double xk = x1;
    if (fabs(f1 - f0) < DBL_EPSILON)
        throw std::runtime_error("The function seems to have a derivative of approximately 0 at the initial guess.\n");
    while ((error > tol) && (counter < maxIter)){
        counter++;
        xk = x1 - f1*(x1 - x0)/(f1 - f0); 
        error = fabs(xk - x1);
        printf("%.16f\n", error);
        x0 = x1;
        x1 = xk;
        f0 = f1;
        f1 = f(x1);
    }
    if (counter >= maxIter)
            throw std::runtime_error("Max iterations reached.\n");
    return x0;
}

template <typename funx, typename funx2>
double hybridNewtonsMethod(double x0, double a, double b, funx f, funx2 df, double tol=1e-12, int maxIter=1e5){
    while(true){
        try{
            return newtonsMethod(x0, f, df, tol, maxIter);
        }
        catch (...) {
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            x0 = (a + b) * 0.5;
        }
    }
}

template <typename funx>
double hybridSecantMethod(double x0, double x1, double a, double b, funx f, double tol=1e-12, int maxIter=1e5){
    while(true){
        try{
            return secantMethod(x0, x1, f, tol, maxIter);
        }
        catch (...) {
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            bisectOnce(a, b, f);
            x0 = (a + b) * 0.5;
            x1 = (a + b) * 0.7;
        }
    }
}
