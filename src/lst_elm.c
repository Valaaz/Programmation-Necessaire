#include "lst_elm.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

struct lst_elm_t *new_lst_elm(void *datum)
{
    struct lst_elm_t *E;
    E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
    assert(E);
    E->datum = datum;
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
    return E->datum;
}

struct lst_elm_t *getSuc(struct lst_elm_t *E)
{
    return E->suc;
}

void *setDatum(struct lst_elm_t *E, void *datum)
{
    E->datum = datum;
}

void setSuc(struct lst_elm_t *E, struct lst_elm_t *S)
{
    E->suc = S->suc;
}