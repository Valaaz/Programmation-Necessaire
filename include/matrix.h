#ifndef _MATRIX_
#define _MATRIX_

struct matrix
{
    double *values;
    int n, m;
};
/** @brief Alloue la mémoire et initialise les champs m et n */
struct matrix *consMatrix(int n, int m);
/** @brief Crée une copie exacte de la matrice M */
struct matrix *cpyMatrix(struct matrix *M);
/** @brief Libère toute la mémoire occupée par *M et met celle-ci à NULL */
void freeMatrix(struct matrix **M);
/** @brief Visualise la matrice M après avoir affiché son entête */
void viewMatrix(struct matrix *M, char *entete);
struct matrix *matrixInput(char *filename);
struct matrix *matrixAdd(struct matrix *A, struct matrix *B);
struct matrix *matrixMult(struct matrix *A, struct matrix *B);

#endif