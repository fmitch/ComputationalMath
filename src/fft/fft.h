#ifndef FFT_H
#define FFT_H
/* Factored discrete Fourier transform, or FFT, and its inverse iFFT 

M. Victor Wickerhauser
from "Mathematics for Multimedia",  2009
Distributed as "public software", freely used for any noncommercial purpose.
*/

typedef double real;
typedef struct{real Re; real Im;} complex;

void print_vector( const char *title, complex *x, int n);
void scaled_fft( complex *v, int n, complex *tmp );
void fft( complex *v, int n, complex *tmp );
void ifft( complex *v, int n, complex *tmp );

#endif
