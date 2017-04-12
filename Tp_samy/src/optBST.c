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

void alloc_matrix(void ***mat, const long col, const long lig, const long size)
{
	*mat = malloc(size*col);

	for(long j=0; j<col; ++j)
		(*mat)[j] = malloc(size*lig);
}

void dealloc_matrix(void ***mat, const long col)
{
	for(long j=0; j<col; ++j)
		free((*mat)[j]);
	free(*mat);
}

void init_freqmatrix(double **freqmat, double *freqtab, long size)
{
    for(long i=0; i<size; ++i)
    {
        for(long j=i; j<size; ++j)
        {
            if (j == 0)
                freqmat[i][j] = freqtab[0];
            else
                freqmat[i][j] = freqmat[i][j-1] + freqtab[j];
        }
    }
}

double sum_infty(double a, double b)
{
    if (a == DBL_MAX || b == DBL_MAX)
        return DBL_MAX;
    else
        return a + b;
}

void optCost(long **root, double **costmatrix, double **freqmat, long i, long j)
{
    costmatrix[i][j] = DBL_MAX;

    for(long r=i; r<=j; ++r)
    {
        double rec_costmatrix = 0;
        if (r == 0)
            rec_costmatrix = costmatrix[r+1][j];
        else
            rec_costmatrix = sum_infty(costmatrix[i][r-1], costmatrix[r+1][j]);
        if (costmatrix[i][j] > rec_costmatrix)
        {
            costmatrix[i][j] = rec_costmatrix;
            root[i][j] = r;
        }
    }

    costmatrix[i][j] += freqmat[i][j]; 
}

double optBSTcost(long **root, double **costmatrix, double **freqmat, long size)
{
    for(long j=0; j<size; ++j)
    {
        for(long i=0; i<size-j; ++i) {
            optCost(root, costmatrix, freqmat, i, i+j);
        }
    }

    return costmatrix[0][size-1];
}

void BSTcreate(long **BSTtree, long **root, long start, long end)
{
    if (start < end)
    {
        long r = root[start][end];

		if (r == 0)
			BSTtree[r][0] = -1;
		else
			BSTtree[r][0] = root[start][r-1];

        if (r == end)
            BSTtree[r][1] = -1;
        else
            BSTtree[r][1] = root[r+1][end];

		if (r != 0)
			BSTcreate(BSTtree, root, start, r-1);
        BSTcreate(BSTtree, root, r+1, end);
    }
}
