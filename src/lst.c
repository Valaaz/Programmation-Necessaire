#include "lst.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place);

bool emptyLst(const struct lst_t *L)
{
    assert(L);
    return L->numelm == 0;
}

struct lst_t *newLst()
{
    /** @note : calloc fonctionne de manière identique à malloc
		et de surcroît met à NULL(0) tous les octets alloués */
    struct lst_t *L = (struct lst_t *)calloc(1, sizeof(struct lst_t));
    assert(L);
    return L;
}

void cons(struct lst_t *L, int v)
{
    struct lst_elm_t *new = malloc(sizeof(*new));
    if (L == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->x = v;

    new->suc = L->head;
    L->head = new;
}

void print_lst(struct lst_t *L)
{
    printf("[ ");
    for (struct lst_elm_t *E = L->head; E; E = E->suc)
    {
        printf("%d ", E->x);
    }
    printf("]\n\n");
}

void del_lst(struct lst_t **ptrL)
{
    assert(ptrL && *ptrL);
    // for(struct lst_elm_t * E = (*ptrL)->head; E; ) {
    // struct lst_elm_t * T = E;
    // E = E->suc;
    // del_lst_elm_t(&T);
    // }
    // free(*ptrL);
    // *ptrL = NULL;
    free(*ptrL);
    *ptrL = NULL;
}

void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place)
{
    if (place == NULL)
        cons(L, value);
    else
    {
        int temp = (int)place;
        printf("%d\n", temp);
        for (struct lst_elm_t *E = L->head; E; E = E->suc)
        {
            printf("%d\n", E->x);
            if (E->x == temp)
                E->x = value;
        }
    }
}