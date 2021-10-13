#ifndef _LST_
#define _LST_

#include "lst_elm.h"
#include <stdbool.h> // librairie du type booléen

/** @brief Le type d'une liste :
	* + head - le premier élément de la liste
	* + tail - le dernier élément de la liste
	* + numelm - le nombre d'élément dans la liste
*/
struct lst_t
{
    struct lst_elm_t *head;
    struct lst_elm_t *tail;
    int numelm;
};

/*** DÉCLARATION DES FONCTIONS ASSOCIÉES ***/
/** @brief Vérifier si la liste L est vide ou pas */
bool emptyLst(const struct lst_t *L);
/** @brief Construire une liste vide */
struct lst_t *newLst();
/** @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t *L, int v);
/** @brief Visualiser les éléments de la liste L */
void print_lst(struct lst_t *L);
/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t ** ptrL);
#endif