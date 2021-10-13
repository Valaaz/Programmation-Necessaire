/**
	* @note
	*  Compiler avec
	*    gcc -Wall -std=c11 -o intlist intlist.c
	*
	* @brief
	*  Conception d'un type pour les listes d'entiers
	*  et des focntions associées
	*
	* @TODO
	*  Ajoutez les fonctions de consultation des éléments de liste :
	*  + getX
	*  + getSuc
	*  + setX
	*  + setSuc
	*
	* @TODO
	*  Puis, séparez les éléments afin qu'apparaissent :
	*  + Un fichier d'entêtes (.h) de la bibliothèque liste d'entiers,
	*  + Un fichier de définitions (.c) correspondant aux déclarations du fichier d'entête
	*  + Un fichier main.c ne contenant que la fonction principale.
	*
	* @TODO
	*	Construisez le Makefile correspondant
*/
#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions

/***
 * LES TYPES ABSTRAITS
 ***/
/** @brief Le type d'un élément de liste:
 * + x - un entier,
 * + suc - un pointeur sur son successeur (ou NULL s'il n'y en a pas)
 */
struct lst_elm_t {
  int x;
  struct lst_elm_t * suc;
};
/***
 * DÉCLARATION DES FONCTIONS PUBLIQUES
 ***/
/** @brief Création d'un nouvel élément de liste d'entiers */
struct lst_elm_t * new_lst_elm(int value);
/** @brief Suppression d'un élément de liste d'entiers */
void del_lst_elm_t(struct lst_elm_t ** ptrE);
/** @ brief Accéder au champ x de l'élément de liste d'entiers */
int getX ( struct lst_elm_t * E );
/** @ brief Accéder au champ suc de l'élément de liste d'entiers */
struct lst_elm_t * getSuc ( struct lst_elm_t * E );
/** @brief Modifier la valeur du champ x de l'élément de liste d'entiers */
void setX (struct lst_elm_t * E, int v );
/** @brief Modifier la valeur du champ suc de l'élément de liste d'entiers */
void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S );

/** @brief Le type d'une liste :
	* + head - le premier élément de la liste
	* + tail - le dernier élément de la liste
	* + numelm - le nombre d'élément dans la liste
*/
struct lst_t {
	struct lst_elm_t * head;
	struct lst_elm_t * tail;
	int numelm;
};
/***
 * DÉCLARATION DES FONCTIONS PUBLIQUES
 ***/
/** @brief Construire une liste vide */
struct lst_t * new_lst();
/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t ** ptrL );
/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t * L);
/** @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t * L, int v);
/** @brief Visualiser les éléments de la liste L */
void print_lst(struct lst_t * L );

/***
	* ALGORITHME (FONCTION PRINCIPALE)
	***/
int main() {
	int v;
	struct lst_t * L = new_lst();
	scanf( "%d", &v );
	while( v > 0 ) {
		cons(L,v);
		scanf("%d",&v);
	}
	print_lst(L);
	del_lst(L);
	return EXIT_SUCCESS;
}

/***
  * DÉFINITIONS DES FONCTIONS
  ***/
/** @todo Définissez les fonctions publiques :
 * + new_lst_elm
 * + del_lst_elm
 * + getX
 * + getSuc
 * + setX
 * + setSuc
 * des éléments de liste d'entiers.
 **/
struct lst_t * new_lst() {
	/**
	 * @note : calloc fonctionne de manière identique à malloc
	 * et de surcroît met à NULL(0) tous les octets alloués
	 **/
	struct lst_t * L = (struct lst_t *)calloc(1,sizeof(struct lst_t));
	assert(L);
	return L;
}
void del_lst(struct lst_t ** ptrL ) {
	/** @todo */
}
bool empty_lst(const struct lst_t * L ) {
	assert(L);// L doit exister !
	return L->numelm == 0;
}
void cons(struct lst_t * L, int v) {
	/** @todo */
}
void print_lst(struct lst_t * L ) {
	printf( "[ " );
	for( struct lst_elm_t * E = L->head; E; E = E->suc) {
		printf( "%d ", E->x );
	}
	printf( "]\n\n" );
}
