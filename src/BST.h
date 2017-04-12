#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>

/* Fichier contenant les fonctions de manipulations
 * et de creation d'un ABR optimal
 *
 */

int **tab_create(const int colonne, const int ligne, int size);

void destruct_tab(int*** tab, int col);


#endif
