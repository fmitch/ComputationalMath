#include "roots.hpp"
#include <math.h>
#include <stdio.h>
#include <float.h>
#include <time.h>

int main(){
    auto start = clock();
    //double num = bisect( -1, 0.1, [](double x){return x*exp(-x);}, 1e-12, 1e9);
//    printf("The root returned by using bisection on x*e^-x is %f\n", num);
//    printf("The root was calculated in %f ms\n", (clock() - start) / (double)(CLOCKS_PER_SEC / 1000));


    printf("\nBisect:\n");
    double num = bisect( -0.1, 0.001, [](double x){return x*cos(10*x);}, 1e-16, 1e9); 
    printf("\nBisect: %f \n", num);
    printf("\nsecant:\n");
    num = secantMethod( -0.09, -.05353, [](double x){return x*cos(10*x);}, 1e-16, 1e9);
    printf("\nsecant: %f \n", num);
    printf("\nnewton:\n");
    num = newtonsMethod( 0.06532, [](double x){return x*cos(10*x);} , [](double x){return cos(10*x) - 10*x*sin(10*x) ;}, 1e-16, 1e9);
    printf("\nnewton: %f \n", num);

    return 0;





    start = clock();
    num = bisect( 0.1, 0.5, [](double x){return 3*x*sin(10*x);}, 1e-12, 1e9);
//    printf("The root returned by using bisection on 3x*sin(10x) is %f\n", num);
//    printf("The root was calculated in %f ms\n", (clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

    start = clock();
    num = simpleNewtonsMethod( -1, [](double x){return x*exp(-x);} , [](double x){return -x*exp(-x) + exp(-x) ;}, 1e-12, 1e9);
//    printf("The root returned by a simple Newton's method of x*e^-x is %f\n", num);
//    printf("The root was calculated in %f ms\n", (clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

    start = clock();
    num = simpleNewtonsMethod( 0.3, [](double x){return 3*x*sin(10*x);} , [](double x){return 3*sin(10*x) + 30*x*cos(10*x) ;}, 1e-12, 1e9);
//    printf("The root returned by a simple Newton's method of 3x*sin(10x) is %f\n", num);
//    printf("The root was calculated in %f ms\n", (clock() - start) / (double)(CLOCKS_PER_SEC / 1000));
    
    start = clock();
    num = newtonsMethod( 1.1, [](double x){return x*exp(-x);} , [](double x){return -x*exp(-x) + exp(-x) ;}, 1e-12, 1e9);
//    printf("The root returned by Newton's method of x*e^-x is %f\n", num);
//    printf("The root was calculated in %f ms\n", (clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

    start = clock();
    num = newtonsMethod( 0.3, [](double x){return 3*x*sin(10*x);} , [](double x){return 3*sin(10*x) + 30*x*cos(10*x) ;}, 1e-12, 1e9);
//    printf("The root returned by Newton's method of 3x*sin(10x) is %f\n", num);
//    printf("The root was calculated in %f ms\n", (clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

/*
    double num = secantMethod( 0.5, .6, [](double x){return x*exp(-x);});
    printf("The root returned by the secant method of x*e^-x is %f\n", num);

    num = hybridNewtonsMethod( 1, -1, 1.5, [](double x){return x*exp(-x);} , [](double x){return -x*exp(-x) + exp(-x) ;});
    printf("The root returned by the hybrid Newton's method of x*e^-x is %f\n", num);

    num = hybridNewtonsMethod( 0.7978665712413240755245781207, -0.5, 2, [](double x){return 3*x*sin(10*x);} , [](double x){return 3*sin(10*x) + 30*x*cos(10*x) ;});
    printf("The root returned by the hybrid Newton's method of 3x*cos(10x) is %f\n", num);

    num = hybridSecantMethod( 1, 0.9, -1, 1.5, [](double x){return x*exp(-x);} );
    printf("The root returned by the hybrid secant method of x*e^-x is %f\n", num);

    num = hybridSecantMethod( 0.7978665712413240755245781207, 0.7978665712413240755245781307, -0.5, 2,  [](double x){return 3*x*sin(10*x);} );
    printf("The root returned by the hybrid secant method of 3x*cos(10x) is %f\n", num);
*/
    return 0;
}
