#include "lst_elm.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

struct lst_elm_t *new_lst_elm(int value)
{
    struct lst_elm_t *E;
    E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
    assert(E);
    E->x = value;
    return E;
}

void del_lst_elm_t(struct lst_elm_t **ptrE)
{
    assert(ptrE && *ptrE);
    free(*ptrE);
    *ptrE = NULL;
}

int getX(struct lst_elm_t *E)
{
    return E->x;
}

struct lst_elm_t *getSuc(struct lst_elm_t *E)
{
    return E->suc;
}

void setX(struct lst_elm_t *E, int v)
{
    E->x = v;
}

void setSuc(struct lst_elm_t *E, struct lst_elm_t *S)
{
    E->suc = S->suc;
}