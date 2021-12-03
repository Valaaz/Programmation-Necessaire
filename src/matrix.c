#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pair.h"
#include "matrix.h"

struct matrix *consMatrix(int n, int m)
{
    struct matrix *M = (struct matrix *)calloc(1, sizeof(struct matrix));
    M->values = (double *)calloc(m * n, sizeof(double));
    M->n = n;
    M->m = m;
    return M;
}

struct matrix *cpyMatrix(struct matrix *M)
{
    struct matrix *newM = consMatrix(M->n, M->m);
    for (int i = 0; i < M->n * M->m; i++)
    {
        newM->n = M->n;
        newM->m = M->m;
    }
    return newM;
}

void freeMatrix(struct matrix **M)
{
    assert(M && *M);
    free(*M);
    *M = NULL;
}

void viewMatrix(struct matrix *M, char *entete)
{
    printf("%s\n", entete);
    int i, j;
    for (i = 0; i < M->n; i++)
    {
        for (j = 0; j < M->m; j++)
        {
            printf("\t%lf", M->values[pair2ind(consPair(i, j), M)]);
        }
        printf("\n");
    }
}

struct matrix *scanMatrix()
{
    int row, col;
    printf("Veuillez rentrer le nombre de lignes :\n");
    scanf("%d", &row);
    printf("Veuillez rentrer le nombre de colonnes :\n");
    scanf("%d", &col);
    struct matrix *M = consMatrix(row, col);

    for (int i = 0; i < row * col; i++)
    {
        printf("(%d, %d) = ", i / row + 1, i % row + 1);
        scanf("%lf", &M->values[i]);
    }
    return M;
}

struct matrix *matrixAdd(struct matrix *A, struct matrix *B)
{
    struct matrix *M = consMatrix(A->n, A->m);
    for (int i = 0; i < A->n * A->m; i++)
    {
        M->values[i] = A->values[i] + B->values[i];
    }
    return M;
}

struct matrix *matrixMult(struct matrix *A, struct matrix *B)
{
    struct matrix *M = consMatrix(A->n, A->m);
    for (int i = 0; i < A->n * A->m; i++)
    {
        for (int j = 0; j < M->n; j++)
        {
            for (int l = 0; l < B->m; l++)
            {
                M->values[pair2ind(consPair(i, j), M)] += A->values[pair2ind(consPair(i, l), A)] * B->values[pair2ind(consPair(l, j), B)];
            }
        }
    }
    return M;
}