#include <stdio.h>
#include <stdlib.h>
#include "pair.h"
#include "matrix.h"

int main()
{
    struct matrix *A = scanMatrix();
    struct matrix *B = scanMatrix();
    viewMatrix(A, "A");
    viewMatrix(B, "B");
    viewMatrix(matrixAdd(A, B), "A + B");
    viewMatrix(matrixMult(A, B), "A * B");
}