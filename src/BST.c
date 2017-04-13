#include "BST.h"


void memorisation( double* proba, double** tab_cout, double** racine, double** tab2f, long i, long j, long n) {
	tab_cout = malloc(sizeof(double)*(n+1));
	racine = malloc(sizeof(double)*(n));
	for (int k = 0; k < n; ++k) {
		(*tab_cout)[k] = malloc(sizeof(double)*n+1);
		(*racine)[k] = malloc(sizeof(double)*n);
		for (int l = 0; l < n; ++l)
		{
			tab_cout[k][l] = DBL_MAX;
		}
	}
	for (int m = 1; m <=n; ++m) {
		e[m,m-1] = 0;
		e[m,m] = proba[i];
	}
}



 BST_Disp(double **racine, double **etiquette, int i, int j) {
	if(i<j) {
		return NULL;
	} else if (i=j){
			printf("feuille %lf \n",etiquette[i]);
			return (etiquette[i], NULL, NULL);

	} else {
				printf("racine= %ld",k[racine[i][j]]);
				printf("arbre gauche= %ld",BST_Disp(racine,k,i,racine[i][j]-1));
				printf("arbre droit= %ld",BST_Disp(racine,k,racine[i][j]+1,j));
	}
}
