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


void Opt(double **tabFreq, int n, double **tabCout, double **tabRac) {
	int j;
	for (int i=0; i<n; i++) {
		tabFreq[i][i]=0;
		tabCout[i][i]=0;
	}
	for (int l=1; l<n; l++) {
		for (int i=0; i<n; i++) {
			j=i+l;
			tabFreq[i][j]=tabFreq[i][j-1];
			//Ici determiner m
			int m=0;
			tabCout[i][j]=tabFreq[i][j]+tabCout[i][m-1]+tabCout[m][j];
			tabRac[i][j]=m;

		}
	}

}



void creation_tabs(double*** tab_cout, double*** racine, double*** tab2f, long n) {
	long j = 0;
	tab_cout = malloc(sizeof(double)*(n+1));
	racine =  malloc(sizeof(double)*(n));
	tab2f =  malloc(sizeof(double)*n);
	for (int k = 0; k < n; ++k) {
		(*tab2f)[k] = malloc(sizeof(double)*n);
		(*tab_cout)[k] = malloc(sizeof(double)*n+1);
		(*racine)[k] = malloc(sizeof(double)*n);
	}
}

void memorisation( double* proba, double** tab_cout, double** racine, double** tab2f, long n) {
	tab_cout[n][n-1] = 0;
	for (int m = 1; m <=n; ++m) {
		tab_cout[m][m-1] = 0;
		tab_cout[m][m] = proba[i];
		tab2f[m][m]= proba[i];
	}
	for (int x = 1; x < n ; ++x){
		for (int y = 1; y < n; ++y) {
			j = x+y;
			tab2f[i][j] = tab[x][j-1] + proba[j];	
		}
	}
 	for  (int i = 0; 
}
