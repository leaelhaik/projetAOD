/*! \file list.h
 *  \brief	   Manipulation of array
 *  \author    Matthieu Charly-Desroches
 *  \author    Samy Amraoui
 *  \version   1.0
 *  \date      31/10/2016 
 *  \copyright GNU Public License.
 */

#ifndef LIST_H
#define LIST_H

/**
 * Node type
 * \brief Structure of node
 * \param value Value of the node
 * \param freq Frequency of the node
 * \param next Next node
 */
typedef struct node
{
    long value;
    double freq;
    struct node *next;
} node;

typedef node* node_list;

/**
 * Length of a node list
 * \brief Function that will find the node of an array's maximum
 * \param l The nodes' list
 * \returns node
 */
long size_node_list (node_list list);

node_list add_node (node_list list, long value, double freq);

/**
 * Maximum of nodes' list
 * \brief Function that will find the node which have the maximum frequency
 * \param l The nodes' list
 * \returns node
 */
long max_node_list (node_list list);

/**
 * Left part of a nodes' list
 * \brief Function that will return the left part of a nodes' list
 * \param l The nodes' list
 * \param node The node where we cut the list into two pieces
 * \returns llist
 */
node_list left_part (node_list list, long node);

/**
 * Right part of a nodes' list
 * \brief Function that will return the right part of a nodes' list
 * \param l The nodes' list
 * \param node The node where we cut the list into two pieces
 * \returns rarray
 */
node_list right_part (node_list list, long node);

#endif
