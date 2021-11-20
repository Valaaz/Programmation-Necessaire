#include <stdio.h>
#include "db.h"

void write_list(struct list *L, enum mode_t mode, void (*ptrf)())
{
    FILE *fd;
    char fname[20];
    if (mode == TEXT)
    {
        printf("\t\tWrite list to text file (.txt)\n\tfile name : ");
        scanf("%s", fname);
        fd = fopen(fname, "wt");
    }
    else
    {
        printf("\t\tWrite list to binary file (.bin)\n\tfile name : ");
        scanf("%s", fname);
        fd = fopen(fname, "wb");
        assert(fd != NULL);
        /** TODO
        Vous devez parcourir la liste et écrire les formulaires qui y sont rangés grâce au pointeur de fonctions
        */
        fclose(fd);
    }
}

struct list *read_list(enum mode_t mode, void *(*ptr_data)(), void(ptr_del)())
{
    /**
    on peut ajouter en argument un pointeur sur la fonction de comparaison des formulaires gt_form si l'on souhaite faire une insertion
     ordonnée (insert_ordered) */
    FILE *fd;
    char fname[20];
    if (mode == TEXT)
    {
        printf("\t\tRead list from text file (. txt)\n\tfile name : ");
        scanf("%s", fname);
        fd = fopen(fname, "rt");
    }
    else
    {
        printf("\t \tRead list from binary file (.bin)\n\tfile name : ");
        scanf("%s", fname);
        fd = fopen(fname, "rb");
    }
    assert(fd != NULL);
    /** TODO
    Vous devez parcourir l'ensemble du fichier pour y collecter les formulaires et les ranger dans la liste.
    ATTENTION : il est possible que vous créiez un élément de trop (un formulaire vide) en fin de liste.
    Il faut alors penser à le supprimer grâce au code suivant :
    E = get_tail (L);
    struct elmlist T = getPred (E);
    set_suc (T, NULL);
    L->tail = T;
    del_elmlist (E, ptr_del);
    où ptr_del est le pointeur sur la fonction de suppression de la donnée (ici la donnée est un formulaire)
    */
    fclose(fd);
    return L;
}