#ifndef _LSTELM_
#define _LSTELM_
/***
	* LES TYPES ABSTRAITS
	***/
/** @brief Le type d'un élément de liste:
 * + x - un entier,
 * + suc - un pointeur sur son successeur (ou NULL s'il n'y en a pas)
 */
struct lst_elm_t
{
    int x;
    struct lst_elm_t *suc;
};

/*** DÉCLARATION DES FONCTIONS ASSOCIÉES ***
	* Créez les fonctions de consultation :
	*  + getX
	*  + getSuc
	*  et les fonctions de modification :
	*  + setX
	*  + setSuc
	*  des éléments de liste
	*/
/** @brief Création d'un nouvel élément de liste d'entiers */
struct lst_elm_t * new_lst_elm(int value);
/** @brief Suppression d'un élément de liste d'entiers */
void del_lst_elm_t(struct lst_elm_t ** ptrE);
int getX(struct lst_elm_t *E);
struct lst_elm_t *getSuc(struct lst_elm_t *E);
void setX(struct lst_elm_t *E, int v);
void setSuc(struct lst_elm_t *E, struct lst_elm_t *S);
#endif