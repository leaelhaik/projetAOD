/*! \file array.h
 *  \brief	   Manipulation of array
 *  \author    Matthieu Charly-Desroches
 *  \author    Samy Amraoui
 *  \version   1.0
 *  \date      31/10/2016 
 *  \copyright GNU Public License.
 */

#ifndef ARRAY_H
#define ARRAY_H

/**
 * Maximum of an array
 * \brief Function that will find the position of an array's maximum
 * \param array	The array
 * \returns position
 */
long max_array (double *array);

/**
 * Left part of an array
 * \brief Function that will return the left part of an array
 * \param array	The array
 * \param position The position where we cut the array into two pieces
 * \returns larray
 */
double* left_array(double *array, long position);

/**
 * Right part of an array
 * \brief Function that will return the right part of an array
 * \param array	The array
 * \param position The position where we cut the array into two pieces
 * \returns rarray
 */
double* right_array(double *array, long position);

#endif
