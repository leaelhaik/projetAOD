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

int partitionner(int *tableau, int p, int r) {
    int pivot = tableau[p], i = p-1, j = r+1;
    int temp;
    while (1) {
        do
            j--;
        while (tableau[j] > pivot);
        do
            i++;
        while (tableau[i] < pivot);
        if (i < j) {
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
        else
            return j;
    }
}

void quickSort(int *tableau, int p, int r) {
    int q;
    if (p < r) {
        q = partitionner(tableau, p, r);
        quickSort(tableau, p, q);
        quickSort(tableau, q+1, r);
    }
}
