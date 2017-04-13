#include "BST.h"


void creation_tabs(double*** tab_cout, double*** racine, double*** tab2f, long n) {
	*tab_cout = malloc(sizeof(double)*(n+1));
	*racine =  malloc(sizeof(double)*(n));
	*tab2f =  malloc(sizeof(double)*(n));
	for (int k = 0; k < n; ++k) {
		(*tab2f)[k] = malloc(sizeof(double)*(n));
		(*tab_cout)[k] = malloc(sizeof(double)*(n+1));
		(*racine)[k] = malloc(sizeof(double)*(n));
	}
	//tab_cout est de taille n+1 * n+1
	(*tab_cout)[n]= malloc(sizeof(double)*(n+1));
}

void destruction_tabs(double*** tab_cout, double*** racine, double*** tab2f, long n) {
	//on libere les cases
	for (int k = 0; k < n; ++k) {
		free((*tab2f)[k]);
		free((*racine)[k]);
		free((*tab_cout)[k]);
	}
	//tab_cout est de taille n+1 * n+1
	free((*tab_cout)[n]);
	//on libere les tab
	free(*tab2f);
	free(*tab_cout);
	free(*racine);
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
		tab_cout[m][m] = proba[m];
		tab2f[m][m]= proba[m];
	}
	//Initialisation de la table des frequences de recherche
	long z;
	for (int x = 1; x < n ; ++x){
		for (int y = 1; y < n; ++y) {
			z = x+y;
			tab2f[x][z] = tab2f[x][z-1] + proba[z];
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

void BST_Disp(double **BSTtree, double **racine, long i, long j) {
	if (i<j) {
		long r=racine[i][j];
		if (r==0) {
			BSTtree[r][0]=-1;
		} else {
			BSTtree[r][0] = racine[i][r-1];
      if (r == j) {
            BSTtree[r][1] = -1;
			} else {
            BSTtree[r][1] = racine[r+1][j];
			}
			BST_Disp(BSTtree, racine, i, r-1);
      BST_Disp(BSTtree, racine, r+1, j);
    }
	}
}
