#ifndef _OUTILS_
#define _OUTILS_

#include <stdbool.h>

/** Fonctions :
- D'affichage d'une valeur entière,
- De suppression d'une mémoire de type entier,
- De comparaison de 2 entiers.
 */
void printInteger ( int * i );
void rmInteger ( int * i );
bool intcmp ( int * i, int * j );

/** Fonctions :
- D'affichage d'une valeur réelle,
- De suppression d'une mémoire de type réel,
- De comparaison de 2 réels.
 */
void printDouble ( double * d );
void rmDouble ( double * d );
bool reelcmp ( double * u, double * v );

#endif // _OUTILS_
