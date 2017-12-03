# Discrete Fourier Transform
## Table of Contents
1. [Fast Fourier Transform](#function-name-fft)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
2. [Inverse Fast Fourier Transform](#function-name-ifft)
    1. [Description](#description-1)
    2. [Input](#input-1)
    3. [Output](#output-1)
    4. [Code](#code-1)
    5. [Example](#example-1)
 
The following code was adapted from code written by 
M. Victor Wickerhauser
from "Mathematics for Multimedia",  2009
The code was marked as "public software", freely usable 
for any noncommercial purpose.

## Function Name: fft

## Description:
Calculate the discrete Fourier transform of a 1-D array using the classic
Cooley-Tukey FFT algorithm.
 
## Input:
*  `complex* v` - A pointer to an array containing time-domain data to transform
which is represented as `complex` structs to transform.  
*  `int n` - The length of the array of complex numbers.  
*  `compex* tmp` - A pointer to an array of `complex` structs used for calculations.  
    
## Output:
The array `v` is changed in place to contain the transformed values.

## Code:
```c
void scaled_fft( complex *v, int n, complex *tmp ){
  if(n>1) {			/* otherwise, do nothing and return */
    int k,m;    
    complex z, w, *vo, *ve;
    ve = tmp; vo = tmp+n/2;
    for(k=0; k<n/2; k++) {
      ve[k] = v[2*k];
      vo[k] = v[2*k+1];
    }
    scaled_fft( ve, n/2, v );		/* FFT on even-indexed elements of v[] */
    scaled_fft( vo, n/2, v );		/* FFT on odd-indexed elements of v[] */
    for(m=0; m<n/2; m++) {
      w.Re = cos(2*PI*m/(double)n);
      w.Im = -sin(2*PI*m/(double)n);
      z.Re = w.Re*vo[m].Re - w.Im*vo[m].Im;	/* Re(w*vo[m]) */
      z.Im = w.Re*vo[m].Im + w.Im*vo[m].Re;	/* Im(w*vo[m]) */
      v[  m  ].Re = ve[m].Re + z.Re;
      v[  m  ].Im = ve[m].Im + z.Im;
      v[m+n/2].Re = ve[m].Re - z.Re;
      v[m+n/2].Im = ve[m].Im - z.Im;
    }
  }
  return;
}

void fft( complex *v, int n, complex *tmp ){
	scaled_fft(v, n, tmp);
	for (int i = 0; i < n; i++)
	{
		v[i].Re = v[i].Re/n;
		v[i].Im = v[i].Im/n;
	}
}
```

## Example:
```c
#include <stdio.h>
#include "fft.h"

#define q	3		/* for 2^3 points */
#define N	(1<<q)		/* N-point FFT, iFFT */

int main(void) {
  complex v[N], scratch[N];
  int k;

  /* Fill v[] with a function of known FFT: */
  for(k=0; k<N; k++) {
      v[0].Re=  0.000,   v[0].Im=  0.000;
      v[1].Re=  1.000,   v[1].Im=  0.000;
      v[2].Re=  0.000,   v[2].Im=  0.000;
      v[3].Re=  0.000,   v[3].Im=  0.000;
      v[4].Re=  0.000,   v[4].Im=  0.000;
      v[5].Re=  0.000,   v[5].Im=  0.000;
      v[6].Re=  0.000,   v[6].Im=  0.000;
      v[7].Re=  0.000,   v[7].Im=  0.000;
  }
    
  /* FFT, iFFT of v[]: */
  print_vector("Orig", v, N);
  fft( v, N, scratch );
  print_vector(" FFT", v, N);

  return 0;
}
```
OUTPUT:
```
Orig (dim=8): 
0.000,  0.000 
 1.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 

 FFT (dim=8): 
0.125,  0.000 
 0.088,  -0.088 
 0.000,  -0.125 
 -0.088,  -0.088 
 -0.125,  0.000 
 -0.088,  0.088 
 -0.000,  0.125 
 0.088,  0.088 
```


## Function Name: ifft

## Description:
Calculate the inverse discrete Fourier transform of a 1-D array using the classic
Cooley-Tukey IFFT algorithm.
 
## Input:
*  `complex* v` - A pointer to an array containing frequency-domain data which
will be transformed to timde domain data. This data is represented as `complex` structs.  
*  `int n` - The length of the array of complex numbers.  
*  `compex* tmp` - A pointer to an array of `complex` structs used for calculations.  
    
## Output:
The array `v` is changed in place to contain the inverse transformed values.

## Code:
```c
void ifft( complex *v, int n, complex *tmp )
{
  if(n>1) {			/* otherwise, do nothing and return */
    int k,m;    complex z, w, *vo, *ve;
    ve = tmp; vo = tmp+n/2;
    for(k=0; k<n/2; k++) {
      ve[k] = v[2*k];
      vo[k] = v[2*k+1];
    }
    ifft( ve, n/2, v );		/* FFT on even-indexed elements of v[] */
    ifft( vo, n/2, v );		/* FFT on odd-indexed elements of v[] */
    for(m=0; m<n/2; m++) {
      w.Re = cos(2*PI*m/(double)n);
      w.Im = sin(2*PI*m/(double)n);
      z.Re = w.Re*vo[m].Re - w.Im*vo[m].Im;	/* Re(w*vo[m]) */
      z.Im = w.Re*vo[m].Im + w.Im*vo[m].Re;	/* Im(w*vo[m]) */
      v[  m  ].Re = ve[m].Re + z.Re;
      v[  m  ].Im = ve[m].Im + z.Im;
      v[m+n/2].Re = ve[m].Re - z.Re;
      v[m+n/2].Im = ve[m].Im - z.Im;
    }
  }
  return;
}
```

## Example:
```c
#include <stdio.h>
#include "fft.h"

#define q	3		/* for 2^3 points */
#define N	(1<<q)		/* N-point FFT, iFFT */

int main(void) {
  complex v[N], scratch[N];
  int k;

  /* Fill v[] with a function of known FFT: */
  for(k=0; k<N; k++) {
      v[0].Re=  0.000,   v[0].Im=  0.000;
      v[1].Re=  1.000,   v[1].Im=  0.000;
      v[2].Re=  0.000,   v[2].Im=  0.000;
      v[3].Re=  0.000,   v[3].Im=  0.000;
      v[4].Re=  0.000,   v[4].Im=  0.000;
      v[5].Re=  0.000,   v[5].Im=  0.000;
      v[6].Re=  0.000,   v[6].Im=  0.000;
      v[7].Re=  0.000,   v[7].Im=  0.000;
  }
    
  /* FFT, iFFT of v[]: */
  print_vector("Orig", v, N);
  fft( v, N, scratch );
  ifft( v, N, scratch );
  print_vector(" IFFT", v, N);

  return 0;
}
```
OUTPUT:
```
Orig (dim=8): 
 0.000,  0.000 
 1.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 

iFFT (dim=8):
 0.000,  0.000 
 1.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
 0.000,  0.000 
```

### Author: 
Frost Mitchell

### Last edited:
2017-12-2
