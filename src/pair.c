#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pair.h"

struct pair *consPair(int l, int c)
{
    struct pair *P = (struct pair *)calloc(1, sizeof(struct pair));
    P->l = l;
    P->c = c;
    return P;
}

struct pair *cpyPair(struct pair *P)
{
    struct pair *newP = consPair(P->c, P->l);
    return newP;
}

void freePair(struct pair *P)
{
    assert(P);
    free(P);
    P = NULL;
}

int pair2ind(struct pair *p, struct matrix *M)
{
    return (p->l) * (M->n) + (p->c);
}

struct pair *ind2pair(int k, struct matrix *M)
{
    struct pair *P = consPair(k / M->n, k % M->n);
    return P;
}