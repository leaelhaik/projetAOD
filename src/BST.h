#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>

/* Fichier contenant les fonctions de manipulations
 * et de creation d'un ABR optimal
 *
 */


void creation_tabs(double*** tab_cout, double*** racine, double*** tab2f, long n);

void destruction_tabs(double*** tab_cout, double*** racine, double*** tab2f, long n);

void memorisation( double* proba, double** tab_cout, double** racine, double** tab2f, long n);

double BST_rec(double** tab2f, double** tab_cout, double** racine, long i, long j);

void BST_Disp(double **BSTtree, double **racine, long i, long j);

#endif
