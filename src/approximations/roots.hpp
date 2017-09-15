#include <stdio.h>

template <typename funx>
double bisect(double a, double b, funx f, double tol, int maxIter){
    double error = 10.0 * tol;
    double counter = 0;
    double fa = f(a);
    double fb = f(b);
    if (fa == 0)
        return fa;
    if (fb == 0)
        return fb;
    if (fa * fb > 0)
    {
        printf("There doesn't seem to be a root in the given interval (%f,%f).\n", fa, fb);
        return 0;
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
    return c;
}
