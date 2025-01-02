#ifndef HUFFMANCODING_H
# define HUFFMANCODING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../inc/tools.h"

//Struct to save each node characters,
//his frefrequency and pointers to next
//t_node on the binary tree
typedef struct s_node
{
	char			c;
	size_t			freq;
	struct s_node	*left;
	struct s_node	*right;
} t_node;

//Struct to save and work with an array
//of t_node structs
typedef struct s_allNodes
{
	size_t		size;
	size_t		capacity;
	t_node		**nodes;
} t_allNodes;

#endif
