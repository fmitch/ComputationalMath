#include <stdio.h>
#include <math.h>
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
        counter++;
    }
    if (counter == maxIter)
        printf("Max number of iterations has been reached. The approximation is outside the acceptable tolerance.\n");
    return c;
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
