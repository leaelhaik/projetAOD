/*! \file compileBST.c
 *  \brief	   This implements the applyPatch program.
 *  \author    Lucie Pansart
 *  \author    Jean-Louis Roch
 *  \version   1.0
 *  \date      30/9/2016
 *  \warning   Usage: compileBST n originalFile
 *  \copyright GNU Public License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#include "BST.h"

static double BSTroot;
static double **BSTtree;


int read(FILE *freqFile, double *tab, int n) {
  if (n <= 0) {
    printf("Erreur: taille invalide.");
    return EXIT_FAILURE;
  }
  else if (!tab) {
    printf("Erreur: Tableau invalide");
    return EXIT_FAILURE;
  }
  else if (!freqFile) {
    printf("Erreur: Fichier invalide");
    return EXIT_FAILURE;
  }
  long* num_lu = (long*) malloc(sizeof(long)*n);
  for (int count=0; count < n; ++count) {
    fscanf(freqFile, "%ld", &num_lu[count]);
    //printf("%ld - ",num_lu[count]);
  }
  //printf("\n");

  long sum=0;
  for (int i=0; i<n; i++) {
    sum+=num_lu[i];
  }
  //printf("sum = %ld \n", sum);
  for (int i=0; i<n; i++) {
    tab[i]=(double)num_lu[i]/sum;
    //printf("%lf - ",tab[i]);
  }
  //printf("\n");

  free(num_lu);
  return EXIT_SUCCESS;
}


void afficheBST(int n)
{
	for(int i = 0; i < n; ++i) {
		printf("{%lf,%lf}\n", BSTtree[i][0], BSTtree[i][0]);
  }
}


/**
 * Main function
 * \brief Main function
 * \param argc  A count of the number of command-line arguments
 * \param argv  An argument vector of the command-line arguments.
 * \warning Must be called with a positive long integer, n,  and a filename, freqFile, as commandline parameters and in the given order.
 * \returns { 0 if succeeds and prints C code implementing an optimal ABR on stdout; exit code otherwise}
 */
int main (int argc, char *argv[]) {
  long n = 0 ; // Number of elements in the dictionary
  FILE *freqFile = NULL ; // File that contains n positive integers defining the relative frequence of dictinary elements





  if(argc != 3){
    fprintf(stderr, "!!!!! Usage: ./compileBST n  originalFile !!!!!\n");
      exit(EXIT_FAILURE); /* indicate failure.*/
  }

  { // Conversion of parameter n in a long
    int codeRetour = EXIT_SUCCESS;
    char *posError;
    long resuLong;
    n = atol(argv[1] ) ;

    assert(argc >= 2);
    // Conversion of argv[1] en long
    resuLong = strtol(argv[1], &posError, 10);
    // Traitement des erreurs
    switch (errno)
    {
      case EXIT_SUCCESS :
         // Conversion du long en int
         if (resuLong > 0)
         {
            n = (long)resuLong;
            fprintf(stderr, "Number of elements in the dictionary: %ld\n", n);
         }
         else
         {
            (void)fprintf(stderr, "%s cannot be converted into a positive integer matching the number of elements in the dicionary.\n", argv[1]) ;
            codeRetour = EXIT_FAILURE;
         }
      break;

      case EINVAL :
         perror(__func__);
         (void)fprintf(stderr, "%s does not match a long integer value. \n", argv[1]);
         codeRetour = EXIT_FAILURE;
      break;

      case ERANGE :
         perror(__func__);
         (void)fprintf(stderr, "%s does not fit in a long int :\n" "out of bound [%ld;%ld]\n",
                       argv[1], LONG_MIN, LONG_MAX);
         codeRetour = EXIT_FAILURE;
      break;
      default :
         perror(__func__);
         codeRetour = EXIT_FAILURE;
    } // switch (errno)
    if  (codeRetour != EXIT_SUCCESS) return codeRetour ;
  }

  freqFile = fopen(argv[2] , "r" );
  if (freqFile==NULL) {fprintf (stderr, "!!!!! Error opening originalFile !!!!!\n"); exit(EXIT_FAILURE);}

  // Tableau pour stocker les probabilités des valeurs lues
  double* tab = (double*) malloc(sizeof(double)*n);
  read(freqFile, tab, n);

  double** tab_cout;
  double** tab2f;
  double** racine;
  long i=0;
  long j=n-1;
  creation_tabs((double***)&tab_cout,(double***)&racine,(double***)&tab2f,n);
  memorisation(tab,tab_cout,racine,tab2f,n);
  BST_rec(tab2f,tab_cout,racine,i,j);
  //BST_Disp(BSTtree,racine,i,j);
  //afficheBST(n);

  printf("\ntab_cout :\n\n");
  affiche_tab(tab_cout,n+1,n+1);
  printf("\ntab2f :\n\n");
  affiche_tab(tab2f,n,n);
  printf("\ntableau_racine:\n\n");
  affiche_tab(racine,n,n);
  destruction_tabs((double***)&tab_cout,(double***)&racine,(double***)&tab2f,n);
  fclose(freqFile);
  free(tab);

  return 0;
}
