#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <assert.h>

void printInteger(int *i)
{
    printf("La valeur est entière et vaut : %d\n", (*i));
}

void rmInteger(int *i)
{
    free(i);
}

bool intcmp(int *i, int *j)
{
    return (*i) < (*j);
}

void printDouble(double *d)
{
    printf("La valeur est réelle et vaut : %lf\n", (*d));
}

void rmDouble(double *d)
{
    free(d);
}

bool reelcmp(double *u, double *v)
{
    return (*u) < (*v);
}

void freeInteger(int *i)
{
    assert(i);
    free(i);
}