#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>

/* Fichier contenant les fonctions de manipulations
 * et de creation d'un ABR optimal
 *
 */


/** Fonction qui initie la mtrice de somme des fréquences des clés de l'arbre
* \brief Initialisation de la matrice.
* \param tab2f La matrice à initialiser
* \param tab_lu Le tableau des fréquences lues depuis le fichier passé en entré.
* \param n La taille du tableau tab_lu
*/
void init_tabf(double **tab2f, double *tab_lu, long n);

#endif
