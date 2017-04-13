#include "BST.h"


void creation_tabs(double*** tab_cout, double*** racine, double*** tab2f, long n) {
	long j = 0;
	tab_cout = malloc(sizeof(double)*(n+1));
	racine =  malloc(sizeof(double)*(n));
	tab2f =  malloc(sizeof(double)*n);
	for (int k = 0; k < n; ++k) {
		(*tab2f)[k] = malloc(sizeof(double)*n);
		(*tab_cout)[k] = malloc(sizeof(double)*(n+1));
		(*racine)[k] = malloc(sizeof(double)*n);
	}
}

void memorisation( double* proba, double** tab_cout, double** racine, double** tab2f, long n) {
	tab_cout[n][n-1] = 0;
	//Initialisation matrice des couts à l'infini
 	for  (int i = 0; i<n+1; ++i) {
		for (int j=0; j<n+1; ++j) {
			tab_cout[i][j]=DBL_MAX;
		}
	}
	//Initialisation de la matrice triangulaire et mise en place des couts sur la diagonale
	for (int m = 1; m <=n; ++m) {
		tab_cout[m][m-1] = 0;
		tab_cout[m][m] = proba[i];
		tab2f[m][m]= proba[i];
	}
	//Initialisation de la table des frequences de recherche
	for (int x = 1; x < n ; ++x){
		for (int y = 1; y < n; ++y) {
			j = x+y;
			tab2f[i][j] = tab[x][j-1] + proba[j];
		}
	}
}

double BST_rec(double** tab2f, double** tab_cout, double** racine, long i, long j) {
	if (tab_cout[i][j]!=DBL_MAX) {
		return tab_cout[i][j];
	} else {
		double t;
		for (long r=i; r<=j; ++r) {
			t=BST_rec(tab2f, tab_cout, racine, i, r-1) + BST_rec(tab2f, tab_cout, racine, r+1, j) + tab2f[i][j] ;
			if (t<tab_cout [i][j]) {
				tab_cout[i][j]=t;
				racine[i][j]=r;
			}
		}
		return tab_cout[i][j];
	}
}



 void BST_Disp(double **racine, double **etiquette, int i, int j) {
	if(i<j) {
		return NULL;
	} else if (i=j){
			printf("feuille %lf \n",etiquette[i]);
	} else {
				printf("racine= %ld",k[racine[i][j]]);
				printf("arbre gauche= %ld",BST_Disp(racine,k,i,racine[i][j]-1));
				printf("arbre droit= %ld",BST_Disp(racine,k,racine[i][j]+1,j));
	}
}
