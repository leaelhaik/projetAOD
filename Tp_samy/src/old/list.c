/*! \file list.c
 *  \brief	   Manipulation of array
 *  \author    Matthieu Charly-Desroches
 *  \author    Samy Amraoui
 *  \version   1.0
 *  \date      31/10/2016 
 *  \copyright GNU Public License.
 */

#include <stdlib.h>
#include "list.h"

/**
 * Length of a node list
 * \brief Function that will find the node of an array's maximum
 * \param l The nodes' list
 * \returns node
 */
long size_node_list (node_list list)
{
    node* tmp = list;
    long size = 0;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}

node_list add_node (node_list list, long value, double freq)
{
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->freq = freq;
    newNode->next = NULL;
    if (list == NULL)
        return newNode;
    else
    {
        node* tmp = list;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode;
        return list;
    }
}

/**
 * Maximum of nodes' list
 * \brief Function that will find the node which have the maximum frequency
 * \param l The nodes' list
 * \returns node
 */
long max_node_list (node_list list) 
{
    node_list tmp = list;
    long node = tmp->value;
    double freq = tmp->freq;
    while (tmp != NULL)	
    {
        if (tmp->freq > freq) 
        {
            node = tmp->value;
            freq = tmp->freq;
        }
    }
    return node;
}


/**
 * Left part of a nodes' list
 * \brief Function that will return the left part of a nodes' list
 * \param l The nodes' list
 * \param node The node where we cut the list into two pieces
 * \returns llist
 */
node_list left_part (node_list list, long node) 
{
    long size = node - list->value;
    node_list llist = NULL;
    node_list tmp = list;
    for (long i; i < size; ++i)
    {
        llist = add_node(llist, tmp->value, tmp->freq);
        tmp = tmp->next;
    }
    return llist;
}

/**
 * Right part of a nodes' list
 * \brief Function that will return the right part of a nodes' list
 * \param l The nodes' list
 * \param node The node where we cut the list into two pieces
 * \returns rlist
 */
node_list right_part (node_list list, long node)
{
    long size = size_node_list(list) - (list->value + 1);
    node_list rlist = NULL;
    node_list tmp = list;
    for (long i; i <= node; ++i)
        tmp = tmp->next;
    for (long i; i < size; ++i)
    {
        rlist = add_node(rlist, tmp->value, tmp->freq);
        tmp = tmp->next;
    }
    return rlist;
}
