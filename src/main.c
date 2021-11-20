#include "lst_elm.h"
#include "lst.h"
#include "outils.h"

#include <stdlib.h> // librairie standard
#include <stdio.h>  // librairie input/output

void listehomoreelle();
void listehomoentiere();

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
    del_lst(&L, &rmInteger);
    // listehomoentiere();
    // listehomoreelle();
    return EXIT_SUCCESS;
}

// void listehomoreelle()
// {
//     struct lst_t *L = new_lst();
//     double *v;
//     do
//     {
//         double u;
//         printf("Entrez un réel (0 pour s'arrêter): ");
//         scanf("%lf", &u);
//         if (u == 0)
//             break;
//         v = (double *)calloc(1, sizeof(double));
//         *v = u;
//         insert_ordered(L, v, &reelcmp);
//     } while (true);
//     view_lst(L, &printDouble);
//     del_lst(&L, &rmDouble);
// }

// void listehomoentiere()
// {
//     struct lst_t *L = new_lst();
//     int *v;
//     do
//     {
//         int u;
//         printf("Entrez un entier (0 pour s'arrêter): ");
//         scanf("%d", &u);
//         if (u == 0)
//             break;
//         v = (int *)calloc(1, sizeof(int));
//         *v = u;
//         insert_ordered(L, v, &intcmp);
//     } while (true);
//     view_lst(L, &printInteger);
//     del_lst(&L, &rmInteger);
// }