#include "lst.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

void insert_after(struct lst_t *L, void *datum, struct lst_elm_t *place);

bool emptyLst(const struct lst_t *L)
{
    assert(L);
    return L->numelm == 0;
}

struct lst_t *new_lst()
{
    /** @note : calloc fonctionne de manière identique à malloc
		et de surcroît met à NULL(0) tous les octets alloués */
    struct lst_t *L = (struct lst_t *)calloc(1, sizeof(struct lst_t));
    assert(L);
    return L;
}

void cons(struct lst_t *L, void *datum)
{
    struct lst_elm_t *E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
    E->datum = datum;
    E->suc = L->head;
    L->head = E;
    L->numelm += 1;
    if (L->numelm == 1)
    {
        L->tail = E;
    }
}

void view_lst(struct lst_t *L, void (*ptrf)())
{
    printf("[\n");
    for (struct lst_elm_t *E = L->head; E; E = E->suc)
    {
        (*ptrf)(E->datum);
    }
    printf("]\n\n");
}

void del_lst(struct lst_t **ptrL, void (*ptrFct)())
{
    assert(ptrL && *ptrL);
    if ((*ptrFct) == NULL)
    {
        for (struct lst_elm_t *E = (*ptrL)->head; E;)
        {
            struct lst_elm_t *T = E;
            E = E->suc;
            del_lst_elm_t(&T);
        }
    }
    else
    {
        for (struct lst_elm_t *E = (*ptrL)->head; E;)
        {
            struct lst_elm_t *T = E;
            E = E->suc;
            del_lst_elm_t(&T);
        }
    }
    free(*ptrL);
    *ptrL = NULL;
}

void insert_after(struct lst_t *L, void *datum, struct lst_elm_t *place)
{
    if (place == NULL)
        cons(L, datum);
    else
    {
        struct lst_elm_t *new = new_lst_elm(datum);
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
        printf("Vide\n");
        cons(L, datum);
    }
    else if ((*ptrFct)(datum, L->head->datum))
    {
        printf("Tete\n");
        cons(L, datum);
    }
    else if ((*ptrFct)(L->tail->datum, datum))
    {
        printf("Queue\n");
        insert_after(L, datum, L->tail);
    }
    else
    {
        printf("Milieu\n");
        for (struct lst_elm_t *E = L->head; E; E = E->suc)
        {
            printf("Boucle\n");

            if ((*ptrFct)(E->datum, datum) && (*ptrFct)(datum, E->suc->datum))
            {
                printf("Cond\n");
                insert_after(L, datum, E);
            }
        }
    }
}

struct lst_elm_t *getHead(struct lst_t *L)
{
    return L->head;
}

struct lst_elm_t *getTail(struct lst_t *L)
{
    return L->tail;
}

void queue(struct lst_t *L, void *datum)
{
    L->tail = datum;
}

int getNumelm(struct lst_t *L)
{
    return L->numelm;
}

int setNumelm(struct lst_t *L, int numElm)
{
    return L->numelm = numElm;
}