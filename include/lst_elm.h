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
	void *datum;
	struct lst_elm *suc;
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
struct lst_elm_t *new_lst_elm(void *datum);
/** @brief Suppression d'un élément de liste d'entiers */
void del_lst_elm_t(struct lst_elm_t **ptrE);
void *getDatum(struct lst_elm_t *E);
struct lst_elm_t *getSuc(struct lst_elm_t *E);
void *setDatum(struct lst_elm_t *E, void *datum);
void setSuc(struct lst_elm_t *E, struct lst_elm_t *S);
#endif