# LU factorization
## Table of Contents
1. [sppLU](#function-name-spplu)
    1. [Description](#description)
    2. [Input](#input)
    3. [Output](#output)
    4. [Code](#code)
    5. [Example](#example)
 
## Function Name: sppLU

## Description:
Performs an LU factorization of a square matrix A using scaled partial pivoting to reduce computational error. 
 
## Input:
`double* A` - A pointer to a square, 2D array of doubles 
`int* perm` - A pointer to an integer array of length M, to record the permutations of A. 
`int M` - The dimension of one side of the 2D array.
    
## Output:
Values in `A` and `perm` are changed in place, so the void function returns no values.

The matrix `A` does not have it's rows reordered due to pivoting, so the values in the vector `perm` represent the applicable row orderings of the true matrix decomposition. 

sppLU changes the vector `perm` to represent both the permutation of the matrix due to pivoting, as well as the correct row ordering. The ith element in the vector represents the index of the row that is the ith row in our array L.

After reordering the rows of `A` according to the values in `perm`, the matrix contains the values for the lower triangular matrix `L` below the diagonal, where `L` has ` for all diagonal values,  and the values of the upper triangular matrix `U` above and including the diagonal.

## Code:
```c
#include <math.h>

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
        printf("%d\n", perm[i]);
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
        printf("%d\n", perm[k]);
        
        for(int i = k+1; i < M; i++){
            double l = pointerMap[i][k]/pointerMap[k][k];
                for (int j = k+1; j< M; j++){
                    pointerMap[i][j] = pointerMap[i][j] - pointerMap[k][j]*l;
                }
            pointerMap[i][k] = l;
        }
    }
}
```

## Example:
```c
int main(){
    double A [4][4] = {{0,1,1,-3},{-2,3,1,4},{0,0,0,1},{3,1,0,0}};
    int map[4];
    sppLU( (double*) A, map, 4);
    printMat( (double*) A, 4, 4);
    printVec(map, 4);
    return 0;
}

```
OUTPUT:
```
0.000000  0.272727  0.727273  -4.090909 
-0.666667  3.666667  1.000000  4.000000 
0.000000  0.000000  0.000000  1.000000 
3.000000  1.000000  0.000000  0.000000 

3
1
0
2
```

### Author: 
Frost Mitchell

### Last edited:
2017-10-9
