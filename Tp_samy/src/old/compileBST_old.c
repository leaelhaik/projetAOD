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
#include <math.h>

#include "optBST.h"

static long BSTroot;
static long **BSTtree;

/**
 * Filling function
 * \brief function that will fill the array of frequency
 * \param file	A file descriptor in which we have to read the frequencies
 * \param array	The array we have to fill
 * \param size	The size of the array
 * \warning The size must be positive, the file opened and the array allocated
 * \returns {0 if succeds, -1 otherwise}
 */
int fill(FILE* file, double *array, long size)
{
	if (size <= 0) 
	{
		printf("Error the size is null or negative!\n");
		return -1;
	}
	else if (!array) 
	{
		printf("The array in parameter has not been initialized!\n");
		return -1;
	}
	else if (!file) 
	{
		printf("The file has not been properly opened!\n");
		return -1;
	}

	long* number_read = (long*) malloc(sizeof(long)*size);

	if (!number_read) 
	{
		printf("Error during the allocation of the array to stock the frequencies!\n");
		return -1;
	}

	for(int i = 0; i < size; ++i) 
	{
		fscanf(file, "%ld,", &number_read[i]);
	}

	long sum = 0;

	printf("DEBUG\n");
	for(int i = 0; i < size; ++i) 
	{
		printf("Number %d: %ld\n", i, number_read[i]);
		sum += number_read[i];
	}

	printf("DEBUG\n");
	for(int i = 0; i < size; ++i) 
	{
		array[i] = ((double) (number_read[i])) / sum;
		printf("Frequency %d: %lf\n", i, array[i]);
	}

	free(number_read);

	return 0;
}

/**
 * Print the BST
 * \brief function that print BSTtree and BSTroot
 * \param tree	BST to display
 * \param root root of the BST
 * \param size size of the BST
 */
void printBST(long size) 
{
	printf("\nBST display\n");
	printf("BSTroot : %ld\n", BSTroot);
	for (long i=0; i<size; ++i)
		printf("{%ld, %ld}\n", BSTtree[i][0], BSTtree[i][1]);
	printf("Merci c'était cool\n");
}

/**
 * Main function
 * \brief Main function
 * \param argc  A count of the number of command-line arguments
 * \param argv  An argument vector of the command-line arguments.
 * \warning Must be called with a positive long integer, n,  and a filename, freqFile, as commandline parameters and in the given order.
 * \returns { 0 if succeeds and prints C code implementing an optimal ABR on stdout; exit code otherwise}
 */
int main(int argc, char *argv[]) 
{
	long n = 0 ; // Number of elements in the dictionary
	FILE *freqFile = NULL ; // File that contains n positive integers defining the relative frequence of dictinary elements 

	if(argc != 3) 
	{
		fprintf(stderr, "!!!!! Usage: ./compileBST n  originalFile !!!!!\n");
		exit(EXIT_FAILURE); /* indicate failure.*/
	}

	// Conversion of parameter n in a long 
	int codeRetour = EXIT_SUCCESS;
	char *posError;
	long resuLong;
	n = atol(argv[1]);

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
	if (codeRetour != EXIT_SUCCESS) 
		return codeRetour;

	freqFile = fopen(argv[2] , "r" );
	if (freqFile==NULL) 
	{
		fprintf (stderr, "!!!!! Error opening originalFile !!!!!\n"); 
		exit(EXIT_FAILURE);
	}

	double* frequencies = (double*) malloc(sizeof(double)*n);
	if (fill(freqFile, frequencies, n) == -1) 
	{
		printf("Error during the file reading process\n");
		return -1;
	}

	BSTtree = malloc(sizeof(long)*n);

    double **freqmatrix, **costmatrix;
    long **root;
    alloc_matrix((void***) &root, n+1, n+1, sizeof(long));
    alloc_matrix((void***) &freqmatrix, n+1, n+1, sizeof(double));
    alloc_matrix((void***) &costmatrix, n+2, n+2, sizeof(double));

    for(size_t i=0; i<n+1; ++i)
    {
        BSTtree[i] = malloc(sizeof(long)*2);
        BSTtree[i][0] = -1;
        BSTtree[i][1] = -1;
        for(size_t j=0; j<n+1; ++j)
            root[i][j] = -1;
    }


    init_freqmatrix(freqmatrix, frequencies, n);

    double cost = optBSTcost(root, costmatrix, freqmatrix, n);

    BSTroot = root[1][n];
    for(int i=0; i<n+1; ++i)
    {
        for(int j=0; j<n+1; ++j)
        {
            printf("%ld ", root[i][j]);
        }
        printf("\n");
    }
    BSTcreate(BSTtree, root, 1, n);

    printf("Le cout de l'arbre est %lf\n", cost);
    printBST(n);

	for(int i = 0; i < n; ++i) 
	{
		printf("Frequency %d: %lf\n", i, frequencies[i]);
	}
    
    free(frequencies);
    free(BSTtree);
    fclose(freqFile);

    return 0;
}
