#include "BST.h"


/* int **tab_create(const int colonne, const int ligne, int size)
{
	int** tab = malloc(size*colonne);
	for (long i = 0; i < colonne; ++i)
	{
		(*tab)[i] = malloc(size*ligne);
	}
	return tab;
}

void destruct_tab(int*** tab, int colonne)
{
	for (long i = 0; i < colonne; ++i)
	{
		free((*tab)[i]);
	}
	free(tab);
}

*/


void init_tabf(double **tab2f, double *tab_lu, long n)
{
	for (int i = 0; i < n ; ++i) {
		for (int j = i; j < n ; ++j) {
			if (j == 0) {
				tab2f[i][j] = tab_lu[j];
			} else {
				tab2f[i][j] = tab2f[i][j-1] +tab_lu[j];
			}
		}
	}
}


	}
