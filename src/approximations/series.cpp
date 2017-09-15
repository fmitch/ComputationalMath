/*****************************************
Frost Mitchell
A01514458
MATH 4610

Functions:
    expSeries
        Summary: 
                Evaluate the Taylor series expansion for e^x at a point x0.
                Since 1/(21!) is less than the machine precision for doubles,
                we stop evaluation after the 21st term of the series.

        Inputs:
                double x0: the point at which to evaluate the Taylor series expansion.

        Outputs:
                double x: The approximation of the Taylor series expansion.

*****************************************/
#include <math.h>
#include "src/constants/constants.hpp" //

double expSeries(double x0){
    double x = 1;
    for (int i=1; i<20; i++)
        x += pow(x0,i) / factorials.at(i-1);
	return x;
}
