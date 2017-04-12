/*! \file optBST.h
 *  \brief	   Manipulation of array
 *  \author    Matthieu Charly-Desroches
 *  \author    Samy Amraoui
 *  \version   1.0
 *  \date      31/10/2016 
 *  \copyright GNU Public License.
 */

#ifndef OPTBST_H
#define OPTBST_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
/**
 * Matrix allocation
 * \brief Allocation of a matrix with given size parameters
 * \param mat The matrix
 * \param col Number of columns
 * \param lig Number of ligns
 * \param size Size of a matrix's element (eg : sizeof(long))
 */
void alloc_matrix(void ***mat, const long col, const long lig, const long size);

/**
 * Matrix desallocation
 * \brief Desallocation of a matrix
 * \param mat The matrix
 * \param col Number of columns
 */
void dealloc_matrix(void ***mat, const long col);

/**
 * Initialisation of the frequencies' matrix
 * \brief 
 * \param freqmat Frequencies' matrix
 * \param freqtab List of nodes' frequencies
 * \param size Size of freqtab (number of nodes)
 */
void init_freqmatrix(double **freqmat, double *freqtab, long size);

/**
 * Improved doubles sum function (allow infinity)
 * \brief A sum function able to sum infinite doubles
 * \param a First double to sum
 * \param b Second double to sum
 */
double sum_infty(double a, double b);

/**
 * Optimal sub-BST cost 
 * \brief Compute the optimal cost of BST for i to j nodes
 * \param root Roots' matrix
 * \param costmatrix Costs' matrix
 * \param freqmat Frequencies's matrix
 * \param i Start index
 * \param j End index
 */
void optCost(long **root, double **costmatrix, double **freqmat, long i, long j);

/**
 * Optimal BST cost
 * \brief Compute the optimal BST's cost
 * \param root Roots' matrix
 * \param costmatrix Costs' matrix
 * \param freqmat Frequencies' matrix
 * \param size Size of freqmat (number of nodes)
 */
double optBSTcost(long **root, double **costmatrix, double **freqmat, long size);

/**
 * Optimal BST creation
 * \brief Create the optimal BST thanks to the roots' matrix
 * \param BSTtree The matrix which represents the optimal BST
 * \param Roots' matrix
 * \param start Start index
 * \param end End index
 */
void BSTcreate(long **BSTtree, long **root, long start, long end);

#endif
