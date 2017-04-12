#include "BST.h"


int **tab_create(const int colonne, const int ligne, int size) 
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

