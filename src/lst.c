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

void cons(struct lst_t *L, void *datum)
{
    assert(L);
    struct lst_elm_t *E = new_lst_elm(datum);
    assert(E);
    E->suc = L->head;
    L->head = E;
    if (L->numelm == 0)
        L->tail = E;
    L->numelm += 1;
}

void print_lst(struct lst_t *L)
{
    printf("[ ");
    for (struct lst_elm_t *E = L->head; E; E = E->suc)
    {
        printf("%d ", E->datum);
    }
    printf("]\n\n");
}

void del_lst(struct lst_t **ptrL, void (*ptrFct)())
{
    assert(ptrL && *ptrL);
    for (struct lst_elm_t *E = (*ptrL)->head; E;)
    {
        struct lst_elm_t *T = E;
        E = E->suc;
        del_lst_elm_t(&T);
    }
    free(*ptrL);
    *ptrL = NULL;
}

void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place)
{
    if (place == NULL)
        cons(L, value);
    else
    {
        struct lst_elm_t *new = new_lst_elm(value);
        assert(new);
        new->suc = place->suc;
        place->suc = new;
        L->numelm++;
        if (place == L->tail)
            L->tail = new;
    }
}

void insert_ordered(struct lst_t *L, void *datum, bool (*ptrFct)())
{
    if (emptyLst(L))
    {
        cons(L, datum);
        print_lst(L);
    }
    else if (datum < L->head->datum)
    {
        cons(L, datum);
        print_lst(L);
    }
    else if (datum > L->tail->datum)
    {
        insert_after(L, datum, L->tail);
        print_lst(L);
    }
    else
    {
        for (struct lst_elm_t *E = L->head; E; E = E->suc)
        {
            // Condition biaisée
            if (datum > E->datum && datum <= E->datum)
            {
                insert_after(L, datum, E);
                print_lst(L);
            }
        }
    }
}
