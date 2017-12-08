#include <math.h>
#include "src/matrix_solutions/factoring.hpp"

double rowMax(double* A, int row, int length){
    double ans = fabs(*((A+row*length) + 0));
    for(int j = 1; j < length; j++){
		if ( ans < fabs(*((A+row*length) + j)))
			ans = fabs(*((A+row*length) + j));
    }
    return ans;
}
 
void sppLU(double* A, int* perm, int M){
	double** pointerMap = new double*[M];
    double* pointerSwapper;
    int permSwapper;
    for (int i = 0; i < M; i++){
        perm[i] = i;
        pointerMap[i] = A+i*M;
    }
     
    double* s = new double[M];
    for (int i = 0; i < M; i++){
        s[i] = rowMax(A,i,M);
    }
 
    for (int k = 0; k < M; k++){
        int maxRow = k;
        double maxVal = fabs(pointerMap[k][k]/s[k]);
        for(int i = k+1; i < M; i++){
            double val = fabs(pointerMap[i][k]/s[i]);
            if(val > maxVal){
                maxVal = val;
                maxRow = i;
            }
        }
        pointerSwapper = pointerMap[maxRow];
        pointerMap[maxRow] = pointerMap[k];
        pointerMap[k] = pointerSwapper;
        permSwapper = perm[maxRow];
        perm[maxRow] = perm[k];
        perm[k] = permSwapper;
        
        for(int i = k+1; i < M; i++){
            double l = pointerMap[i][k]/pointerMap[k][k];
                for (int j = k+1; j< M; j++){
                    pointerMap[i][j] = pointerMap[i][j] - pointerMap[k][j]*l;
                }
            pointerMap[i][k] = l;
        }
    }
}
