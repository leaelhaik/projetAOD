/*! \file BST.h
*  \brief	   This implements the package reference for BST.
*  \author    Lea El Haik
*  \author    Pierre Brossy
*  \version   1.0
*  \date      5/04/2017
*  \warning   Usage: compileBST n originalFile
*  \copyright GNU Public License.
*/


#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>



 /**
 * creation_tabs
 * \brief creation and memory allocation of differents tabs that will be used
 * \param tab_cout double*** in-out param, tab of costs
 * \param racine long*** in-out param,tab of roots
 * \param tab2f double*** in-out param, tab of frequencies
 * \param BST long*** in-out param, BST that have to be created
 * \param n number of value for the BST
 */
void creation_tabs(double*** tab_cout, long*** racine, double*** tab2f, long*** BSTtree, long n);


/**
* destruction_tabs
* \brief destruction and memory deallocation of differents tabs that will be used
* \param tab_cout double*** in-out param, tab of costs
* \param racine long*** in-out param,tab of roots
* \param tab2f double*** in-out param, tab of frequencies
* \param BST long*** in-out param, BST that have to be created
* \param n number of value for the BST
*/
void destruction_tabs(double*** tab_cout, long*** racine, double*** tab2f, long*** BSTtree, long n);

/**
* creation_tabs
* \brief method of memorisation
* \param proba double* tab
* \param tab_cout double** tab of costs
* \param racine long** tab of roots
* \param tab2f double** tab of frequencies
* \param n number of value for the BST
*/
void memorisation( double* proba, double** tab_cout, long** racine, double** tab2f, long n);

/**
*BST_rec
* \brief recursiv method for searching roots and costs
* \param tab2f double** tab of frequencies
* \param tab_cout double** tab of costs
* \param racine long** tab of roots
* \param i long start index
* \param j long end index
* \returns value of tab_cout[i][j]
*/
double BST_rec(double** tab2f, double** tab_cout,long** racine, long i, long j);


/**
*BST_fin
* \brief recursiv method for creating the BSTtree
* \param BSTtree long** BST
* \param racine long** tab of roots
* \param i long start index
* \param j long end index
*/
void BST_fin(long **BSTtree, long **racine, long i, long j);

#endif
