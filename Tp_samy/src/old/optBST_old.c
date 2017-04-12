/*! \file optBST.c
 *  \brief	   Manipulation of array
 *  \author    Matthieu Charly-Desroches
 *  \author    Samy Amraoui
 *  \version   1.0
 *  \date      31/10/2016 
 *  \copyright GNU Public License.
 */

#include <unistd.h>
#include "optBST.h"

/**
 * Matrix allocation
 * \brief 
 * \param 
 */
void alloc_matrix(void ***mat, const long col, const long lig, const long size)
{
	*mat = malloc(size*col);

	for(long j=0; j<col; ++j)
		(*mat)[j] = malloc(size*lig);
}

/**
 * Matrix desallocation
 * \brief 
 * \param 
 */
void dealloc_matrix(void ***mat, const long col)
{
	for(long j=0; j<col; ++j)
		free((*mat)[j]);
	free(*mat);
}

/**
 * Initialisation of the frequencies' matrix
 * \brief 
 * \param 
 */
void init_freqmatrix(double **freqmat, double *freqtab, long size)
{
	for(long i=1; i<=size; ++i)
	{
		freqmat[i][i-1] = 0;

		for(long j=i; j<=size; ++j) // j = size inclus ?
			freqmat[i][j] = freqmat[i][j-1] + freqtab[j];
	}
}

/**
 * New sum fonction
 * \brief
 * \param
 */
double sum_infty(double a, double b)
{
    if (a == DBL_MAX || b == DBL_MAX)
        return DBL_MAX;
    else
        return a + b;
}

/**
 * Optimal sub-BST cost 
 * \brief Compute the optimal cost of BST for i to j nodes
 * \param 
 */
void optCost(long **root, double **costmatrix, double **freqmat, long i, long j)
{
	costmatrix[i][j] = DBL_MAX;

	for(long r=i; r<=j; ++r)
	{
        //printf("Regarde ici A: %lf\nB : %lf\ni: %ld\nj: %ld\nr: %ld\n", costmatrix[i][r-1], costmatrix[r+1][j], i, j, r);
        printf("\n \n ");
        double rec_costmatrix = sum_infty(costmatrix[i][r-1], costmatrix[r+1][j]);
        if (costmatrix[i][j] > rec_costmatrix)
		{
			costmatrix[i][j] = rec_costmatrix;
			printf("BITEMAGIQUE r=%ld\n", r);
            root[i][j] = r;
			printf("BITEMAGIQUEEEEEE2 root[%ld][%ld]=%ld\n", i, j, root[i][j]);
		}
        else
        {
            printf("LA PUTE !!!\n");
            printf("rec_costmatrix = %lf\n ", rec_costmatrix);
        }
	}

	costmatrix[i][j] += freqmat[i][j]; 
}

/**
 * Optimal BST cost
 * \brief Compute the optimal BST's cost
 * \param 
 * \retur
 */
double optBSTcost(long **root, double **costmatrix, double **freqmat, long size)
{
	for(long i=1; i<=size+1; ++i)
        costmatrix[i][i-1] = 0;

    for(long j=0; j<size; ++j)
    {
        for(long i=1; i<=size-j; ++i) {
            optCost(root, costmatrix, freqmat, i, i+j);
        }
    }

    return costmatrix[1][size];
}

/**
 * Optimal BST creation
 * \brief Create the optimal BST thanks to the roots' matrix
 *
 */
void BSTcreate(long **BSTtree, long **root, long debut, long fin)
{
    if (debut < fin)
    {
        long r = root[debut][fin];
        //printf("RRRRRRRR: %ld\n", r);
        
        BSTtree[r][0] = root[debut][r-1];
        BSTtree[r][1] = root[r+1][fin];

        BSTcreate(BSTtree, root, debut, r-1);
        BSTcreate(BSTtree, root, r+1, fin);
    }
}
