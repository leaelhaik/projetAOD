/*! \file array.c
 *  \brief	   Manipulation of array
 *  \author    Matthieu Charly-Desroches
 *  \author    Samy Amraoui
 *  \version   1.0
 *  \date      31/10/2016 
 *  \copyright GNU Public License.
 */


/**
 * Maximum of an array
 * \brief Function that will find the position of an array's maximum
 * \param array	The array
 * \returns position
 */
long max_array (double *array) 
{
    long position = 0;
    long size = sizeof(array)/sizeof(double);
    if (size > 1) 
	{
        for (long i = 1; i < size ; ++i) 
		{
            if (array[i] > array[position]) 
                position = i;
        }
    }
    return position;
}

/**
 * Left part of an array
 * \brief Function that will return the left part of an array
 * \param array	The array
 * \param position The position where we cut the array into two pieces
 * \returns larray
 */
double* left_array(double *array, long position) 
{
    long size = position;
    double larray[size];
    for (long i = 0; i < size ; ++i)
        larray[i] = array[i];
    return larray;
}

/**
 * Right part of an array
 * \brief Function that will return the right part of an array
 * \param array	The array
 * \param position The position where we cut the array into two pieces
 * \returns rarray
 */
double* right_array(double *array, long position) 
{
    long size = sizeof(array)/sizeof(double) - (position + 1);
    double rarray[size];
    for (long i = 0; i < size ; ++i)
        rarray[i] = array[position + i + 1];
    return rarray;
}
