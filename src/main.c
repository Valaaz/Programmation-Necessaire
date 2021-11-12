#include "lst_elm.h"
#include "lst.h"
#include "outils.h"

#include <stdlib.h> // librairie standard
#include <stdio.h>  // librairie input/output

// #define DEBUG
// #undef DEBUG

int main()
{
    int v;
    struct lst_t *L = new_lst();
    printf("Veuillez rentrer une valeur :\n");
    scanf("%d", &v);
    while (v > 0)
    {
        int *ptrv = calloc(1, sizeof(int));
        *ptrv = v;
        insert_ordered(L, ptrv, &intcmp);
        scanf("%d", &v);
    }
    view_lst(L, &printInteger);
    del_lst(&L, NULL);
    return EXIT_SUCCESS;
}