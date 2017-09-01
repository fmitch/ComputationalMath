#include <math.h>
#include <vector>
#include "src/constants/constants.hpp"

double expSeries(double x0){
    double x = 1;
    for (int i=1; i<20; i++)
        x += pow(x0,i) / factorials.at(i-1);
	return x;
}
