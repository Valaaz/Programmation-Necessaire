#include "lst_elm.h"
#include "lst.h"

#include <stdlib.h> // librairie standard
#include <stdio.h>  // librairie input/output

int main()
{
    int v;
    struct lst_t *L = newLst();
    printf("Veuillez rentrer une valeur :\n");
    scanf("%d", &v);
    while (v > 0)
    {
        insert_ordered(L, v);
        scanf("%d", &v);
    }
    print_lst(L);
    del_lst(&L);
    return EXIT_SUCCESS;
}